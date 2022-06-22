#ifndef MYMAPLAYERS_H
#define MYMAPLAYERS_H

#include <QGraphicsView>
#include <QObject>
#include <QWidget>

#include <QMouseEvent>
#include <QScrollBar>

class myMapLayers : public QGraphicsView
{
    Q_OBJECT
public:
    myMapLayers(QWidget *parent = 0);
    ~myMapLayers();

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    virtual void wheelEvent(QWheelEvent *e);

signals:
    void sendMousePosition(QPoint&, QPoint&);
    void sendMousePress(QPoint&, QPoint&);
    void sendMouseDoubleClick(QPoint&, QPoint&);

};

#endif // MYMAPLAYERS_H
