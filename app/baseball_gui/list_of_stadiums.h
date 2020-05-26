#ifndef LIST_OF_STADIUMS_H
#define LIST_OF_STADIUMS_H

#include <QDialog>

#include "../../src/baseball_project/map.h"

namespace Ui
{
class list_of_Stadiums;
}

class list_of_Stadiums : public QDialog
{
    Q_OBJECT

  public:
    explicit list_of_Stadiums(Map *map, QWidget *parent = nullptr);
    ~list_of_Stadiums();

    void display_List(vector<Stadium> list);

    void update_list();

    int stadium_surface();

  private slots:

    void on_american_stateChanged(int arg1);

    void on_national_stateChanged(int arg1);

    void on_grass_stateChanged(int arg1);

    void on_turf_stateChanged(int arg1);

    void on_teamName_clicked();

    void on_stadiumName_clicked();

    void on_dateOpened_clicked();

    void on_access_button_clicked();

  private:
    Ui::list_of_Stadiums *ui;
    Map *_map;
    vector<Stadium> _list;
};

#endif // LIST_OF_STADIUMS_H
