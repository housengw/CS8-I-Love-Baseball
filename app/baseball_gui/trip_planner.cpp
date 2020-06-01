#include "trip_planner.h"
#include "ui_trip_planner.h"

TripPlanner::TripPlanner(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripPlanner)
{
    ui->setupUi(this);
    _map = map;

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setUpdatesEnabled(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setColumnCount(1);

    QStringList tableHeaders;
    tableHeaders <<"Stadium";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeaders);

    vector<Stadium> stadium_v = sorted_by_stadium_name(_map->get_stadiums());
    for (size_t i=0; i<stadium_v.size(); i++){
        ui->comboBox->addItem(QString::fromStdString(stadium_v[i].get_stadium_name()));
        ui->to_combo_box->addItem(QString::fromStdString(stadium_v[i].get_stadium_name()));
    }
    update_table();
}

TripPlanner::~TripPlanner()
{
    delete ui;
}

void TripPlanner::update_table(){
    ui->tableWidget->setRowCount(_selected_stadiums.size());
    for (int i=0; i<_selected_stadiums.size(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(_selected_stadiums[i].get_stadium_name().c_str()));
    }
    ui->tableWidget->resizeRowsToContents();
}

void TripPlanner::on_national_stadiums_button_clicked()
{
    StadiumContainer selection, trip;
    Stadium start = _map->get_stadiums().get_stadium(ui->comboBox->currentText().toStdString());
    selection = _map->get_stadiums().get_national_stadiums();
    trip = _map->get_trip_greedy(selection, start);
    _map->set_trip(trip);
    this->close();
}

void TripPlanner::on_american_stadium_button_clicked()
{
    StadiumContainer selection, trip;
    Stadium start = _map->get_stadiums().get_stadium(ui->comboBox->currentText().toStdString());
    selection = _map->get_stadiums().get_american_stadiums();
    trip = _map->get_trip_greedy(selection, start);
    _map->set_trip(trip);
    this->close();
}

void TripPlanner::on_custom_stadium_button_clicked()
{
    if (_selected_stadiums.size() == 0) return;
    StadiumContainer selection, trip;
    Stadium start = _map->get_stadiums().get_stadium(ui->comboBox->currentText().toStdString());
    selection = _selected_stadiums;
    trip = _map->get_trip_greedy(selection, start);
    _map->set_trip(trip);
    this->close();
}

void TripPlanner::on_add_button_clicked()
{
    string stadium = ui->to_combo_box->currentText().toStdString();
    if (!_selected_stadiums.contains(stadium))
        _selected_stadiums.add(_map->get_stadiums().get_stadium(stadium));
    update_table();
}

void TripPlanner::on_remove_button_clicked()
{
    string stadium = ui->to_combo_box->currentText().toStdString();
    if (_selected_stadiums.contains(stadium)){
        _selected_stadiums.remove(_selected_stadiums.find(stadium));
    }
    update_table();
}


void TripPlanner::on_all_stadium_button_clicked()
{
    StadiumContainer selection, trip;
    Stadium start = _map->get_stadiums().get_stadium(ui->comboBox->currentText().toStdString());
    selection = _map->get_stadiums();
    trip = _map->get_trip_greedy(selection, start);
    _map->set_trip(trip);
    this->close();
}
