#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QImage>
#include <QString>
#include <QPainter>
#include <QImageReader>

class ImageItem
{
public:
  ImageItem(const QString &path);
  ImageItem();
  QString getFilePath() {return filePath;};
  QImage getThumbnail() {return thumbnail;};
  QImage getImage() {return image;};

  void paintThumbnail(QPainter *painter, const QRect &rect,
                      const QPalette &palette);
  QSize sizeHint() const;

private:
  QString filePath;
  QImage thumbnail;
  QImage image;

};

Q_DECLARE_METATYPE(ImageItem)

#endif