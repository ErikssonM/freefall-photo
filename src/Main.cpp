#include <QApplication>
#include <QPushButton>
//#include "imageviewer.h"
#include "MainView.h"

int main(int argc, char **argv)
{
  QApplication app (argc, argv);
  //QGuiApplication::setApplicationDisplayName(ImageViewer::tr("Image Viewer"));

  QGuiApplication::setApplicationDisplayName(MainView::tr("Image Viewer"));

  MainView *test = new MainView();
  test->show();

  //ImageViewer *viewer = new ImageViewer();
  //viewer->show();

  return app.exec();
}