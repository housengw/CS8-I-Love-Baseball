#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>      // header for images in GUI

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap mapPixmap(":/map.jpg");                 // Pixelmap of the map

    int width_label_map = ui->label_map->width();   // UI label_map item width
    int height_label_map = ui->label_map->height(); // UI labl_map item height

    // PROC - set ui label_map variable to QPixmap object defined above
    //        as mapPixmap
    // Documentation: https://doc.qt.io/qt-5/qpixmap.html#scaled
    ui->label_map->setPixmap(mapPixmap.scaled(width_label_map,
                                              height_label_map));
}

MainWindow::~MainWindow()
{
    delete ui;
}
