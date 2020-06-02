#include "manage_stadiums.h"
#include "ui_manage_stadiums.h"
#include "modify_stadium.h"

/*****************************************************************
 * CONSTRUCTOR
 * ManageStadiums::ManageStadiums(Map* map, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes the private variables to default values
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
ManageStadiums::ManageStadiums(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageStadiums)
{
    ui->setupUi(this);
    _map = map;

    vector<Stadium> stadium_v = sorted_by_stadium_name(_map->get_stadiums());
    for (size_t i=0; i<stadium_v.size(); i++){
        ui->stadium_cbox->addItem(QString::fromStdString(stadium_v[i].get_stadium_name()));
    }
}

/*****************************************************************
 * DESTRUCTOR
 * ManageStadiums::~ManageStadiums(): Class ManageStadiums
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
ManageStadiums::~ManageStadiums()
{
    delete ui;
}

/*****************************************************************
 *  Method void ManageStadiums::on_modify_button_clicked()
 *________________________________________________________________
 *  This function process the input and create a object for ModifyStadium
 *  class to modify the stadium selected
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     modify button clicked and stadium selected
 *
 *  POST-CONDITIONS
 *     stadium information modified
 *****************************************************************/
void ManageStadiums::on_modify_button_clicked()
{
    string stadium_name = ui->stadium_cbox->currentText().toStdString();
    ModifyStadium ms(_map, stadium_name);
    ms.setModal(true);
    ms.exec();
}
