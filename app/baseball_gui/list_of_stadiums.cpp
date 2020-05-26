#include "list_of_stadiums.h"
#include "ui_list_of_stadiums.h"
#include "view_souvenir_list.h"

list_of_Stadiums::list_of_Stadiums(Map *map, QWidget *parent)
    : QDialog(parent), ui(new Ui::list_of_Stadiums)
{
    ui->setupUi(this);
    _map = map;

    ui->display_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->display_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->display_list->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->display_list->setUpdatesEnabled(true);
    ui->display_list->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);
    ui->display_list->verticalHeader()->hide();
    ui->display_list->setColumnCount(8);

    QStringList tableHeaders;
    tableHeaders << "Stadium"
                 << "Team"
                 << "Street Adress"
                 << "City, State, Zip"
                 << "Box Office #"
                 << "Date Opened"
                 << "Capacity"
                 << "Surface";
    ui->display_list->setHorizontalHeaderLabels(tableHeaders);
    update_list();

    vector<Stadium> stadium_v = sorted_by_stadium_name(_map->get_stadiums());
    for (size_t i = 0; i < stadium_v.size(); i++)
    {
        ui->stadium_cbox->addItem(
            QString::fromStdString(stadium_v[i].get_stadium_name()));
    }
}

list_of_Stadiums::~list_of_Stadiums()
{
    delete ui;
}

void list_of_Stadiums::on_american_stateChanged(int arg1)
{
    update_list();
}

void list_of_Stadiums::on_national_stateChanged(int arg1)
{
    update_list();
}

void list_of_Stadiums::on_grass_stateChanged(int arg1)
{
    update_list();
}

void list_of_Stadiums::on_turf_stateChanged(int arg1)
{
    update_list();
}

void list_of_Stadiums::update_list()
{
    StadiumContainer stadiums;
    stadiums = _map->get_stadiums();

    if (ui->american->QAbstractButton::isChecked() &&
        !ui->national->QAbstractButton::isChecked())
    {
        stadiums = stadiums.get_american_stadiums();
        _list = vectorize(stadiums);
        //        if (stadium_surface() == 1)
        //            _list = vectorize(stadiums.get_stadiums_turf_surface());
        //        else if (stadium_surface() == 2) {
        //            _list = vectorize(stadiums.get_stadiums_grass_surface());
        //        }
    }
    else if (!ui->american->QAbstractButton::isChecked() &&
             ui->national->QAbstractButton::isChecked())
    {
        stadiums = stadiums.get_national_stadiums();
        _list = vectorize(stadiums);
    }
    else if (ui->american->QAbstractButton::isChecked() &&
             ui->national->QAbstractButton::isChecked())
    {
        _list = vectorize(stadiums);
    }

    if (stadium_surface() == 1)
    {
        stadiums = stadiums.get_stadiums_turf_surface();
        _list = vectorize(stadiums);
    }

    else if (stadium_surface() == 2)
    {
        stadiums = stadiums.get_stadiums_grass_surface();
        _list = vectorize(stadiums);
    }
}

void list_of_Stadiums::on_teamName_clicked()
{
    vector<Stadium> temp_list(_list);
    sort_by_team_name(temp_list);
    display_List(temp_list);
}

void list_of_Stadiums::on_stadiumName_clicked()
{
    vector<Stadium> temp_list(_list);
    sort_by_stadium_name(temp_list);
    display_List(temp_list);
}

void list_of_Stadiums::on_dateOpened_clicked()
{
    vector<Stadium> temp_list(_list);
    sort_by_opened_date(temp_list);
    display_List(temp_list);
}

void list_of_Stadiums::display_List(vector<Stadium> list)
{
    ui->display_list->setRowCount(list.size());

    vector<Stadium>::iterator _it;
    _it = list.begin();
    for (int i = 0; i < list.size(); i++)
    {
        ui->display_list->setItem(
            i, 0, new QTableWidgetItem(_it->get_stadium_name().c_str()));

        ui->display_list->setItem(
            i, 1, new QTableWidgetItem(_it->get_team_name().c_str()));

        ui->display_list->setItem(
            i, 2, new QTableWidgetItem(_it->get_address1().c_str()));

        ui->display_list->setItem(
            i, 3, new QTableWidgetItem(_it->get_address2().c_str()));

        ui->display_list->setItem(
            i, 4, new QTableWidgetItem(_it->get_phone_number().c_str()));

        ui->display_list->setItem(
            i, 5,
            new QTableWidgetItem(_it->get_date_opened().get_date().c_str()));

        ui->display_list->setItem(
            i, 6, new QTableWidgetItem(to_string(_it->get_capacity()).c_str()));

        ui->display_list->setItem(
            i, 7, new QTableWidgetItem(_it->get_surface().c_str()));

        _it++;
    }
    ui->display_list->resizeRowsToContents();
}

int list_of_Stadiums::stadium_surface()
{
    if (!ui->grass->QAbstractButton::isChecked() &&
        ui->turf->QAbstractButton::isChecked())
    {
        return 1;
    }
    else if (ui->grass->QAbstractButton::isChecked() &&
             !ui->turf->QAbstractButton::isChecked())
    {
        return 2;
    }
    return 0;
}

void list_of_Stadiums::on_access_button_clicked()
{
    ui->display_list->setRowCount(1);

    string stadium_name = ui->stadium_cbox->currentText().toStdString();

    Stadium stadium = _map->get_stadiums().get_stadium(stadium_name);

    ui->display_list->setItem(
        0, 0, new QTableWidgetItem(stadium.get_stadium_name().c_str()));

    ui->display_list->setItem(
        0, 1, new QTableWidgetItem(stadium.get_team_name().c_str()));

    ui->display_list->setItem(
        0, 2, new QTableWidgetItem(stadium.get_address1().c_str()));

    ui->display_list->setItem(
        0, 3, new QTableWidgetItem(stadium.get_address2().c_str()));

    ui->display_list->setItem(
        0, 4, new QTableWidgetItem(stadium.get_phone_number().c_str()));

    ui->display_list->setItem(
        0, 5,
        new QTableWidgetItem(stadium.get_date_opened().get_date().c_str()));

    ui->display_list->setItem(
        0, 6, new QTableWidgetItem(to_string(stadium.get_capacity()).c_str()));

    ui->display_list->setItem(
        0, 7, new QTableWidgetItem(stadium.get_surface().c_str()));

    ui->display_list->resizeRowsToContents();
}

void list_of_Stadiums::on_pushButton_clicked()
{
    string stadium_name = ui->stadium_cbox->currentText().toStdString();
    Stadium stadium = _map->get_stadiums().get_stadium(stadium_name);

    view_souvenir_list souvenirList(_map, &stadium);

    souvenirList.setModal(true);
    souvenirList.exec();
}
