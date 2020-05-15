#include "ImageItem.h"

ImageItem::ImageItem(const QString &path)
{
  filePath = path;

  QImageReader reader(path);
  reader.setAutoTransform(true);
  image = reader.read();
  thumbnail = image.scaled(100, 100, Qt::KeepAspectRatio);
  qDebug("Read image");
}

ImageItem::ImageItem()
{
}


void ImageItem::paintThumbnail(QPainter *painter, const QRect &rect,
                               const QPalette &palette)
{
  painter->save();

  painter->setRenderHint(QPainter::Antialiasing, true);
  //painter->drawText(rect.x(), rect.y(), filePath);
  painter->drawImage(rect, thumbnail);
  
  painter->restore();
}

QSize ImageItem::sizeHint() const
{
  return QSize(100, 100);
}