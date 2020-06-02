#ifndef MANAGE_STADIUMS_H
#define MANAGE_STADIUMS_H
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/sort_functions.h"
#include <QDialog>
#include <QMessageBox>


namespace Ui {
class ManageStadiums;
}

class ManageStadiums : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit ManageStadiums(Map* map, QWidget *parent = nullptr);
    ~ManageStadiums();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_modify_button_clicked();

private:
    Ui::ManageStadiums *ui;    // ManageStadiums object for GUI
    Map* _map;                 // Map class object
};

#endif // MANAGE_STADIUMS_H

/*****************************************************************
 * ManageStadiums Class
 * ______________________________________________________________
 *  The class 'ManageStadiums' is used for manage the stadiums
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* ManageStadiums (Map* map, QWidget *parent = nullptr);
*   Constructor; default constructor for a ManageStadiums object for qtwidgets,
*   Parameters: Map* map, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~ManageStadiums();
*   Destructor; default Deconstructor for a ManageStadiums object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the ManageStadiums.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *  void on_modify_button_clicked();
 *   Mutator: It will let the administrator modify the stadiums
 *   Parameters: None
 *   Return: None
 *****************************************/
