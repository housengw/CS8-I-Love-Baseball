#ifndef VIEW_DISTANCES_H
#define VIEW_DISTANCES_H
#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ViewDistances;
}

class ViewDistances : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit ViewDistances(Map* map, QWidget *parent = nullptr);
    ~ViewDistances();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_get_distance_button_clicked();

private:
    Ui::ViewDistances *ui;  // ViewDistances object for GUI
    Map* _map;              // Map class object
};

#endif // VIEW_DISTANCES_H


/*****************************************************************
 * ViewDistances Class
 * ______________________________________________________________
 *  The class 'ViewDistances' is used to let the user view the distances
 *  between stadiums
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* ViewDistances (Map* map, QWidget *parent = nullptr);
*   Constructor; default constructor for a ViewDistances object for qtwidgets,
*   Parameters:Map* map, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~ViewDistances ();
*   Destructor; default Deconstructor for a ViewDistances object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the ViewDistances.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_get_distance_button_clicked();
 *   Mutator: It will display the distance between stadiums
 *   Parameters: None
 *   Return: none
 *****************************************/
