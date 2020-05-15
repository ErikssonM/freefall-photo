#ifndef DISPLAYAREA_H
#define DISPLAYAREA_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QModelIndex>
#include <QWheelEvent>

#include "ImageItem.h"

//https://stackoverflow.com/a/40687145

class DisplayArea : public QWidget
{
  Q_OBJECT

public:
  DisplayArea(QWidget *parent = nullptr);

  QSize sizeHint() const override;

public slots:
  void imageSelected(const QModelIndex &current,
                     const QModelIndex &previous);
  void zoom(float factor);

protected:
  void paintEvent(QPaintEvent *e) override;
  void mousePressEvent(QMouseEvent *e) override;
  void mouseMoveEvent(QMouseEvent *e) override;
  void mouseReleaseEvent(QMouseEvent *e) override;
  void wheelEvent(QWheelEvent *e) override;

private:
  QPixmap pixmap;
  //ImageItem *image;

  QRectF rect;
  QPointF ref;
  QPointF delta;
  float scale;
};

#endif