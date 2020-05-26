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
}

ModifyStadium::~ModifyStadium() { delete ui; }

void ModifyStadium::on_cancel_button_clicked() { this->close(); }
