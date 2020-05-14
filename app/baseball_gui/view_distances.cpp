#include "view_distances.h"
#include "ui_view_distances.h"

ViewDistances::ViewDistances(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewDistances)
{
    ui->setupUi(this);
    _map = map;
    vector<Stadium> stadium_v = sorted_by_stadium_name(_map->get_stadiums());
    for (size_t i=0; i<stadium_v.size(); i++){
        ui->from_stadium_cbox->addItem(QString::fromStdString(stadium_v[i].get_stadium_name()));
        ui->to_stadium_cbox->addItem(QString::fromStdString(stadium_v[i].get_stadium_name()));
    }
}

ViewDistances::~ViewDistances()
{
    delete ui;
}

void ViewDistances::on_get_distance_button_clicked()
{
    string stadium_a, stadium_b;
    stadium_a = ui->from_stadium_cbox->currentText().toStdString();
    stadium_b = ui->to_stadium_cbox->currentText().toStdString();

    if (!_map->get_edges().connected(stadium_a, stadium_b)){
        QMessageBox::warning(this, "Error",
                             "Selected Stadiums are not connected");
        return;
    }

    int cost = _map->get_edges().get_cost(stadium_a, stadium_b);
    ui->distance_text_browser->setText(int_to_qstr(cost));
}
