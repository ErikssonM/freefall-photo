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
  display = new DisplayArea(this);
  openFile = new QPushButton("File");
  openFolder = new QPushButton("Folder");

  view = new QListView();
  view->setItemDelegate(new ThumbnailDelegate);
  view->setSelectionMode(QAbstractItemView::SingleSelection);
  view->setSelectionBehavior(QAbstractItemView::SelectRows);

  layout->addWidget(openFile, 0, 0);
  layout->addWidget(openFolder, 0, 1);
  layout->addWidget(display, 0, 2, 2, 1);
  layout->addWidget(view, 1, 0, 1, 2);

  this->setLayout(layout);

  view->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
  openFile->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
  openFolder->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
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

  select = new QItemSelectionModel(model);
  view->setSelectionModel(select);

  connect(select, &QItemSelectionModel::currentChanged,
          display, &DisplayArea::imageSelected);
}
