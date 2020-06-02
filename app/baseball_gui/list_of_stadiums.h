#ifndef LIST_OF_STADIUMS_H
#define LIST_OF_STADIUMS_H

#include <QDialog>

#include "../../src/baseball_project/map.h"

namespace Ui {
class list_of_Stadiums;
}

class list_of_Stadiums : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit list_of_Stadiums(Map* map, QWidget *parent = nullptr);
    ~list_of_Stadiums();


    /***************
     ** ACCESSORS **
     ***************/
    void display_List (vector<Stadium> list);

    void update_list ();

    int stadium_surface ();

private slots:

    /**************
     ** MUTATORS **
     **************/
    void on_american_stateChanged(int arg1);

    void on_national_stateChanged(int arg1);

    void on_grass_stateChanged(int arg1);

    void on_turf_stateChanged(int arg1);

    void on_teamName_clicked();

    void on_stadiumName_clicked();

    void on_dateOpened_clicked();

    void on_access_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::list_of_Stadiums *ui;      // list_of_Stadiums object for GUI
    Map* _map;                     // Map class object
    vector<Stadium> _list;         // vector of stadiums


};

#endif // LIST_OF_STADIUMS_H


/*****************************************************************
 * list_of_Stadiums Class
 * ______________________________________________________________
 *  The class 'list_of_Stadiums' is used for display the information of
 *  stadiums and actions such as sorting the list or accessing specific
 *  stadiums.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* list_of_Stadiums (Map* map, QWidget *parent = nullptr);
*   Constructor; default constructor for a list_of_Stadiums object for qtwidgets,
*   Parameters: Map* map, parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~list_of_Stadiums();
*   Destructor; default Deconstructor for a list_of_Stadiums object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the list_of_Stadiums.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/*******************************************
 * void display_List (vector<Stadium> list);
 *   Accessor: It will display the list of stadiums and their information
 *   Parameters: vector<Stadium> list //IN  list of stadiums
 *   Return: None
 *****************************************/
/*******************************************
 * void update_list ();
 *   Accessor: It will update the table of stadiums
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 * int stadium_surface ();
 *   Accessor: It will process the GUI selected option
 *   for sorting the stadiums base on their surface
 *   Parameters: None
 *   Return: the option selected else return 0
 *****************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_american_stateChanged(int arg1);
 *   Mutator: It will call update list to display only american stadiums
 *   Parameters: int arg1
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_national_stateChanged(int arg1);
 *   Mutator: It will call update list to display only national stadiums
 *   Parameters: int arg1
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_grass_stateChanged(int arg1);
 *   Mutator: It will call update list to display only stadiums with grass surface
 *   Parameters: int arg1
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_turf_stateChanged(int arg1);
 *   Mutator: It will call update list to display only stadiums with turf surface
 *   Parameters: int arg1
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_teamName_clicked();
 *   Mutator: It will sort stadiums by team name and display the list
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_stadiumName_clicked();
 *   Mutator: It will sort stadiums by stadium name and display the list
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_dateOpened_clicked();
 *   Mutator: It will sort stadiums by thier opened date and display the list
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_access_button_clicked();
 *   Mutator: It will display a list of stadiums to let the choose
 *   the stadium to access
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_pushButton_clicked();
 *   Mutator: It will display souvenir window
 *   Parameters: None
 *   Return: None
 *****************************************/
