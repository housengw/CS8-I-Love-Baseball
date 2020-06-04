#ifndef BUY_SOUVENIR_H
#define BUY_SOUVENIR_H

#include "../../src/baseball_project/map.h"
#include <QDialog>

namespace Ui {
class buy_souvenir;
}

class buy_souvenir : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit buy_souvenir(Map* map, SouvenirsContainer* purchaseList, string stadium_name, QWidget *parent = nullptr);
    ~buy_souvenir();

    /**************
     ** ACCESSORS **
     **************/
    void display_List();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_buy_clicked();

private:
    Ui::buy_souvenir *ui;               // buy_souvenir object for GUI
    Map* _map;                          // Map class object
    SouvenirsContainer* _purchaseList;  // purchase list of souvenirs
    string _stadium_name;               // stadium name
    Stadium* _stadium;                  // pointer to stadium
};

#endif // BUY_SOUVENIR_H


/*****************************************************************
 * buy_souvenir Class
 * ______________________________________________________________
 *  The class 'buy_souvenir' is used to let user purchase souvenirs
 *  items for specific stadiums.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* buy_souvenir (Map* map, SouvenirsContainer* purchaseList, string stadium_name, QWidget *parent = nullptr);
*   Constructor; default constructor for a purchase_list object for qtwidgets,
*   Parameters: Map* map,SouvenirsContainer* purchaseList, string stadium_name, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~buy_souvenir();
*   Destructor; default Deconstructor for a buy_souvenir object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the buy_souvenir.
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
 *   Mutator: It will update the purchased items
 *   Parameters: None
 *   Return: None
 *****************************************/

