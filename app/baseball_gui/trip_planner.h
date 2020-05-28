#ifndef TRIP_PLANNER_H
#define TRIP_PLANNER_H
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/constants.h"
#include <QDialog>
#include <QMessageBox>


namespace Ui {
class TripPlanner;
}

class TripPlanner : public QDialog
{
    Q_OBJECT

public:
    explicit TripPlanner(Map* map, QWidget *parent = nullptr);
    ~TripPlanner();

    void update_table();

private slots:
    void on_national_stadiums_button_clicked();

    void on_american_stadium_button_clicked();

    void on_custom_stadium_button_clicked();

    void on_add_button_clicked();

    void on_remove_button_clicked();

private:
    Ui::TripPlanner *ui;
    Map* _map;
    StadiumContainer _selected_stadiums;
};

#endif // TRIP_PLANNER_H
