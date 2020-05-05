#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>      // header for images in GUI

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
