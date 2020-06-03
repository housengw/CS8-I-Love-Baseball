#ifndef ADMINISTRATOR_ACTIONS_H
#define ADMINISTRATOR_ACTIONS_H
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/constants.h"
#include <QDialog>
#include <QMessageBox>


namespace Ui {
class AdministratorActions;
}

class AdministratorActions : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit AdministratorActions(Map* map, QWidget *parent = nullptr);
    ~AdministratorActions();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_manage_stadiums_button_clicked();

    void on_add_stadium_button_clicked();

    void on_manage_edges_button_clicked();

private:
    Ui::AdministratorActions *ui;  // AdministratorActions object for GUI
    Map* _map;                     // Map class object
};

#endif // ADMINISTRATOR_ACTIONS_H


/*****************************************************************
 * AdministratorActions Class
 * ______________________________________________________________
 *  The class 'AdministratorActions' is used for processing administrator
 *  actions like modify stadium information, add or remove stadium.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* AdministratorActions(Map* map, QWidget *parent = nullptr);
*   Constructor; default constructor for a AdministratorActions object for qtwidgets,
*   Parameters:Map* map,  parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~AdministratorActions();
*   Destructor; default Deconstructor for a AdministratorActions object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the AdministratorActions.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_manage_stadiums_button_clicked();
 *   Mutator: It will call ManageStadiums to manage stadiums
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_add_stadium_button_clicked();
 *   Mutator: It will call AddStadium for adding a new stadium
 *   Parameters: None
 *   Return: None
 *****************************************/
