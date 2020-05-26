#include "manage_stadiums.h"
#include "modify_stadium.h"
#include "ui_manage_stadiums.h"

ManageStadiums::ManageStadiums(Map *map, QWidget *parent)
    : QDialog(parent), ui(new Ui::ManageStadiums)
{
    ui->setupUi(this);
    _map = map;

    vector<Stadium> stadium_v = sorted_by_stadium_name(_map->get_stadiums());
    for (size_t i = 0; i < stadium_v.size(); i++)
    {
        ui->stadium_cbox->addItem(
            QString::fromStdString(stadium_v[i].get_stadium_name()));
    }
}

ManageStadiums::~ManageStadiums()
{
    delete ui;
}

void ManageStadiums::on_modify_button_clicked()
{
    string stadium_name = ui->stadium_cbox->currentText().toStdString();
    ModifyStadium ms(_map, stadium_name);
    ms.setModal(true);
    ms.exec();
}
