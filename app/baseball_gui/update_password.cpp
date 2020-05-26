#include "update_password.h"
#include "ui_update_password.h"

UpdatePassword::UpdatePassword(string password, QWidget *parent)
    : QDialog(parent), ui(new Ui::UpdatePassword)
{
    ui->setupUi(this);
    _password = password;
}

UpdatePassword::~UpdatePassword()
{
    delete ui;
}

void UpdatePassword::on_cancel_button_clicked()
{
    this->close();
}

void UpdatePassword::on_confirm_button_clicked()
{
    string old_pw, new_pw;
    old_pw = ui->old_password->toPlainText().toStdString();
    new_pw = ui->new_password->toPlainText().toStdString();
    if (old_pw != _password)
    {
        QMessageBox::warning(this, "Error", "Invalid Old Password");
        return;
    }
    save_password(APP_PW_FILE_PATH, new_pw);
    this->close();
}
