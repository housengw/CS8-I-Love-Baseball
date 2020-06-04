#ifndef VIEW_SOUVENIR_LIST_H
#define VIEW_SOUVENIR_LIST_H

#include <QDialog>
#include "../../src/baseball_project/map.h"

namespace Ui {
class view_souvenir_list;
}

class view_souvenir_list : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit view_souvenir_list(Map* map, Stadium* stadium, QWidget *parent = nullptr);
    ~view_souvenir_list();

    /**************
     ** ACCESSORS **
     **************/
    void display_List();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_pushButton_clicked();

private:
    Ui::view_souvenir_list *ui; // view_souvenir_list object for GUI
    Stadium* _stadium;          // stadium pointer
    Map* _map;                  // Map class object
};

#endif // VIEW_SOUVENIR_LIST_H


/*****************************************************************
 * view_souvenir_list Class
 * ______________________________________________________________
 *  The class 'view_souvenir_list' is used to display the souvenir information
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* view_souvenir_list (Map* map, Stadium* stadium, QWidget *parent = nullptr);
*   Constructor; default constructor for a view_souvenir_list object for qtwidgets,
*   Parameters:Map* map,Stadium* stadium, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~view_souvenir_list ();
*   Destructor; default Deconstructor for a view_souvenir_list object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the view_souvenir_list.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_pushButton_clicked();
 *   Mutator: It will call AdministratorLogin for administrator actions
 *   Parameters: None
 *   Return: none
 *****************************************/

/****************************************
 **  ACCESSORS  **
 *****************************************/
/*******************************************
 * void display_List();
 *   Mutator: It will display the sourvenir information
 *   Parameters: None
 *   Return: none
 *****************************************/
