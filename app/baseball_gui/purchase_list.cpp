#include "purchase_list.h"
#include "ui_purchase_list.h"
#include "buy_souvenir.h"

/*****************************************************************
 * CONSTRUCTOR
 * purchase_list::purchase_list(Map* map, SouvenirsContainer* purchaseList, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes the private variables
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
purchase_list::purchase_list(Map* map,                         //IN - map class object
                             SouvenirsContainer* purchaseList, //IN - souvenir container
                             QWidget *parent) :                //IN - parent widget
    QDialog(parent),
    ui(new Ui::purchase_list),
    _map(map),
    list(purchaseList)
{
    ui->setupUi(this);

    ui->display_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->display_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->display_list->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->display_list->setUpdatesEnabled(true);
    ui->display_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->display_list->verticalHeader()->hide();
    ui->display_list->setColumnCount(3);

    QStringList tableHeaders;
    tableHeaders <<"quantity" << "souvenir name"<<"souvenir price";
    ui->display_list->setHorizontalHeaderLabels(tableHeaders);

    for(size_t i=0; i<_map->get_trip().size(); i++)
    {
        ui->visited_stadium->addItem(QString::fromStdString(_map->get_trip()[i].get_stadium_name()));
    }

    display_list();
}

/*****************************************************************
 * DESTRUCTOR
 * purchase_list::~purchase_list(): Class purchase_list
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
purchase_list::~purchase_list()
{
    delete ui;
}

/*****************************************************************
 *  Method void purchase_list::display_list ()
 *________________________________________________________________
 *  This function will display the list of sourvenir items
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     list displayed
 *****************************************************************/
void purchase_list::display_list()
{
    ui->display_list->setRowCount(list->size());

    for (int i = 0; i < list->size(); i++){
        ui->display_list->setItem(i, 0, new QTableWidgetItem (to_string((*list)[i]._quantity).c_str()));
        ui->display_list->setItem(i, 1, new QTableWidgetItem ((*list)[i]._name.c_str()));
        char number[20];
        sprintf(number, "%4.2f", (*list)[i]._price);
        string price = "$" + string(number);
        ui->display_list->setItem(i, 2, new QTableWidgetItem(price.c_str()));
    }
    ui->display_list->resizeRowsToContents();
}


/*****************************************************************
 *  Method void purchase_list::on_buy_clicked ()
 *________________________________________________________________
 *  This function will call buy_souvenir to let user buy souvenirs
 *  items
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Buy button clicked
 *
 *  POST-CONDITIONS
 *     update purchases and display list
 *****************************************************************/
void purchase_list::on_buy_clicked()
{
    string stadium_name = ui->visited_stadium->currentText().toStdString();
    if (stadium_name.empty()){
        QMessageBox::warning(this, "Error", "Plan a trip first");
        return;
    }
    buy_souvenir bs(_map, list, stadium_name);
    bs.setModal(true);
    bs.exec();
    display_list();
}
