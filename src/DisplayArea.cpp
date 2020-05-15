#include "DisplayArea.h"

DisplayArea::DisplayArea(QWidget *parent)
{
  scale = 1.0;
}

void DisplayArea::paintEvent (QPaintEvent *e)
{
  QPainter p{this};
  p.translate(rect.center());
  p.scale(scale, scale);
  p.translate(delta);
  p.drawPixmap(rect.topLeft(), pixmap);
}

void DisplayArea::imageSelected(const QModelIndex &current,
                                const QModelIndex &previous)
{
  if (current.data().canConvert<ImageItem>()) {
    ImageItem selectedImage = qvariant_cast<ImageItem>(current.data());
    pixmap = QPixmap::fromImage(selectedImage.getImage());
    rect = pixmap.rect();
    rect.translate(rect.center());
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
  delta += (e->pos() - ref) * 1.0/scale;
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

  if (!numDegrees.isNull()) {
    float y = numDegrees.y();
    if (y < 0) {
      zoom(1.1);
    } else if (y > 0) {
      zoom(0.9);
    }
  }
  e->accept();
}

void DisplayArea::zoom(float factor)
{
  scale *= factor;
  update();
}

QSize DisplayArea::sizeHint() const
{
  return {400, 400};
}