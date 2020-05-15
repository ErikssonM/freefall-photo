#ifndef TEST_LAYOUT_H
#define TEST_LAYOUT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QListView>
#include <QScrollArea>

#include "ImageListModel.h"
#include "ThumbnailDelegate.h"
#include "DisplayArea.h"

class MainView : public QWidget
{
  Q_OBJECT

public:
  MainView(QWidget *parent = nullptr);

private:
  void createLayout();
  void createConnections();

  ImageListModel *model;
  QListView *view;
  QItemSelectionModel *select;
  //ThumbnailDelegate *delegate;

  QGridLayout *layout;

  DisplayArea *display;
  QLabel *placeholder;
  QPushButton *openFile;
  QPushButton *openFolder;
};

#endif