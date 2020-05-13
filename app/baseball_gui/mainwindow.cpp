#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mouse_event.h"
#include "view_distances.h"
#include "list_of_stadiums.h"
#include "administrator_login.h"
#include <QPixmap>      // header for images in GUI


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _map = new Map;
    ui->setupUi(this);
    scene = new QGraphicsScene();
    on_Map_clicked();
    connect(ui->mouse_area, SIGNAL (Mouse_Pos()), this, SLOT (Mouse_current_pos ()));
    connect(ui->mouse_area, SIGNAL (Mouse_Release()), this, SLOT (Mouse_release ()));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Map_clicked()
{
    QPixmap m (":/Images/Stadiums.png");

    m = m.scaled(ui->graphicsView->width(),ui->graphicsView->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    scene->addPixmap(m);

    ui->graphicsView->setScene(scene);
}


void MainWindow::on_Trip_clicked()
{
    plot_connections();
}


void MainWindow::Mouse_current_pos()
{
    ui->current_pos->setText(
                QString ("X = %1, Y = %2").arg(ui->mouse_area->x).arg(ui->mouse_area->y));
}


void MainWindow::Mouse_release()
{
    ui->location_pressed->setText(QString ("X = %1, Y = %2").arg(ui->mouse_area->x).arg(ui->mouse_area->y));
}


void MainWindow::plot_connections(){
    vector<Plottable> plottables;
    Point p1, p2;
    QLine l;
    plottables = _map->get_plottables();
    for (size_t i=0; i<plottables.size(); i++){
        p1 = plottables[i].p1;
        p2 = plottables[i].p2;
        l.setLine(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
        scene->addLine(l);
    }
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_view_distances_button_clicked()
{
    ViewDistances vd(_map);
    vd.setModal(true);
    vd.exec();
}


void MainWindow::on_display_list_clicked()
{
    list_of_Stadiums list;
    list.setModal(true);
    list.exec();
}

void MainWindow::on_administrator_button_clicked()
{
    AdministratorLogin al(_map);
    al.setModal(true);
    al.exec();
}
