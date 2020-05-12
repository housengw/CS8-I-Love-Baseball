#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include <QWidget>
#include <QMouseEvent>

#include <QDebug>
#include <QEvent>
#include <QLabel>

class mouse_event : public QLabel
{
    Q_OBJECT
public:
    explicit mouse_event(QWidget *parent = nullptr);

    void mouseMoveEvent (QMouseEvent *ev);
    void mouseReleaseEvent (QMouseEvent *);

    int x, y;

signals:

    void Mouse_Pos ();
    void Mouse_Release ();

public slots:
};

#endif // MOUSE_EVENT_H
