#include "list_of_stadiums.h"
#include "ui_list_of_stadiums.h"
#include "view_souvenir_list.h"

/*****************************************************************
 * CONSTRUCTOR
 * list_of_Stadiums::list_of_Stadiums(Map* map, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes the private variables and displat the table
 *  with stadium's information
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
list_of_Stadiums::list_of_Stadiums(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::list_of_Stadiums)
{
    ui->setupUi(this);
    _map = map;

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
    update_list();

    vector<Stadium> stadium_v = sorted_by_stadium_name(_map->get_stadiums());
    for (size_t i=0; i<stadium_v.size(); i++){
        ui->stadium_cbox->addItem(QString::fromStdString(stadium_v[i].get_stadium_name()));
    }
    on_stadiumName_clicked();
}

/*****************************************************************
 * DESTRUCTOR
 * list_of_Stadiums::~list_of_Stadiums(): Class list_of_Stadiums
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
list_of_Stadiums::~list_of_Stadiums()
{
    delete ui;
}

/*****************************************************************
 *  Method void list_of_Stadiums::on_american_stateChanged(int arg1)
 *________________________________________________________________
 *  This function call update_list to display only american stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     american state changed
 *
 *  POST-CONDITIONS
 *     list updated
 *****************************************************************/
void list_of_Stadiums::on_american_stateChanged(int arg1)
{
    update_list ();
}

/*****************************************************************
 *  Method void list_of_Stadiums::on_national_stateChanged(int arg1)
 *________________________________________________________________
 *  This function call update_list to display only national stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     national state changed
 *
 *  POST-CONDITIONS
 *     list updated
 *****************************************************************/
void list_of_Stadiums::on_national_stateChanged(int arg1)
{
    update_list ();
}

/*****************************************************************
 *  Method void list_of_Stadiums::on_grass_stateChanged(int arg1)
 *________________________________________________________________
 *  This function call update_list to display only stadiums with grass surface
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     grass state changed
 *
 *  POST-CONDITIONS
 *     list updated
 *****************************************************************/
void list_of_Stadiums::on_grass_stateChanged(int arg1)
{
    update_list ();
}

/*****************************************************************
 *  Method void list_of_Stadiums::on_turf_stateChanged(int arg1)
 *________________________________________________________________
 *  This function call update_list to display only stadiums with turf surface
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     turf state changed
 *
 *  POST-CONDITIONS
 *     list updated
 *****************************************************************/
void list_of_Stadiums::on_turf_stateChanged(int arg1)
{
    update_list ();
}

/*****************************************************************
 *  Method void list_of_Stadiums::update_list()
 *________________________________________________________________
 *  This function will update_list and display the list base on user's
 *  choices
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Sort and options states changed
 *
 *  POST-CONDITIONS
 *     list updated and displayed
 *****************************************************************/
void list_of_Stadiums::update_list ()
{
    StadiumContainer stadiums;
    stadiums = _map->get_stadiums();

    if (ui->american->QAbstractButton::isChecked() && !ui->national->QAbstractButton::isChecked()) {
        stadiums = stadiums.get_american_stadiums();
        _list = vectorize(stadiums);
    }
    else if (!ui->american->QAbstractButton::isChecked() && ui->national->QAbstractButton::isChecked()) {
        stadiums = stadiums.get_national_stadiums();
        _list = vectorize(stadiums);
    }
    else if (ui->american->QAbstractButton::isChecked() && ui->national->QAbstractButton::isChecked()) {
        _list = vectorize(stadiums);
    }

    if (stadium_surface() == 1) {
        stadiums = stadiums.get_stadiums_turf_surface();
        _list = vectorize(stadiums);
    }

    else if (stadium_surface() == 2) {
        stadiums = stadiums.get_stadiums_grass_surface();
        _list = vectorize(stadiums);
    }
}

/*****************************************************************
 *  Method void list_of_Stadiums::on_teamName_clicked()
 *________________________________________________________________
 *  This function will sort the stadiums base on team name
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Team Name button clicked
 *
 *  POST-CONDITIONS
 *     list sorted and displayed
 *****************************************************************/
void list_of_Stadiums::on_teamName_clicked()
{
    vector<Stadium> temp_list (_list);
    sort_by_team_name (temp_list);
    display_List (temp_list);
}

/*****************************************************************
 *  Method void list_of_Stadiums::on_stadiumName_clicked()
 *________________________________________________________________
 *  This function will sort the stadiums base on stadium name
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Stadium Name button clicked
 *
 *  POST-CONDITIONS
 *     list sorted and displayed
 *****************************************************************/
void list_of_Stadiums::on_stadiumName_clicked()
{
    vector<Stadium> temp_list (_list);
    sort_by_stadium_name (temp_list);
    display_List (temp_list);
}

/*****************************************************************
 *  Method void list_of_Stadiums::on_dateOpened_clicked()
 *________________________________________________________________
 *  This function will sort the stadiums base on their opened date
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Opened date button clicked
 *
 *  POST-CONDITIONS
 *     list sorted and displayed
 *****************************************************************/
void list_of_Stadiums::on_dateOpened_clicked()
{
    vector<Stadium> temp_list (_list);
    sort_by_opened_date (temp_list);
    display_List (temp_list);
}

/*****************************************************************
 *  Method void list_of_Stadiums::display_List (vector<Stadium> list)
 *________________________________________________________________
 *  This function will display the stadiums information in a table
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     list displayed
 *****************************************************************/
void list_of_Stadiums::display_List (vector<Stadium> list)
{
    ui->display_list->setRowCount(list.size());

    vector<Stadium> ::iterator _it;
    _it = list.begin();
    for (int i = 0; i < list.size(); i++){
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
    ui->display_list->resizeRowsToContents();
}

/*****************************************************************
 *  Method int list_of_Stadiums::stadium_surface ()
 *________________________________________________________________
 *  This function will update the stadium surface option
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Stadium surface state changed
 *
 *  POST-CONDITIONS
 *     return the option selected
 *****************************************************************/
int list_of_Stadiums::stadium_surface ()
{
    if (!ui->grass->QAbstractButton::isChecked() && ui->turf->QAbstractButton::isChecked()) {
        return 1;
    }
    else if (ui->grass->QAbstractButton::isChecked() && !ui->turf->QAbstractButton::isChecked()) {
        return 2;
    }
    return 0;
}


/*****************************************************************
 *  Method void list_of_Stadiums::on_access_button_clicked()
 *________________________________________________________________
 *  This function will display list of stadiums option to access them
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Access button clicked
 *
 *  POST-CONDITIONS
 *     none
 *****************************************************************/
void list_of_Stadiums::on_access_button_clicked()
{
    ui->display_list->setRowCount(1);
    string stadium_name = ui->stadium_cbox->currentText().toStdString();
    Stadium stadium = _map->get_stadiums().get_stadium(stadium_name);
    ui->display_list->setItem(0, 0, new QTableWidgetItem (stadium.get_stadium_name().c_str()));
    ui->display_list->setItem(0, 1, new QTableWidgetItem(stadium.get_team_name().c_str()));
    ui->display_list->setItem(0, 2, new QTableWidgetItem(stadium.get_address1().c_str()));
    ui->display_list->setItem(0, 3, new QTableWidgetItem(stadium.get_address2().c_str()));
    ui->display_list->setItem(0, 4, new QTableWidgetItem(stadium.get_phone_number().c_str()));
    ui->display_list->setItem(0, 5, new QTableWidgetItem(stadium.get_date_opened().get_date().c_str()));
    ui->display_list->setItem(0, 6, new QTableWidgetItem(to_string(stadium.get_capacity()).c_str()));
    ui->display_list->setItem(0, 7, new QTableWidgetItem(stadium.get_surface().c_str()));
    ui->display_list->resizeRowsToContents();
}

/*****************************************************************
 *  Method void list_of_Stadiums::on_pushButton_clicked()
 *________________________________________________________________
 *  This function will display souvenir window to modify and view souvenir
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     button clicked
 *
 *  POST-CONDITIONS
 *     none
 *****************************************************************/
void list_of_Stadiums::on_pushButton_clicked()
{
    string stadium_name = ui->stadium_cbox->currentText().toStdString();
    Stadium stadium = _map->get_stadiums().get_stadium(stadium_name);

    view_souvenir_list souvenirList(_map, &stadium);

    souvenirList.setModal(true);
    souvenirList.exec();
}
