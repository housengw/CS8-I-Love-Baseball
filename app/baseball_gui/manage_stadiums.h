#ifndef MANAGE_STADIUMS_H
#define MANAGE_STADIUMS_H
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/sort_functions.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui
{
    class ManageStadiums;
}

class ManageStadiums : public QDialog
{
    Q_OBJECT

  public:
    explicit ManageStadiums(Map *map, QWidget *parent = nullptr);
    ~ManageStadiums();

  private slots:
    void on_modify_button_clicked();

  private:
    Ui::ManageStadiums *ui;
    Map *_map;
};

#endif // MANAGE_STADIUMS_H
