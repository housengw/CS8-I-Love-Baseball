#include "trip_planner.h"
#include "ui_trip_planner.h"

/*****************************************************************
 * CONSTRUCTOR
 * TripPlanner::TripPlanner(Map* map, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes variables to default values update table
 *  of visited stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
TripPlanner::TripPlanner(Map* map,           //IN - map class
                         QWidget *parent) :  //IN - parent of the mainwindow
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

/*****************************************************************
 * DESTRUCTOR
 * TripPlanner::~TripPlanner(): Class TripPlanner
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
TripPlanner::~TripPlanner()
{
    delete ui;
}

/*****************************************************************
 *  Method void TripPlanner::update_table()
 *________________________________________________________________
 *  This function properly updates the table of visited stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     selected stadiums are selected
 *
 *  POST-CONDITIONS
 *     selected stadiums are displayed in order
 *****************************************************************/
void TripPlanner::update_table()
{
    ui->tableWidget->setRowCount(_selected_stadiums.size());
    for (int i=0; i<_selected_stadiums.size(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(_selected_stadiums[i].get_stadium_name().c_str()));
    }
    ui->tableWidget->resizeRowsToContents();
}

/*****************************************************************
 *  Method void TripPlanner::on_national_stadiums_button_clicked()
 *________________________________________________________________
 *  This function creates a trip to all national stadiums from start stadium
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     selected stadiums and start stadium are selected
 *
 *  POST-CONDITIONS
 *     trip set and close window to display
 *****************************************************************/
void TripPlanner::on_national_stadiums_button_clicked()
{
    StadiumContainer selection, trip;
    Stadium start = _map->get_stadiums().get_stadium(ui->comboBox->currentText().toStdString());
    selection = _map->get_stadiums().get_national_stadiums();
    trip = _map->get_trip_greedy(selection, start);
    _map->set_trip(trip);
    this->close();
}

/*****************************************************************
 *  Method void TripPlanner::on_american_stadium_button_clicked()
 *________________________________________________________________
 *  This function creates a trip to all american stadiums from start stadium
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     selected stadiums and start stadium are selected
 *
 *  POST-CONDITIONS
 *     trip set and close window to display
 *****************************************************************/
void TripPlanner::on_american_stadium_button_clicked()
{
    StadiumContainer selection, trip;
    Stadium start = _map->get_stadiums().get_stadium(ui->comboBox->currentText().toStdString());
    selection = _map->get_stadiums().get_american_stadiums();
    trip = _map->get_trip_greedy(selection, start);
    _map->set_trip(trip);
    this->close();
}

/*****************************************************************
 *  Method void TripPlanner::on_custom_stadium_button_clicked()
 *________________________________________________________________
 *  This function creates a trip to custom stadiums from start stadium
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     selected stadiums and start stadium are selected
 *
 *  POST-CONDITIONS
 *     trip set and close window to display
 *****************************************************************/
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

/*****************************************************************
 *  Method void TripPlanner::on_all_stadium_button_clicked()
 *________________________________________________________________
 *  This function creates a trip to all stadiums from start stadium
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     all stadiums and start stadium are selected
 *
 *  POST-CONDITIONS
 *     trip set and close window to display
 *****************************************************************/
void TripPlanner::on_all_stadium_button_clicked()
{
    StadiumContainer selection, trip;
    Stadium start = _map->get_stadiums().get_stadium(ui->comboBox->currentText().toStdString());
    selection = _map->get_stadiums();
    trip = _map->get_trip_greedy(selection, start);
    _map->set_trip(trip);
    this->close();
}

/*****************************************************************
 *  Method void TripPlanner::on_add_button_clicked()
 *________________________________________________________________
 *  This function add another stadium to create trip
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     stadiums and start stadium are selected
 *
 *  POST-CONDITIONS
 *     stadium added and update table
 *****************************************************************/
void TripPlanner::on_add_button_clicked()
{
    string stadium = ui->to_combo_box->currentText().toStdString();
    if (!_selected_stadiums.contains(stadium))
        _selected_stadiums.add(_map->get_stadiums().get_stadium(stadium));
    update_table();
}

/*****************************************************************
 *  Method void TripPlanner::on_remove_button_clicked()
 *________________________________________________________________
 *  This function remove stadium
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     stadium is selected
 *
 *  POST-CONDITIONS
 *     stadium removed and update table
 *****************************************************************/
void TripPlanner::on_remove_button_clicked()
{
    string stadium = ui->to_combo_box->currentText().toStdString();
    if (_selected_stadiums.contains(stadium)){
        _selected_stadiums.remove(_selected_stadiums.find(stadium));
    }
    update_table();
}


