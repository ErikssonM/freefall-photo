#include "ThumbnailEditor.h"

ThumbnailEditor::ThumbnailEditor(QWidget *parent) : QWidget(parent)
{
  //Nothing?
}

void ThumbnailEditor::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  image.paintThumbnail(&painter, rect(), palette());
}

void ThumbnailEditor::mouseMoveEvent(QMouseEvent *event)
{
  //Nothing?
  QWidget::mouseMoveEvent(event);
}

void ThumbnailEditor::mouseReleaseEvent(QMouseEvent *event)
{
  emit editingFinished();
  QWidget::mouseReleaseEvent(event);
}

QSize ThumbnailEditor::sizeHint() const
{
  return this->image.sizeHint();
}