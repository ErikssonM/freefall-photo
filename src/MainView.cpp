#include "MainView.h"

MainView::MainView(QWidget *parent)
  : QWidget(parent)
{
  createLayout();
  createConnections();
}

void MainView::createLayout()
{
  layout = new QGridLayout(this);
  image = new QLabel("Image");
  openFile = new QPushButton("File");
  openFolder = new QPushButton("Folder");

  view = new QListView();
  view->setItemDelegate(new ThumbnailDelegate);
  view->setSelectionMode(QAbstractItemView::SingleSelection);
  view->setSelectionBehavior(QAbstractItemView::SelectRows);
  //view->setEditTriggers(QAbstractItemView::SelectedClicked);

  layout->addWidget(openFile, 0, 0);
  layout->addWidget(openFolder, 0, 1);
  layout->addWidget(image, 0, 2, 2, 1);
  layout->addWidget(view, 1, 0, 1, 2);

  this->setLayout(layout);
}

void MainView::createConnections()
{
  model = new ImageListModel();
  model->appendRow(
    QVariant::fromValue(ImageItem("/home/martin/Projects/Image/test_resource/1.JPG")));
  model->appendRow(
    QVariant::fromValue(ImageItem("/home/martin/Projects/Image/test_resource/2.JPG")));
  model->appendRow(
    QVariant::fromValue(ImageItem("/home/martin/Projects/Image/test_resource/3.JPG")));
  view->setModel(model);
  view->setSelectionModel(new QItemSelectionModel(model));
}
