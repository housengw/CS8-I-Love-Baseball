#include "modify_souvenir_list.h"
#include "ui_modify_souvenir_list.h"

modify_souvenir_list::modify_souvenir_list(Map* map, string stadium_name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_souvenir_list),
    _stadium_name(stadium_name)
{
    ui->setupUi(this);
    _map = map;

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
        ui->index->addItem(QString::fromStdString(_stadium->get_souvenir_list().at(i)._name));
    }

    update_textBox();
}

modify_souvenir_list::~modify_souvenir_list()
{
    delete ui;
}

void modify_souvenir_list::display_List()
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

void modify_souvenir_list::clear_table()
{
    // Deselects all selected items
    ui->display_souvenirs->clearSelection();

    // Disconnect all signals from table widget ! important !
    ui->display_souvenirs->disconnect();

    // Remove all items
    ui->display_souvenirs->clearContents();

    // Set row count to 0 (remove rows)
    ui->display_souvenirs->setRowCount(0);
}

void modify_souvenir_list::update_textBox()
{
    if(_stadium->get_souvenir_list().empty())
    {
        return;
    }

    int index = ui->index->currentIndex();
    ui->name->setText(QString::fromStdString(_stadium->get_souvenir_list().at(index)._name));
    double price = _stadium->get_souvenir_list().at(index)._price;
    char number[20];
    sprintf(number, "%4.2f", price);
    ui->price->setText(QString::fromStdString(string(number)));
}

void modify_souvenir_list::on_index_currentIndexChanged(const QString &arg1)
{
    update_textBox();
}

void modify_souvenir_list::on_modify_clicked()
{
    if(_stadium->get_souvenir_list().empty())
    {
        return;
    }

    string newName;
    double newPrice;

    newName = ui->name->toPlainText().toStdString();
    newPrice = stod(ui->price->toPlainText().toStdString());

    int index = ui->index->currentIndex();

    _stadium->get_souvenir_list().at(index)._name = newName;
    _stadium->get_souvenir_list().at(index)._price = newPrice;

    clear_table();
    display_List();

    update_textBox();
}


void modify_souvenir_list::on_delete_2_clicked()
{
    if(_stadium->get_souvenir_list().empty())
    {
        return;
    }

    int index = ui->index->currentIndex();

    _stadium->get_souvenir_list().remove(index);

    clear_table();
    display_List();

    ui->index->removeItem(ui->index->currentIndex());

    update_textBox();
}

void modify_souvenir_list::on_add_clicked()
{
    string newName;
    double newPrice;

    newName = ui->name->toPlainText().toStdString();
    newPrice = stod(ui->price->toPlainText().toStdString());

    if(_stadium->get_souvenir_list().add(souvenir(newName, newPrice)))
    {
        ui->index->addItem(QString::fromStdString(newName));
    }

    clear_table();
    display_List();

    update_textBox();
}
