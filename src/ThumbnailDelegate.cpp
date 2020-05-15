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

bool ThumbnailDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index)
{
  return false;
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