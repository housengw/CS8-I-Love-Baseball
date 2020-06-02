#ifndef UPDATE_PASSWORD_H
#define UPDATE_PASSWORD_H
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/constants.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class UpdatePassword;
}

class UpdatePassword : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit UpdatePassword(string password, QWidget *parent = nullptr);
    ~UpdatePassword();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_cancel_button_clicked();

    void on_confirm_button_clicked();

private:
    Ui::UpdatePassword *ui;   // UpdatePassword object for GUI
    string _password;         // string password
};

#endif // UPDATE_PASSWORD_H


/*****************************************************************
 * UpdatePassword Class
 * ______________________________________________________________
 *  The class 'UpdatePassword' is used to update the administrator
 *  accesscode.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* UpdatePassword(string password, QWidget *parent = nullptr);
*   Constructor; default constructor for a UpdatePassword object for qtwidgets,
*   Parameters:string password, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~UpdatePassword ();
*   Destructor; default Deconstructor for a UpdatePassword object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the UpdatePassword.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_cancel_button_clicked();
 *   Mutator: It will return  this->close();
 *   Parameters: None
 *   Return: close window
 *****************************************/
/*******************************************
 * void on_confirm_button_clicked();
 *   Mutator: It will update new password and save into file
 *   Parameters: None
 *   Return: password saved and close window
 *****************************************/
