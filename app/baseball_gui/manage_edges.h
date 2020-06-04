#ifndef MANAGE_EDGES_H
#define MANAGE_EDGES_H
#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ManageEdges;
}

class ManageEdges : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit ManageEdges(Map* map, QWidget *parent = nullptr);
    ~ManageEdges();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_add_button_clicked();
    void on_remove_button_clicked();
private:
    void update_table();
    Ui::ManageEdges *ui;    //ManageEdges object for GUI
    Map* _map;              //Map class object
};

/*****************************************************************
 * ManageEdges Class
 * ______________________________________________________________
 *  The class 'ManageEdges' is used for manage the edges
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* ManageEdges(Map* map, QWidget *parent = nullptr);
*   Constructor; default constructor for a ManageEdges object for qtwidgets,
*   Parameters: Map* map, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~ManageEdges();
*   Destructor; default Deconstructor for a ManageEdges object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the ManageEdges.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *  void on_add_button_clicked();
 *   Mutator: Add an edge to _map->_edges
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_remove_button_clicked();
 *   Mutator: Remove an edge to _map->_edges
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void update_table();
 *   Mutator: updates the table that displays
 *            the edges.
 *   Parameters: None
 *   Return: None
 *****************************************/


#endif // MANAGE_EDGES_H
