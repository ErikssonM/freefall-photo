#ifndef DISPLAYAREA_H
#define DISPLAYAREA_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QModelIndex>

#include "ImageItem.h"

class DisplayArea : public QScrollArea
{
  Q_OBJECT

public:
  DisplayArea(QWidget *parent = nullptr);

public slots:
  void imageSelected(const QModelIndex &current,
                     const QModelIndex &previous);
  void zoomOut();
  void zoomIn();

private:
  QLabel *display;
  ImageItem *image;
};

#endif