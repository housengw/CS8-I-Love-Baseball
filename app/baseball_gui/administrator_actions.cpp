#include "administrator_actions.h"
#include "manage_stadiums.h"
#include "ui_administrator_actions.h"

AdministratorActions::AdministratorActions(Map *map, QWidget *parent)
    : QDialog(parent), ui(new Ui::AdministratorActions)
{
    ui->setupUi(this);
    _map = map;
}

AdministratorActions::~AdministratorActions() { delete ui; }

void AdministratorActions::on_manage_stadiums_button_clicked()
{
    ManageStadiums ms(_map);
    ms.setModal(true);
    ms.exec();
}
