#ifndef MODIFY_SOUVENIR_LIST_H
#define MODIFY_SOUVENIR_LIST_H

#include <QDialog>
#include "../../src/baseball_project/stadium.h"
#include "../../src/baseball_project/map.h"
#include <QString>

namespace Ui {
class modify_souvenir_list;
}

class modify_souvenir_list : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit modify_souvenir_list(Map* map, string staduim_name, QWidget *parent = nullptr);
    ~modify_souvenir_list();

    /**************
     ** ACCESSORS **
     **************/
    void display_List();
    void update_textBox();
    void clear_table();

private slots:

    /**************
     ** MUTATORS **
     **************/
    void on_index_currentIndexChanged(const QString &arg1);

    void on_modify_clicked();

    void on_delete_2_clicked();

    void on_add_clicked();

private:
    Ui::modify_souvenir_list *ui;  //modify_souvenir_list object for GUI
    string _stadium_name;          //stadium name
    Map* _map;                     // Map class object
    Stadium* _stadium;             //stadiun pointer
};

#endif // MODIFY_SOUVENIR_LIST_H

/*****************************************************************
 * modify_souvenir_list Class
 * ______________________________________________________________
 *  The class 'modify_souvenir_list' is used to modify souvenirs.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* modify_souvenir_list (Map* map,string staduim_name, QWidget *parent = nullptr);
*   Constructor; default constructor for a modify_souvenir_list object for qtwidgets,
*   Parameters: Map* map,string staduim_name, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~modify_souvenir_list();
*   Destructor; default Deconstructor for a modify_souvenir_list object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the modify_souvenir_list.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *   void on_index_currentIndexChanged(const QString &arg1);
 *   Mutator: It will update the souvenir table
 *   Parameters: const QString &arg1
 *   Return: None
 *****************************************/
/*******************************************
 *   void on_modify_clicked();
 *   Mutator: It will let the administrator modify the souvenir
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *   void on_delete_2_clicked();
 *   Mutator: It will let the administrator remove souvenir
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *   void on_add_clicked();
 *   Mutator: It will let the administrator add new souvenir
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/*******************************************
 * void display_List ();
 *   Accessor: It will display the list of souvenir information
 *   Parameters: none
 *   Return: None
 *****************************************/
/*******************************************
 * void update_textBox ();
 *   Accessor: It will update the table of souvenir
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 * void clear_table ();
 *   Accessor: It will clear the souvenir table
 *   Parameters: None
 *   Return: none
 *****************************************/
