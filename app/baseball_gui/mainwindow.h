#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Map_clicked();

    void on_Trip_clicked();

    void Mouse_current_pos ();
    void Mouse_release ();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

};

#endif // MAINWINDOW_H
