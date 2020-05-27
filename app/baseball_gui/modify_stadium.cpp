#include "modify_stadium.h"
#include "ui_modify_stadium.h"

ModifyStadium::ModifyStadium(Map *map, string stadium_name, QWidget *parent)
    : QDialog(parent), ui(new Ui::ModifyStadium)
{
    ui->setupUi(this);
    _map = map;
    _stadium_name = stadium_name;
    Stadium stadium = _map->get_stadiums().get_stadium(_stadium_name);
    ui->stadium_name->setText(QString::fromStdString(_stadium_name));
    ui->team_name->setText(QString::fromStdString(stadium.get_team_name()));
    ui->capacity->setText(int_to_qstr(stadium.get_capacity()));
    ui->phone_number->setText(
        QString::fromStdString(stadium.get_phone_number()));
    ui->date->setText(
        QString::fromStdString(stadium.get_date_opened().get_date()));
    ui->street->setText(QString::fromStdString(stadium.get_address1()));
    ui->city->setText(QString::fromStdString(stadium.get_address2()));
    ui->surface->addItem(QString::fromStdString(GRASS_SURFACE_NAME));
    ui->surface->addItem(QString::fromStdString(TURF_SURFACE_NAME));
    if (stadium.get_surface() == GRASS_SURFACE_NAME)
    {
        ui->surface->setCurrentText(QString::fromStdString(GRASS_SURFACE_NAME));
    }
    else
    {
        ui->surface->setCurrentText(QString::fromStdString(TURF_SURFACE_NAME));
    }
}

ModifyStadium::~ModifyStadium()
{
    delete ui;
}

void ModifyStadium::on_cancel_button_clicked()
{
    this->close();
}

void ModifyStadium::on_confirm_button_clicked()
{
    string stadium_name, team_name, capacity, phone_number, date, street, city,
        surface;
    stadium_name = ui->stadium_name->toPlainText().toStdString();
    team_name = ui->team_name->toPlainText().toStdString();
    capacity = ui->capacity->toPlainText().toStdString();
    phone_number = ui->phone_number->toPlainText().toStdString();
    date = ui->date->toPlainText().toStdString();
    street = ui->street->toPlainText().toStdString();
    city = ui->city->toPlainText().toStdString();
    surface = ui->surface->currentText().toStdString();

    if (!is_unsigned_int(capacity))
    {
        QMessageBox::warning(this, "Error", "Invalid Capacity");
        return;
    }
    if (!is_valid_date(date))
    {
        QMessageBox::warning(this, "Error", "Invalid Date");
        return;
    }

    Date d;
    d.set_date(date);
    Stadium s(stadium_name, team_name, street, city, phone_number, d,
              stoi(capacity), surface);
    _map->update_stadium(_stadium_name, s);
    this->close();
}
