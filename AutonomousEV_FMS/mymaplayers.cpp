#include "mymaplayers.h"
#include <QMessageBox>
#include <QtDebug>


bool rightMousePressed = false;
int _panStartX, _panStartY;

myMapLayers::myMapLayers(QWidget *parent) : QGraphicsView(parent)
{

}

myMapLayers::~myMapLayers()
{

}

void myMapLayers::mouseMoveEvent(QMouseEvent *e)
{
    QPoint delta(horizontalScrollBar()->value(), verticalScrollBar()->value());
    QPoint mousePos = e->pos();

    if(mousePos.x() <= this->size().width() && mousePos.y() <= this->size().height()){
        if(mousePos.x() >= 0 && mousePos.y() >= 0){
            emit sendMousePosition(mousePos, delta);
        }
    }

    //move picture
    if (rightMousePressed){
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (e->x() - _panStartX));
        verticalScrollBar()->setValue(verticalScrollBar()->value() - (e->y() - _panStartY));
        _panStartX = e->x();
        _panStartY = e->y();
        e->accept();
        return;
    }
    e->ignore();
}

void myMapLayers::mousePressEvent(QMouseEvent *e)
{
    QMessageBox msg;
    QPoint delta(horizontalScrollBar()->value(), verticalScrollBar()->value());
    QPoint mousePos = e->pos();

    if(e->button() == Qt::LeftButton)
    {
        mousePos = e->pos();
        emit sendMousePress(mousePos, delta);
//        msg.setText("Left Mouse Button Clicked!");
//        msg.exec();

    }
    else if (e->button() == Qt::RightButton)
    {
        mousePos = e->pos();
        emit sendMousePress(mousePos, delta);
//        msg.setText("Right Mouse Button Clicked!");
//        msg.exec();
    }

    //move picture
    if (e->button() == Qt::RightButton)
        {
            rightMousePressed = true;
            _panStartX = e->x();
            _panStartY = e->y();
            setCursor(Qt::ClosedHandCursor);
            e->accept();
            return;
        }

}

void myMapLayers::mouseReleaseEvent(QMouseEvent *e)
{
    //move picture
    if (e->button() == Qt::RightButton)
        {
            rightMousePressed = false;
            setCursor(Qt::ArrowCursor);
            e->accept();
            return;
        }
    e->ignore();
}

void myMapLayers::mouseDoubleClickEvent(QMouseEvent *e)
{
    QPoint delta(horizontalScrollBar()->value(), verticalScrollBar()->value());
    QPoint mousePos = e->pos();

    emit sendMouseDoubleClick(mousePos, delta);
}

void myMapLayers::wheelEvent(QWheelEvent *e)
{
    Q_UNUSED(e);
//    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

//    double scaleFactor = 1.15;
//    if(e->delta() > 0){
//        scale(scaleFactor, scaleFactor);
//    }
//    else{
//        scale(1/scaleFactor, 1/scaleFactor);
//    }
}


