#ifndef TRIP_PLANNER_H
#define TRIP_PLANNER_H
#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>


namespace Ui {
class TripPlanner;
}

class TripPlanner : public QDialog
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit TripPlanner(Map* map, QWidget *parent = nullptr);
    ~TripPlanner();

    /**************
     ** ACCESSORS **
     **************/
    void update_table();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_national_stadiums_button_clicked();

    void on_american_stadium_button_clicked();

    void on_custom_stadium_button_clicked();

    void on_add_button_clicked();

    void on_remove_button_clicked();

    void on_all_stadium_button_clicked();

private:
    Ui::TripPlanner *ui;                 // TripPlanner object for GUI
    Map* _map;                           // Map class object
    StadiumContainer _selected_stadiums; // Selected stadiums container
};

#endif // TRIP_PLANNER_H


/*****************************************************************
 * TripPlanner Class
 * ______________________________________________________________
 *  The class 'TripPlanner' is used to plan a trip and display on the map.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* TripPlanner (Map* map, QWidget *parent = nullptr);
*   Constructor; default constructor for a TripPlanner object for qtwidgets,
*   Parameters: Map* map,parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~TripPlanner();
*   Destructor; default Deconstructor for a TripPlanner object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the TripPlanner.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *   void on_national_stadiums_button_clicked();
 *   Mutator: It will create a trip to national stadiums
 *   Parameters: None
 *   Return: close window
 *****************************************/
/*******************************************
 *   void on_american_stadium_button_clicked();
 *   Mutator: It will create a trip to american stadiums
 *   Parameters: None
 *   Return: close window
 *****************************************/
/*******************************************
 *   void on_custom_stadium_button_clicked();
 *   Mutator: It will create a trip to custom stadiums
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *   void on_add_button_clicked();
 *   Mutator: It will add another stadium to the custom trip
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *   void on_remove_button_clicked();
 *   Mutator: It will remove stadium from custom trip
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *   void on_all_stadium_button_clicked();
 *   Mutator: It will create a trip to all stadiums
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/*******************************************
 * void update_table ();
 *   Accessor: It will update table of visited stadiums
 *   Parameters: none
 *   Return: None
 *****************************************/
