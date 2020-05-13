#include "administrator_login.h"
#include "ui_administrator_login.h"
#include "administrator_actions.h"

AdministratorLogin::AdministratorLogin(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministratorLogin)
{
    ui->setupUi(this);
    _map = map;
}

AdministratorLogin::~AdministratorLogin()
{
    delete ui;
}

void AdministratorLogin::on_cancel_button_clicked()
{
    this->close();
}

void AdministratorLogin::on_login_button_clicked()
{
    string pw = ui->pw_text_edit->toPlainText().toStdString();
    if (!(pw == TEMP_PW)){
        QMessageBox::warning(this, "Error", "Invalid Password");
        return;
    }

    this->hide();
    AdministratorActions aa(_map);
    aa.setModal(true);
    aa.exec();
    this->close();
}
