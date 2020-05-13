#include "administrator_actions.h"
#include "ui_administrator_actions.h"

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
