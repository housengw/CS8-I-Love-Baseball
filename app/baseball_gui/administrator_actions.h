#ifndef ADMINISTRATOR_ACTIONS_H
#define ADMINISTRATOR_ACTIONS_H
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/constants.h"
#include <QDialog>
#include <QMessageBox>


namespace Ui {
class AdministratorActions;
}

class AdministratorActions : public QDialog
{
    Q_OBJECT

public:
    explicit AdministratorActions(Map* map, QWidget *parent = nullptr);
    ~AdministratorActions();

private:
    Ui::AdministratorActions *ui;
    Map* _map;
};

#endif // ADMINISTRATOR_ACTIONS_H
