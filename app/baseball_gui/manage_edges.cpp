#include "manage_edges.h"
#include "ui_manage_edges.h"

ManageEdges::ManageEdges(Map* map, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageEdges)
{
    ui->setupUi(this);
    _map = map;

    ui->edges_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->edges_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->edges_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->edges_table->setUpdatesEnabled(true);
    ui->edges_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->edges_table->setColumnCount(3);
    QStringList tableHeaders;
    tableHeaders <<"From Stadium"<<"To Stadium"<<"Cost";
    ui->edges_table->setHorizontalHeaderLabels(tableHeaders);
    update_table();

    vector<Stadium> stadium_v = sorted_by_stadium_name(_map->get_stadiums());
    for (size_t i=0; i<stadium_v.size(); i++){
        ui->from_stadium_cbox->addItem(QString::fromStdString(stadium_v[i].get_stadium_name()));
        ui->to_stadium_cbox->addItem(QString::fromStdString(stadium_v[i].get_stadium_name()));
    }
}


void ManageEdges::update_table(){
    EdgeContainer ec = _map->get_edges();
    ui->edges_table->setRowCount(ec.size());
    for (size_t i=0; i<ec.size(); i++){
        ui->edges_table->setItem(i, 0, new QTableWidgetItem(ec[i].get_left_node().c_str()));
        ui->edges_table->setItem(i, 1, new QTableWidgetItem(ec[i].get_right_node().c_str()));
        ui->edges_table->setItem(i, 2, new QTableWidgetItem(to_string(ec[i].get_cost()).c_str()));
    }
}


ManageEdges::~ManageEdges()
{
    delete ui;
}

void ManageEdges::on_add_button_clicked()
{
    string from, to, cost;
    from = ui->from_stadium_cbox->currentText().toStdString();
    to = ui->to_stadium_cbox->currentText().toStdString();
    cost = ui->cost->toPlainText().toStdString();
    if (from == to){
        QMessageBox::warning(this, "Error", "Stadiums cannot be the same");
        return;
    }
    if (cost.empty() || !is_unsigned_int(cost)){
        QMessageBox::warning(this, "Error", "Invalid Cost");
        return;
    }
    if (_map->get_edges().connected(from, to)){
        QMessageBox::warning(this, "Error", "Stadiums already connected");
        return;
    }
    Edge e(from, to, stoi(cost));
    _map->add_edge(e);
    update_table();
    ui->cost->clear();
}

void ManageEdges::on_remove_button_clicked()
{
    if (_map->get_edges().size() == 0) return;
    string row;
    row = ui->row_to_remove->toPlainText().toStdString();
    if (row.empty() || !is_unsigned_int(row)){
        QMessageBox::warning(this, "Error", "Invalid row");
        return;
    }
    int row_int = stoi(row) - 1;
    if (row_int >= _map->get_edges().size() || row_int < 0){
        QMessageBox::warning(this, "Error", "Invalid row");
        return;
    }

    _map->get_edges().remove(row_int);
    update_table();
    ui->row_to_remove->clear();
}
