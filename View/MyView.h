#ifndef MYVIEW_H_
#define MYVIEW_H_
#include <QGraphicsView>
#include <QMouseEvent>
#include <QWheelEvent>

class MyView :public QGraphicsView {
private:
	QSize size;
	QPointF start;
	QPointF end;
	QPointF center;
	QPointF delta;

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
};
#endif // !MYVIEW_H_

