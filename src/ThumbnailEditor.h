#ifndef THUMBNAILEDITOR_H
#define THUMBNAILEDITOR_H

#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QPainter>

#include "ImageItem.h"

class ThumbnailEditor : public QWidget
{
  Q_OBJECT
public:
  ThumbnailEditor(QWidget *parent = nullptr);

  QSize sizeHint() const override;
  void setImageItem(const ImageItem &imageItem) {
    image = imageItem;
  }
  ImageItem getImageItem() {return image;}

signals:
  void editingFinished();

protected:
  void paintEvent(QPaintEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

private:
  ImageItem image;
};

#endif