#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mouse_event.h"

#include <QPixmap>      // header for images in GUI

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

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

    m = m.scaled(ui->graphicsView->width(),ui->graphicsView->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    scene->addPixmap(m);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_Trip_clicked()
{
    QLine l,l1,l2;
    l.setLine(217, 177,317, 319);
    scene->addLine(l);
    l1.setLine(76,49,217, 177);
    scene->addLine(l1);
    l2.setLine(217, 177,328, 190);
    scene->addLine(l2);
    ui->graphicsView->setScene(scene);
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

