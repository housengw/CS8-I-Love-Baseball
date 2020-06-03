#include "modify_stadium.h"
#include "ui_modify_stadium.h"
#include "modify_souvenir_list.h"

/*****************************************************************
 * CONSTRUCTOR
 * ModifyStadium::ModifyStadium(Map* map, string stadium_name, QWidget *parent) :QDialog(parent)
 *________________________________________________________________
 *  This constructor initializes the private variables to default values
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
ModifyStadium::ModifyStadium(Map* map, string stadium_name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyStadium)
{
    ui->setupUi(this);
    _map = map;
    _stadium_name = stadium_name;
    Stadium stadium = _map->get_stadiums().get_stadium(_stadium_name);
    ui->stadium_name->setText(QString::fromStdString(_stadium_name));
    ui->team_name->setText(QString::fromStdString(stadium.get_team_name()));
    ui->capacity->setText(QString::fromStdString(std::to_string(stadium.get_capacity())));
    ui->phone_number->setText(QString::fromStdString(stadium.get_phone_number()));
    ui->date->setText(QString::fromStdString(stadium.get_date_opened().get_date()));
    ui->street->setText(QString::fromStdString(stadium.get_address1()));
    ui->city->setText(QString::fromStdString(stadium.get_address2()));
    ui->surface->addItem(QString::fromStdString(GRASS_SURFACE_NAME));
    ui->surface->addItem(QString::fromStdString(TURF_SURFACE_NAME));
    if (stadium.get_surface() == GRASS_SURFACE_NAME){
        ui->surface->setCurrentText(QString::fromStdString(GRASS_SURFACE_NAME));
    }
    else{
        ui->surface->setCurrentText(QString::fromStdString(TURF_SURFACE_NAME));
    }
}


/*****************************************************************
 * DESTRUCTOR
 * ModifyStadium::~ModifyStadium(): Class ModifyStadium
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
ModifyStadium::~ModifyStadium()
{
    delete ui;
}


/*****************************************************************
 *  Method void ModifyStadium::on_cancel_button_clicked()
 *________________________________________________________________
 *  This function returns this->close()
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     cancel button clicked
 *
 *  POST-CONDITIONS
 *     close window
 *****************************************************************/
void ModifyStadium::on_cancel_button_clicked()
{
    this->close();
}

/*****************************************************************
 *  Method void ModifyStadium::on_confirm_button_clicked()
 *________________________________________________________________
 *  This function process the input for a new stadium and display error
 *  message for incorrect input and update stadium
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     confirm button clicked and input filled out
 *
 *  POST-CONDITIONS
 *     stadium updated and close window
 *****************************************************************/
void ModifyStadium::on_confirm_button_clicked()
{
    string stadium_name, team_name, capacity, phone_number, date, street, city, surface;
    stadium_name = ui->stadium_name->toPlainText().toStdString();
    team_name = ui->team_name->toPlainText().toStdString();
    capacity = ui->capacity->toPlainText().toStdString();
    phone_number = ui->phone_number->toPlainText().toStdString();
    date = ui->date->toPlainText().toStdString();
    street = ui->street->toPlainText().toStdString();
    city = ui->city->toPlainText().toStdString();
    surface = ui->surface->currentText().toStdString();

    if (stadium_name.empty() || team_name.empty() || capacity.empty() ||
            phone_number.empty() || date.empty() || street.empty() ||
            city.empty()){
        QMessageBox::warning(this, "Error", "Empty field(s)");
        return;
    }
    if (!is_unsigned_int(capacity)){
        QMessageBox::warning(this, "Error", "Invalid Capacity");
        return;
    }
    if (!is_valid_date(date)){
        QMessageBox::warning(this, "Error", "Invalid Date");
        return;
    }

    Date d;
    d.set_whole(date);
    Stadium s(stadium_name, team_name, street, city, phone_number, d, stoi(capacity), surface);

    Stadium stadium = _map->get_stadiums().get_stadium(_stadium_name);
    s.get_souvenir_list() = stadium.get_souvenir_list();

    _map->update_stadium(_stadium_name, s);
    this->close();
}

/*****************************************************************
 *  Method void ModifyStadium::on_pushButton_clicked()
 *________________________________________________________________
 *  This function process the souvenir information
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     button clicked and stadium seleted
 *
 *  POST-CONDITIONS
 *     none
 *****************************************************************/
void ModifyStadium::on_pushButton_clicked()
{
    modify_souvenir_list souvenirList(_map, _stadium_name);

    souvenirList.setModal(true);
    souvenirList.exec();
}
