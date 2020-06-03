#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mouse_event.h"
#include "view_distances.h"
#include "list_of_stadiums.h"
#include "administrator_login.h"
#include "trip_planner.h"
#include "purchase_list.h"
#include <QPixmap>      // header for images in GUI


/*****************************************************************
 * CONSTRUCTOR
 * MainWindow::MainWindow(QWidget *parent): Class MainWindow
 *________________________________________________________________
 *  This constructor initializes the map with connections between stadiums,
 *  and connect the mouse coordinates on map. It also create a table to display
 *  the list of visited stadiums for each trip.
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     Various options added to display list, create trip or administrator actions
 *****************************************************************/
MainWindow::MainWindow(QWidget *parent) :  //IN - parent of the mainwindow
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _map = new Map;
    ui->setupUi(this);
    scene = new QGraphicsScene();
    update_map();
    connect(ui->mouse_area, SIGNAL (Mouse_Pos()), this, SLOT (Mouse_current_pos ()));
    connect(ui->mouse_area, SIGNAL (Mouse_Release()), this, SLOT (Mouse_release ()));

    ui->visited_stadiums_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->visited_stadiums_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->visited_stadiums_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->visited_stadiums_table->setUpdatesEnabled(true);
    ui->visited_stadiums_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->visited_stadiums_table->verticalHeader()->hide();
    ui->visited_stadiums_table->setColumnCount(1);
    QStringList tableHeaders;
    tableHeaders <<"Stadium";
    ui->visited_stadiums_table->setHorizontalHeaderLabels(tableHeaders);

    purchaseList.clear_list();
}


/*****************************************************************
 * DESTRUCTOR
 * MainWindow::~MainWindow(): Class MainWindow
 *________________________________________________________________
 *  This deallocates any dynamically allocated memory
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     none
 *
 *  POST-CONDITIONS
 *     dynamic memory deallocated
 *****************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}


/*****************************************************************
 *  Method void MainWindow::update_map()
 *________________________________________________________________
 *  This function properly updates the map's view with the last trip
 *  as well the table of visited stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     GUI input filled out
 *
 *  POST-CONDITIONS
 *     Map displayed with trip or connections and table updated along with the
 *     total # of stadiums visited and distance of the last trip.
 *****************************************************************/
void MainWindow::update_map()
{
    QPixmap m (":/Images/Stadiums.png");

    m = m.scaled(ui->graphicsView->width(),ui->graphicsView->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    scene->addPixmap(m);

    ui->graphicsView->setScene(scene);

    plot_connections();
    plot_trip();
    update_visited_stadiums_table();

    ui->total_stadiums_text->setText(QString::fromStdString(to_string(_map->get_trip().size())));
    ui->total_distance_text->setText(QString::fromStdString(to_string(_map->get_cost())));
}

/*****************************************************************
 *  Method void MainWindow::update_visited_stadiums_table()
 *________________________________________________________________
 *  This function properly updates the table of visited stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     Table filled with visited stadiums
 *****************************************************************/
void MainWindow::update_visited_stadiums_table()
{
    ui->visited_stadiums_table->setRowCount(_map->get_trip().size());
    for (size_t i=0; i<_map->get_trip().size(); i++){
        ui->visited_stadiums_table->setItem(i, 0, new QTableWidgetItem(_map->get_trip()[i].get_stadium_name().c_str()));
    }
    ui->visited_stadiums_table->resizeRowsToContents();
}


/*****************************************************************
 *  Method void MainWindow::on_Trip_clicked()
 *________________________________________________________________
 *  This function creates a TripPlanner object and pass in the map to
 *  update the map with a new planned trip.
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Trip buttom clicked
 *
 *  POST-CONDITIONS
 *     Map updated with probably new trip
 *****************************************************************/
void MainWindow::on_Trip_clicked()
{
    purchaseList.clear_list();
    TripPlanner tp(_map);
    tp.setModal(true);
    tp.exec();
    update_map();
}


/*****************************************************************
 *  Method void MainWindow::on_clear_trip_button_clicked()
 *________________________________________________________________
 *  This function clears the last created trip and updates the map
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Clear Trip buttom clicked
 *
 *  POST-CONDITIONS
 *     Map updated with only connections between stadiums
 *****************************************************************/
void MainWindow::on_clear_trip_button_clicked()
{
    _map->set_trip(StadiumContainer());
    update_map();
    purchaseList.clear_list();
}

/*****************************************************************
 *  Method void MainWindow::plot_connections()
 *________________________________________________________________
 *  This function plot the connections between stadiums with black lines
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     Connections are plotted
 *****************************************************************/
void MainWindow::plot_connections()
{
    vector<Plottable> plottables;
    Point p1, p2;
    QLine l;
    plottables = _map->get_plottables();
    for (size_t i=0; i<plottables.size(); i++){
        p1 = plottables[i].p1;
        p2 = plottables[i].p2;
        l.setLine(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
        scene->addLine(l);
    }
    ui->graphicsView->setScene(scene);
}


/*****************************************************************
 *  Method void MainWindow::plot_trip()
 *________________________________________________________________
 *  This function plot the trio created with red color lines
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Trip created
 *
 *  POST-CONDITIONS
 *     Trip is plotted
 *****************************************************************/
void MainWindow::plot_trip()
{
    vector<Plottable> plottables;
    Point p1, p2;
    QLine l;
    plottables = _map->get_trip_plottables();
    for (size_t i=0; i<plottables.size(); i++){
        p1 = plottables[i].p1;
        p2 = plottables[i].p2;
        l.setLine(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
        scene->addLine(l, QPen(QBrush("red"), 4));
    }
    ui->graphicsView->setScene(scene);
}


/*****************************************************************
 *  Method void MainWindow::on_view_distances_button_clicked()
 *________________________________________________________________
 *  This function creates ViewDistances object and it display a new
 *  window to allow user to view the distances between stadiums
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     View distances button clicked
 *
 *  POST-CONDITIONS
 *     New window displayed and let user to modify it
 *****************************************************************/
void MainWindow::on_view_distances_button_clicked()
{
    ViewDistances vd(_map);
    vd.setModal(true);
    vd.exec();
}


/*****************************************************************
 *  Method void MainWindow::on_display_list_clicked()
 *________________________________________________________________
 *  This function creates list_of_Stadiums object and it display
 *  a table of all stadiums with their information and it also allow
 *  the user to sort the list or access to a specific stadium
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Display list button clicked
 *
 *  POST-CONDITIONS
 *     New window with a table displayed and let user to modify it
 *****************************************************************/
void MainWindow::on_display_list_clicked()
{
    list_of_Stadiums list(_map);
    list.setModal(true);
    list.exec();
}

/*****************************************************************
 *  Method void MainWindow::on_administrator_button_clicked()
 *________________________________________________________________
 *  This function creates AdministratorLogin object and it display
 *  a new window for administrator actions
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Administrator button clicked
 *
 *  POST-CONDITIONS
 *     New window displayed and let administrator to modify it
 *****************************************************************/
void MainWindow::on_administrator_button_clicked()
{
    AdministratorLogin al(_map);
    al.setModal(true);
    al.exec();
}


/*****************************************************************
 *  Method void MainWindow::Mouse_current_pos()
 *________________________________________________________________
 *  This function set the current position of the mouse
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Mouse is moved
 *
 *  POST-CONDITIONS
 *     Display the current location of mouse
 *****************************************************************/
void MainWindow::Mouse_current_pos()
{
  ui->current_pos->setText(
              QString ("X = %1, Y = %2").arg(ui->mouse_area->x).arg(ui->mouse_area->y));
}

/*****************************************************************
 *  Method void MainWindow::on_purchase_list_button_clicked()
 *________________________________________________________________
 *  This function call purchase_list class to let user purchase
 *  souvenirs during trip
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Purchase button clicked
 *
 *  POST-CONDITIONS
 *     Display new window and update purchases
 *****************************************************************/
void MainWindow::on_purchase_list_button_clicked()
{
    purchase_list pl(_map, &purchaseList);
    pl.setModal(true);
    pl.exec();
}

/*****************************************************************
 *  Method void MainWindow::Mouse_release()
 *________________________________________________________________
 *  This function gets the mouse last pressed location
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     Mouse is released
 *
 *  POST-CONDITIONS
 *     Display the position released
 *****************************************************************/
void MainWindow::Mouse_release()
{
    ui->location_pressed->setText(QString ("X = %1, Y = %2").arg(ui->mouse_area->x).arg(ui->mouse_area->y));
}
