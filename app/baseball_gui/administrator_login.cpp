#include "administrator_login.h"
#include "administrator_actions.h"
#include "update_password.h"

AdministratorLogin::AdministratorLogin(Map *map, QWidget *parent)
    : QDialog(parent), ui(new Ui::AdministratorLogin)
{
    ui->setupUi(this);
    _map = map;
    _password = load_password(APP_PW_FILE_PATH);
}

AdministratorLogin::~AdministratorLogin() { delete ui; }

void AdministratorLogin::on_cancel_button_clicked() { this->close(); }

void AdministratorLogin::on_login_button_clicked()
{
    string pw = ui->pw_text_edit->toPlainText().toStdString();
    if (!(pw == _password)){
        QMessageBox::warning(this, "Error", "Invalid Password");
        return;
    }

    this->hide();
    AdministratorActions aa(_map);
    aa.setModal(true);
    aa.exec();
    this->close();
}

void AdministratorLogin::on_update_password_button_clicked()
{
    UpdatePassword up(_password);
    up.setModal(true);
    up.exec();
    _password = load_password(APP_PW_FILE_PATH);
    QMessageBox::information(this, "Message", "Password successfully changed");
}
