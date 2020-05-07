#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>      // header for images in GUI

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPixmap m (":/Images/Stadiums.png");

    m = m.scaled(ui->graphicsView->width(),ui->graphicsView->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    scene->addPixmap(m);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_2_clicked()
{
    QLine l;
    l.setLine(150,160,300, 300);
    scene->addLine(l);
    ui->graphicsView->setScene(scene);
}
