#include "view_souvenir_list.h"
#include "ui_view_souvenir_list.h"
#include "administrator_login.h"

view_souvenir_list::view_souvenir_list(Map* map, Stadium* stadium, QWidget *parent) :
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

view_souvenir_list::~view_souvenir_list()
{
    delete ui;
}

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


void view_souvenir_list::on_pushButton_clicked()
{
    AdministratorLogin al(_map);
    al.setModal(true);
    al.exec();
}
