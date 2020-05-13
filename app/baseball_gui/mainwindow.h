#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../../src/baseball_project/map.h"
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

    void plot_connections();

    void on_view_distances_button_clicked();

    void on_administrator_button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Map* _map;
};

#endif // MAINWINDOW_H
