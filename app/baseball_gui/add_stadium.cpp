#include "add_stadium.h"
#include "ui_add_stadium.h"

AddStadium::AddStadium(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStadium)
{
    ui->setupUi(this);
    _map = map;
    ui->surface->addItem(QString::fromStdString(GRASS_SURFACE_NAME));
    ui->surface->addItem(QString::fromStdString(TURF_SURFACE_NAME));
}

AddStadium::~AddStadium()
{
    delete ui;
}

void AddStadium::on_add_button_clicked()
{
    string stadium_name, team_name, capacity, phone_number, date, street, city, surface;
    stadium_name = ui->stadium_name->toPlainText().toStdString();
    team_name = ui->team_name->toPlainText().toStdString();
    capacity = ui->capacity->toPlainText().toStdString();
    phone_number = ui->phone_number->toPlainText().toStdString();
    date = ui->date->toPlainText().toStdString();
    street = ui->street->toPlainText().toStdString();
    city = ui->city->toPlainText().toStdString();
    surface = ui->surface->currentText().toStdString();

    if (!is_unsigned_int(capacity)){
        QMessageBox::warning(this, "Error", "Invalid Capacity");
        return;
    }
    if (!is_valid_date(date)){
        QMessageBox::warning(this, "Error", "Invalid Date");
        return;
    }

    if (_map->get_stadiums().contains(stadium_name)){
        QMessageBox::warning(this, "Error", "Stadium Already Exists");
        return;
    }

    Date d;
    d.set_whole(date);
    Stadium s(stadium_name, team_name, street, city, phone_number, d, stoi(capacity), surface);
    _map->add_stadium(s);
    this->close();
}

void AddStadium::on_cancel_button_clicked()
{
    this->close();
}
