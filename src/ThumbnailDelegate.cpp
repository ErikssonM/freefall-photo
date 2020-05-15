#include "ThumbnailDelegate.h"

void ThumbnailDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const
{
  if (index.data().canConvert<ImageItem>()) {
    ImageItem image = qvariant_cast<ImageItem>(index.data());

    if (option.state & QStyle::State_Selected) {
      qDebug("Painting selection");
      painter->fillRect(option.rect, option.palette.highlight());
    }

    image.paintThumbnail(painter, option.rect, option.palette);
  } else {
    QStyledItemDelegate::paint(painter, option, index);
  }
}

QWidget *ThumbnailDelegate::createEditor(QWidget *parent,
                                         const QStyleOptionViewItem &option,
                                         const QModelIndex &index) const
{
  if (index.data().canConvert<ImageItem>()) {
    ThumbnailEditor *editor = new ThumbnailEditor(parent);
    connect(editor, &ThumbnailEditor::editingFinished,
            this, &ThumbnailDelegate::commitAndCloseEditor);
    return editor;
  }
  return QStyledItemDelegate::createEditor(parent, option, index);
}

void ThumbnailDelegate::commitAndCloseEditor()
{
  ThumbnailEditor *editor = qobject_cast<ThumbnailEditor *>(sender());
  emit commitData(editor);
  emit closeEditor(editor);
}

void ThumbnailDelegate::setEditorData(QWidget *editor,
                                      const QModelIndex &index) const
{
  if (index.data().canConvert<ImageItem>()) {
    ImageItem image = qvariant_cast<ImageItem>(index.data());
    ThumbnailEditor *thumbEditor = qobject_cast<ThumbnailEditor *>(editor);
    thumbEditor->setImageItem(image);
  } else {
    QStyledItemDelegate::setEditorData(editor, index);
  }
}

void ThumbnailDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                     const QModelIndex &index) const
{
  if (index.data().canConvert<ImageItem>()) {
    ThumbnailEditor *thumbEditor = qobject_cast<ThumbnailEditor *>(editor);
    model->setData(index, QVariant::fromValue(thumbEditor->getImageItem()));
  } else {
    QStyledItemDelegate::setModelData(editor, model, index);
  }
}

QSize ThumbnailDelegate::sizeHint(const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const
{
  if (index.data().canConvert<ImageItem>()) {
    ImageItem image = qvariant_cast<ImageItem>(index.data());
    return image.sizeHint();
  }
  return QStyledItemDelegate::sizeHint(option, index);
}