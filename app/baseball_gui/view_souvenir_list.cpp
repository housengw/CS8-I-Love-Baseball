#include "view_souvenir_list.h"
#include "ui_view_souvenir_list.h"
#include "administrator_login.h"

/*****************************************************************
 * CONSTRUCTOR
 * view_souvenir_list::view_souvenir_list(Map* map, Stadium* stadium, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes variables to default values and display the
 *  list of souvenir
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
view_souvenir_list::view_souvenir_list(Map* map,             //IN - map class
                                       Stadium* stadium,     //IN - stadium
                                       QWidget *parent) :    //IN - parent of the mainwindow
    QDialog(parent),
    ui(new Ui::view_souvenir_list),
    _stadium(stadium)
{
    ui->setupUi(this);
    _map = map;

    ui->display_souvenirs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->display_souvenirs->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->display_souvenirs->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->display_souvenirs->setUpdatesEnabled(true);
    ui->display_souvenirs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->display_souvenirs->verticalHeader()->hide();
    ui->display_souvenirs->setColumnCount(2);

    QStringList tableHeaders;
    tableHeaders <<"souvenir name"<<"souvenir price";
    ui->display_souvenirs->setHorizontalHeaderLabels(tableHeaders);

    display_List();

}

/*****************************************************************
 * DESTRUCTOR
 * view_souvenir_list::~view_souvenir_list(): Class view_souvenir_list
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
view_souvenir_list::~view_souvenir_list()
{
    delete ui;
}

/*****************************************************************
 *  Method void view_souvenir_list::display_List()
 *________________________________________________________________
 *  This function will display the souvenir information
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     display souvenir information
 *****************************************************************/
void view_souvenir_list::display_List()
{
    SouvenirsContainer* list = &(_stadium->get_souvenir_list());
    ui->display_souvenirs->setRowCount(list->size());

    for (int i = 0; i < list->size(); i++){
        ui->display_souvenirs->setItem(i, 0, new QTableWidgetItem ((*list)[i]._name.c_str()));
        char number[20];
        sprintf(number, "%4.2f", (*list)[i]._price);
        string price = "$" + string(number);
        ui->display_souvenirs->setItem(i, 1, new QTableWidgetItem(price.c_str()));
    }
    ui->display_souvenirs->resizeRowsToContents();
}


/*****************************************************************
 *  Method void view_souvenir_list::on_pushButton_clicked()
 *________________________________________________________________
 *  This function creates an AdministratorLogin object to let administrator
 *  modify the souvenir information
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     button clicked
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
void view_souvenir_list::on_pushButton_clicked()
{
    AdministratorLogin al(_map);
    al.setModal(true);
    al.exec();
}
