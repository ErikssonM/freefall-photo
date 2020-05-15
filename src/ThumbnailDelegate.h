#ifndef THUMBNAILDELEGATE_H
#define THUMBNAILDELEGATE_H

#include <QObject>
#include <QPainter>
#include <QStyledItemDelegate>

#include "ImageItem.h"

class ThumbnailDelegate : public QStyledItemDelegate
{
  Q_OBJECT
public:
  using QStyledItemDelegate::QStyledItemDelegate;

  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const override;
  QSize sizeHint(const QStyleOptionViewItem &option,
                 const QModelIndex &index) const override;
  bool editorEvent(QEvent *event, QAbstractItemModel *model,
                   const QStyleOptionViewItem &option,
                   const QModelIndex &index) override;
};

#endif