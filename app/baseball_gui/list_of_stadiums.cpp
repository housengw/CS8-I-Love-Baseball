#include "list_of_stadiums.h"
#include "ui_list_of_stadiums.h"

list_of_Stadiums::list_of_Stadiums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::list_of_Stadiums)
{
    ui->setupUi(this);

    ui->display_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->display_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->display_list->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->display_list->setUpdatesEnabled(true);
    ui->display_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->display_list->verticalHeader()->hide();
    ui->display_list->setColumnCount(8);

    QStringList tableHeaders;
    tableHeaders <<"Stadium"<<"Team"<<"Street Adress"<<"City, State, Zip"
                <<"Box Office #" << "Date Opened" << "Capacity" << "Surface";
    ui->display_list->setHorizontalHeaderLabels(tableHeaders);
}

list_of_Stadiums::~list_of_Stadiums()
{
    delete ui;
}

void list_of_Stadiums::on_american_stateChanged(int arg1)
{
    update_list ();
}

void list_of_Stadiums::on_national_stateChanged(int arg1)
{
    update_list ();
}

void list_of_Stadiums::on_grass_stateChanged(int arg1)
{
    update_list ();
}

void list_of_Stadiums::on_turf_stateChanged(int arg1)
{
    update_list ();
}

void list_of_Stadiums::update_list ()
{

    _list._update_list (ui->american->QAbstractButton::isChecked(),
                        ui->national->QAbstractButton::isChecked(),
                        ui->grass->QAbstractButton::isChecked(),
                        ui->turf->QAbstractButton::isChecked());
}

void list_of_Stadiums::on_teamName_clicked()
{
    display_List (_list.sorted_TeamName());
}

void list_of_Stadiums::on_stadiumName_clicked()
{
    display_List (_list.sorted_StadiumName());
}

void list_of_Stadiums::on_dateOpened_clicked()
{
    display_List (_list.sorted_DateOpened());
}

void list_of_Stadiums::display_List (vector<Stadium> list)
{
    ui->display_list->setRowCount(list.size());
    vector<Stadium> ::iterator _it;
    _it = list.begin();
    for (size_t i = 0; i < list.size(); i++){
        ui->display_list->setItem(i, 0, new QTableWidgetItem (_it->get_stadium_name().c_str()));
        ui->display_list->setItem(i, 1, new QTableWidgetItem(_it->get_team_name().c_str()));
        ui->display_list->setItem(i, 2, new QTableWidgetItem(_it->get_address1().c_str()));
        ui->display_list->setItem(i, 3, new QTableWidgetItem(_it->get_address2().c_str()));
        ui->display_list->setItem(i, 4, new QTableWidgetItem(_it->get_phone_number().c_str()));
        ui->display_list->setItem(i, 5, new QTableWidgetItem(_it->get_date_opened().get_date().c_str()));
        ui->display_list->setItem(i, 6, new QTableWidgetItem(to_string (_it->get_capacity()).c_str()));
        ui->display_list->setItem(i, 7, new QTableWidgetItem(_it->get_surface().c_str()));
        _it++;
    }
}

