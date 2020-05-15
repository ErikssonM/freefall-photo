#include "ImageItem.h"

ImageItem::ImageItem(const QString &path)
{
  filePath = path;

  QImageReader reader(path);
  reader.setAutoTransform(true);
  image = reader.read();
  //TODO:Add padding to thumbnail image
  thumbnail = image.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
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

  QSize thumbnailSize = thumbnail.size();
  QRect place = QRect(rect.x(), rect.y(), thumbnailSize.width(), thumbnailSize.height());
  painter->drawImage(place, thumbnail);
  
  painter->restore();
}

QSize ImageItem::sizeHint() const
{
  return QSize(200, 100);
}