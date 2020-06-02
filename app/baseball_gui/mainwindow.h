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
    void on_Trip_clicked();

    void Mouse_current_pos ();
    void Mouse_release ();

    void plot_connections();
    void plot_trip();
    void update_visited_stadiums_table();
    void update_map();

    void on_view_distances_button_clicked();
    void on_display_list_clicked();
    void on_administrator_button_clicked();

    void on_clear_trip_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Map* _map;
    SouvenirsContainer purchaseList;
};

#endif // MAINWINDOW_H
