#ifndef TEST_LAYOUT_H
#define TEST_LAYOUT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QListView>
#include <QStringListModel>

#include "ImageListModel.h"
#include "ThumbnailDelegate.h"

class MainView : public QWidget
{
  Q_OBJECT

public:
  MainView(QWidget *parent = nullptr);

private:
  void createLayout();
  void createConnections();

  //SomeKindOfImageModel
  //ThumbnailView (Should probably be inside widget)

  ImageListModel *model;
  //QStringListModel *model;
  QListView *view;
  //ThumbnailDelegate *delegate;

  QGridLayout *layout;

  QLabel *image;
  QLabel *placeholder;
  QPushButton *openFile;
  QPushButton *openFolder;
};

#endif