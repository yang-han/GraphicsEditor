#include "MyView.h"

void MyView::mousePressEvent(QMouseEvent *event)
{
	QGraphicsView::mousePressEvent(event);

	if (event->button() == Qt::LeftButton) {
		start = event->pos();
		center = mapToScene(viewport()->rect().center());
	}
}

void MyView::mouseMoveEvent(QMouseEvent *event)
{
	QGraphicsView::mouseMoveEvent(event);
	delta = event->pos() - start;
	//centerOn(mViewCenterAtScene - point / mZoomRate);
}

void MyView::mouseReleaseEvent(QMouseEvent *event)
{
	QGraphicsView::mouseReleaseEvent(event);
}

void MyView::wheelEvent(QWheelEvent *event) {

}