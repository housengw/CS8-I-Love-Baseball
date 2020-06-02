#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../../src/baseball_project/map.h"
#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_Trip_clicked();
    void on_clear_trip_button_clicked();
    void update_map();
    void update_visited_stadiums_table();

    void plot_connections();
    void plot_trip();

    void on_view_distances_button_clicked();
    void on_display_list_clicked();
    void on_administrator_button_clicked();

    void Mouse_current_pos ();
    void Mouse_release ();


    void on_purchase_list_button_clicked();

private:
    Ui::MainWindow *ui;      // Main Window object for GUI
    QGraphicsScene *scene;   // QGraphicsScene object for stadium map
    Map* _map;               // Map class object
    SouvenirsContainer purchaseList;
};

#endif // MAINWINDOW_H

/*****************************************************************
 * MainWindow Class
 * ______________________________________________________________
 *  The class 'MainWindow' is used for processing input from the GUI
 *  and outputting map and its corresponding trips.
 *  It will also allow the user to display list of stadiums, modify them
 *  and find the distances between them.
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* MainWindow(QWidget *parent = nullptr);
*   Constructor; default constructor for a mainwindow object for qtwidgets,
*   Parameters: parent (QWidget) // IN - parent of the mainwindow,
*   Return: none
***************************************************************/
/****************************************************************
* ~MainWindow();
*   Destructor; default Deconstructor for a mainwindow object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the mainwindow.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 * void on_Trip_clicked();
 *   Mutator: It will call the TripPlanner class to create a plan a trip
 *            and update in the displayed map
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_clear_trip_button_clicked();
 *   Mutator: It will create the current trip from displayed map
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void update_map();
 *   Mutator: It will update the map to the last created trip and display it
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 * void update_visited_stadiums_table();
 *   Mutator: It will update the table of visited stadiums
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 * void plot_connections();
 *   Mutator: It will plot the connections between all stadiums
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 * void plot_trip();
 *   Mutator: It will plot the trip on the displayed map
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 * void on_view_distances_button_clicked();
 *   Mutator: It will call ViewDistance class to pop out a new
 *            window to allow viewing the distances between stadiums
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_display_list_clicked();
 *   Mutator: It will call list_of_stadiums class to display
 *   a table with all stadiums' information along with other features
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void on_administrator_button_clicked();
 *   Mutator: It will call AdministatorLogin class to display a
 *   window for administrator actions
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void Mouse_current_pos ();
 *   Mutator: It will set the current coordinated of the mouse on map
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void Mouse_release ();
 *   Mutator: It will track the mouse coordinates on the map
 *   Parameters: None
 *   Return: None
 *****************************************/
