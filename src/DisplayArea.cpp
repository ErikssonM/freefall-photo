#include "DisplayArea.h"

DisplayArea::DisplayArea(QWidget *parent)
  : QScrollArea(parent)
{
  display = new QLabel("Select an image to View");
  display->setScaledContents(true);
  display->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  setBackgroundRole(QPalette::Dark);
  setWidget(display);
}

void DisplayArea::imageSelected(const QModelIndex &current,
                                const QModelIndex &previous)
{
  if (current.data().canConvert<ImageItem>()) {
    ImageItem selectedImage = qvariant_cast<ImageItem>(current.data());
    QPixmap pix = QPixmap::fromImage(selectedImage.getImage());
    display->setPixmap(pix);
    display->resize(pix.size());
  } else {
    qDebug("Attempting to convert ImageItem, but cannot");
  }
}

void DisplayArea::zoomIn()
{

}

void DisplayArea::zoomOut()
{

}