#include "administrator_login.h"
#include "ui_administrator_login.h"
#include "administrator_actions.h"
#include "update_password.h"

/*****************************************************************
 * CONSTRUCTOR
 * AdministratorLogin::AdministratorLogin(Map* map, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes the private variables
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
AdministratorLogin::AdministratorLogin(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministratorLogin)
{
    ui->setupUi(this);
    _map = map;
    _password = load_password (APP_PW_FILE_PATH);
}

/*****************************************************************
 * DESTRUCTOR
 * AdministratorLogin::~AdministratorLogin(): Class AdministratorLogin
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
AdministratorLogin::~AdministratorLogin()
{
    delete ui;
}

/*****************************************************************
 *  Method void AdministratorLogin::on_cancel_button_clicked()
 *________________________________________________________________
 *  This function returns this->close()
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     cancel button clicked
 *
 *  POST-CONDITIONS
 *     close window
 *****************************************************************/
void AdministratorLogin::on_cancel_button_clicked()
{
    this->close();
}

/*****************************************************************
 *  Method void AdministratorLogin::on_login_button_clicked()
 *________________________________________________________________
 *  This function process input to let administratot log in and display
 *  error message for incorrect input
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     log in button clicked and GUI input filled
 *
 *  POST-CONDITIONS
 *     close window
 *****************************************************************/
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

/*****************************************************************
 *  Method void AdministratorLogin::on_update_password_button_clicked()
 *________________________________________________________________
 *  This function process input to let administrator update the password
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     update password button clicked and GUI input filled
 *
 *  POST-CONDITIONS
 *     Update password and display successfully changed message
 *****************************************************************/
void AdministratorLogin::on_update_password_button_clicked()
{
    UpdatePassword up(_password);
    up.setModal(true);
    up.exec();
    _password = load_password(APP_PW_FILE_PATH);
    QMessageBox::information(this, "Message", "Password successfully changed");
}
