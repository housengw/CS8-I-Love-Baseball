#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include <QMouseEvent>
#include <QWidget>

#include <QDebug>
#include <QEvent>
#include <QLabel>

class mouse_event : public QLabel
{
    Q_OBJECT
  public:
    // Variables
    int x, // x position of the cursor
        y; // y position of the cursor

    explicit mouse_event(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *);

  signals:
    void Mouse_Pos(); // Cursor position
    void Mouse_Release();

  public slots:
};

#endif // MOUSE_EVENT_H
