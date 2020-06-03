#include "buy_souvenir.h"
#include "ui_buy_souvenir.h"

/*****************************************************************
 * CONSTRUCTOR
 * buy_souvenir::buy_souvenir(Map* map, SouvenirsContainer* purchaseList, string stadium_name, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes the private variables and display list of
 *  souvenir items
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
buy_souvenir::buy_souvenir(Map* map,                          //IN - map class object
                           SouvenirsContainer* purchaseList,  //IN - souvenir container
                           string stadium_name,               //IN - stadium selected
                           QWidget *parent) :                 //IN - parent widget
    QDialog(parent),
    ui(new Ui::buy_souvenir),
    _map(map),
    _purchaseList(purchaseList),
    _stadium_name(stadium_name)
{
    ui->setupUi(this);

    _stadium = &(_map->get_stadiums().get_stadium(_stadium_name));

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

    for(int i = 0; i < _stadium->get_souvenir_list().size(); i++)
    {
        ui->comboBox->addItem(QString::fromStdString(_stadium->get_souvenir_list().at(i)._name));
    }
}

/*****************************************************************
 * DESTRUCTOR
 * buy_souvenir::~buy_souvenir(): Class buy_souvenir
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
buy_souvenir::~buy_souvenir()
{
    delete ui;
}

/*****************************************************************
 *  Method void buy_souvenir::display_List ()
 *________________________________________________________________
 *  This function will display the list of purchased sourvenir items
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     list displayed
 *****************************************************************/
void buy_souvenir::display_List()
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
 *  Method void buy_souvenir::on_buy_clicked ()
 *________________________________________________________________
 *  This function will let user to buy souvenirs items and display them
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Buy button clicked
 *
 *  POST-CONDITIONS
 *     update purchases, display list and close window
 *****************************************************************/
void buy_souvenir::on_buy_clicked()
{
    if(_stadium->get_souvenir_list().empty())
    {
        return;
    }

    int index = ui->comboBox->currentIndex();

    string newName;
    newName = _stadium->get_souvenir_list().at(index)._name +
            "(" + _stadium->get_stadium_name() + ")";

    souvenir boughtItem(newName, _stadium->get_souvenir_list().at(index)._price);

    _purchaseList->add(boughtItem);

    this->close();
}
