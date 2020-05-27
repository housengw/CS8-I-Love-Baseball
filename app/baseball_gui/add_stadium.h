#ifndef ADD_STADIUM_H
#define ADD_STADIUM_H
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/constants.h"
#include "../../src/baseball_project/sort_functions.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AddStadium;
}

class AddStadium : public QDialog
{
    Q_OBJECT

public:
    explicit AddStadium(Map* map, QWidget *parent = nullptr);
    ~AddStadium();

private slots:
    void on_add_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::AddStadium *ui;
    Map* _map;
};

#endif // ADD_STADIUM_H
