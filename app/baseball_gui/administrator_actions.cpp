#include "administrator_actions.h"
#include "ui_administrator_actions.h"
#include "manage_stadiums.h"
#include "add_stadium.h"

AdministratorActions::AdministratorActions(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministratorActions)
{
    ui->setupUi(this);
    _map = map;
}

AdministratorActions::~AdministratorActions()
{
    delete ui;
}

void AdministratorActions::on_manage_stadiums_button_clicked()
{
    ManageStadiums ms(_map);
    ms.setModal(true);
    ms.exec();
}

void AdministratorActions::on_add_stadium_button_clicked()
{
    AddStadium as(_map);
    as.setModal(true);
    as.exec();
}
