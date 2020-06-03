#include "administrator_actions.h"
#include "ui_administrator_actions.h"
#include "manage_stadiums.h"
#include "add_stadium.h"

/*****************************************************************
 * CONSTRUCTOR
 * AdministratorActions::AdministratorActions(Map* map, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes the private variables
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
AdministratorActions::AdministratorActions(Map* map,            //IN - map class
                                           QWidget *parent) :   //IN - parent of the mainwindow
    QDialog(parent),
    ui(new Ui::AdministratorActions)
{
    ui->setupUi(this);
    _map = map;
}

/*****************************************************************
 * DESTRUCTOR
 * AdministratorActions::~AdministratorActions(): Class AdministratorActions
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
AdministratorActions::~AdministratorActions()
{
    delete ui;
}

/*****************************************************************
 *  Method void AdministratorActions::on_manage_stadiums_button_clicked()
 *________________________________________________________________
 *  This function creates an object of ManageStadiums class to let the
 *  administrator modify the stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     manage stadiums button clicked
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
void AdministratorActions::on_manage_stadiums_button_clicked()
{
    ManageStadiums ms(_map);
    ms.setModal(true);
    ms.exec();
}

/*****************************************************************
 *  Method void AdministratorActions::on_add_stadium_button_clicked()
 *________________________________________________________________
 *  This function creates an object of AddStadium class to let the
 *  administrator add new stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     add button clicked
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
void AdministratorActions::on_add_stadium_button_clicked()
{
    AddStadium as(_map);
    as.setModal(true);
    as.exec();
}
