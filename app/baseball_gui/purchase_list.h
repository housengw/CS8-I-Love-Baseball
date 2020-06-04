#ifndef PURCHASE_LIST_H
#define PURCHASE_LIST_H

#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>


namespace Ui {
class purchase_list;
}

class purchase_list : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit purchase_list(Map* map, SouvenirsContainer* purchaseList, QWidget *parent = nullptr);
    ~purchase_list();

    /**************
     ** ACCESSORS **
     **************/
    void display_list();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_buy_clicked();

private:
    Ui::purchase_list *ui;      // purchase_list object for GUI
    Map* _map;                  // Map class object
    SouvenirsContainer* list;   // list of souvenirs
};

#endif // PURCHASE_LIST_H


/*****************************************************************
 * purchase_list Class
 * ______________________________________________________________
 *  The class 'purchase_list' is used to display the information
 *  for purchased souvenirs in a trip.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* purchase_list (Map* map, SouvenirsContainer* purchaseList, QWidget *parent = nullptr);
*   Constructor; default constructor for a purchase_list object for qtwidgets,
*   Parameters: Map* map,SouvenirsContainer* purchaseList, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~purchase_list();
*   Destructor; default Deconstructor for a purchase_list object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the purchase_list.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/*******************************************
 * void display_List ();
 *   Accessor: It will display the list of sourvenir items
 *   Parameters: None
 *   Return: None
 *****************************************/



/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_buy_clicked();
 *   Mutator: It will call buy_souvenir class to let
 *   user purchase souvenirs
 *   Parameters: None
 *   Return: None
 *****************************************/

