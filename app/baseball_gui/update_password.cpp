#include "update_password.h"
#include "ui_update_password.h"

/*****************************************************************
 * CONSTRUCTOR
 * UpdatePassword::UpdatePassword(string password, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes variables to default values
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
UpdatePassword::UpdatePassword(string password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdatePassword)
{
    ui->setupUi(this);
    _password = password;
}

/*****************************************************************
 * DESTRUCTOR
 * UpdatePassword::~UpdatePassword(): Class UpdatePassword
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
UpdatePassword::~UpdatePassword()
{
    delete ui;
}

/*****************************************************************
 *  Method void UpdatePassword::on_cancel_button_clicked()
 *________________________________________________________________
 *  This function returns this->close()
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     cancel button clicked
 *
 *  POST-CONDITIONS
 *     close window
 *****************************************************************/
void UpdatePassword::on_cancel_button_clicked()
{
    this->close();
}

/*****************************************************************
 *  Method void UpdatePassword::on_confirm_button_clicked()
 *________________________________________________________________
 *  This function process input to let administrator to change access password
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     confirm button clicked and GUI input filled
 *
 *  POST-CONDITIONS
 *     save password and close window
 *****************************************************************/
void UpdatePassword::on_confirm_button_clicked()
{
    string old_pw, new_pw;
    old_pw = ui->old_password->toPlainText().toStdString();
    new_pw = ui->new_password->toPlainText().toStdString();
    if (old_pw != _password){
        QMessageBox::warning(this, "Error", "Invalid Old Password");
        return;
    }
    save_password(APP_PW_FILE_PATH, new_pw);
    this->close();
}
