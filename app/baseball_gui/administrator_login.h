#ifndef ADMINISTRATOR_LOGIN_H
#define ADMINISTRATOR_LOGIN_H
#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AdministratorLogin;
}

class AdministratorLogin : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit AdministratorLogin(Map* map, QWidget *parent = nullptr);
    ~AdministratorLogin();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_cancel_button_clicked();

    void on_login_button_clicked();

    void on_update_password_button_clicked();

private:
    Ui::AdministratorLogin *ui;// AdministratorLogin object for GUI
    Map* _map;                 // Map class object
    string _password;          // String password
};

#endif // ADMINISTRATOR_LOGIN_H


/*****************************************************************
 * AdministratorLogin Class
 * ______________________________________________________________
 *  The class 'AdministratorLogin' is used for processing input from the GUI
 *  and administrator log in.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/

/****************************************************************
* AdministratorLogin (Map* map, QWidget *parent = nullptr);
*   Constructor; default constructor for a AdministratorLogin object for qtwidgets,
*   Parameters: Map* map, parent (QWidget)
*   Return: none
***************************************************************/

/****************************************************************
* ~AdministratorLogin();
*   Destructor; default Deconstructor for a AdministratorLogin object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the AdministratorLogin.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_cancel_button_clicked();
 *   Mutator: It will return this->close()
 *   display any error for incorrect information
 *   Parameters: None
 *   Return: close window
 *****************************************/
/*******************************************
 *  void on_update_password_button_clicked();
 *   Mutator: It will process input for a new password
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_login_button_clicked();
 *   Mutator: It will process input and let administrator to log in
 *   Parameters: None
 *   Return: close the window
 *****************************************/
