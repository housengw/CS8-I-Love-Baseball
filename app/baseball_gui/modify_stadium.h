#ifndef MODIFY_STADIUM_H
#define MODIFY_STADIUM_H
#include "../../src/baseball_project/constants.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/sort_functions.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui
{
    class ModifyStadium;
}

class ModifyStadium : public QDialog
{
    Q_OBJECT

  public:
    explicit ModifyStadium(Map *map,
                           string stadium_name,
                           QWidget *parent = nullptr);
    ~ModifyStadium();

  private slots:
    void on_cancel_button_clicked();

    void on_confirm_button_clicked();

  private:
    Ui::ModifyStadium *ui;
    Map *_map;
    string _stadium_name;
};

#endif // MODIFY_STADIUM_H
