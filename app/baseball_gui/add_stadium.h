#ifndef ADD_STADIUM_H
#define ADD_STADIUM_H
#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AddStadium;
}

class AddStadium : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit AddStadium(Map* map, QWidget *parent = nullptr);
    ~AddStadium();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_add_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::AddStadium *ui;   // AddStadium object for GUI
    Map* _map;            // Map class object
};

#endif // ADD_STADIUM_H

/*****************************************************************
 * AddStadium Class
 * ______________________________________________________________
 *  The class 'AddStadium' is used for processing input from the GUI
 *  and add new stadiums.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/

/****************************************************************
* AddStadium(Map* map, QWidget *parent = nullptr);
*   Constructor; default constructor for a AddStadium object for qtwidgets,
*   Parameters: Map* map, parent (QWidget)
*   Return: none
***************************************************************/

/****************************************************************
* ~AddStadium();
*   Destructor; default Deconstructor for a AddStadium object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the AddStadium.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_add_button_clicked();
 *   Mutator: It will process input information of new stadium and
 *   display any error for incorrect information
 *   Parameters: None
 *   Return: this->close()
 *****************************************/
/*******************************************
 *  void on_cancel_button_clicked();
 *   Mutator: It will return this->close()
 *   Parameters: None
 *   Return: close window
 *****************************************/
