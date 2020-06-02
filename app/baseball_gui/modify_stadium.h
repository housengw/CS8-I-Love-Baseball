#ifndef MODIFY_STADIUM_H
#define MODIFY_STADIUM_H
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/constants.h"
#include "../../src/baseball_project/sort_functions.h"
#include <QDialog>
#include <QMessageBox>


namespace Ui {
class ModifyStadium;
}

class ModifyStadium : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     *****************************Fir***/
    explicit ModifyStadium(Map* map, string stadium_name, QWidget *parent = nullptr);
    ~ModifyStadium();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_cancel_button_clicked();

    void on_confirm_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::ModifyStadium *ui;         //ModifyStadium object for GUI
    Map* _map;                     // Map class object
    string _stadium_name;          //stadium name
};

#endif // MODIFY_STADIUM_H


/*****************************************************************
 * ModifyStadium Class
 * ______________________________________________________________
 *  The class 'ModifyStadium' is used to modify stadiums.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* ModifyStadium (Map* map,string staduim_name, QWidget *parent = nullptr);
*   Constructor; default constructor for a ModifyStadium object for qtwidgets,
*   Parameters: Map* map,string staduim_name, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~ModifyStadium();
*   Destructor; default Deconstructor for a ModifyStadium object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the ModifyStadium.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *   void on_cancel_button_clicked();
 *   Mutator: It will retrun->close
 *   Parameters: None
 *   Return: close window
 *****************************************/
/*******************************************
 *   void on_confirm_button_clicked();
 *   Mutator: It will let the administrator modify the stadium
 *   and process the input filled out
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *   void on_pushButton_clicked();
 *   Mutator: It will display souvenir information
 *   Parameters: None
 *   Return: None
 *****************************************/
