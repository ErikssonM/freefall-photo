#include "DisplayArea.h"

DisplayArea::DisplayArea(QWidget *parent)
{
  scale = 1.0;
}

void DisplayArea::paintEvent(QPaintEvent *e)
{
  QPainter p{this};
  p.fillRect(this->rect(), Qt::darkGray);
  p.scale(scale, scale);
  p.translate(center);
  p.drawPixmap(pixRect, pixmap);
}

void DisplayArea::imageSelected(const QModelIndex &current,
                                const QModelIndex &previous)
{
  if (current.data().canConvert<ImageItem>()) {
    ImageItem selectedImage = qvariant_cast<ImageItem>(current.data());
    pixmap = QPixmap::fromImage(selectedImage.getImage());
    pixRect = pixmap.rect();
    update();
  } else {
    qDebug("Attempting to convert ImageItem, but cannot");
  }
}

void DisplayArea::mousePressEvent(QMouseEvent *e)
{
  ref = e->pos();
  setMouseTracking(true);
}

void DisplayArea::mouseMoveEvent(QMouseEvent *e)
{
  center += (e->pos() - ref) * 1.0/scale;
  ref = e->pos();
  update();
}

void DisplayArea::mouseReleaseEvent(QMouseEvent *e)
{
  setMouseTracking(false);
}

void DisplayArea::wheelEvent(QWheelEvent *e)
{
  QPoint numDegrees = e->angleDelta();
  QPointF mousePos = e->posF();

  if (!numDegrees.isNull()) {
    float y = numDegrees.y();
    if (y < 0) {
      zoom(1.1, mousePos);
    } else if (y > 0) {
      zoom(0.9, mousePos);
    }
  }
  e->accept();
}

void DisplayArea::zoom(float factor, QPointF mousePos)
{
  float newScale = scale * factor;
  if (newScale < 0.1) {
    scale = 0.1;
  } else if (newScale > 4.0) {
    scale = 4.0;
  } else {
    scale = newScale;
    center += mousePos * (1.0 - factor) * 1.0/scale;
  }
  update();
}

QSize DisplayArea::sizeHint() const
{
  return {800, 800};
}