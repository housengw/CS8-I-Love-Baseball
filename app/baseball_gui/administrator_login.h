#ifndef ADMINISTRATOR_LOGIN_H
#define ADMINISTRATOR_LOGIN_H
#include "../../src/baseball_project/constants.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui
{
class AdministratorLogin;
}

class AdministratorLogin : public QDialog
{
    Q_OBJECT

  public:
    explicit AdministratorLogin(Map *map, QWidget *parent = nullptr);
    ~AdministratorLogin();

  private slots:
    void on_cancel_button_clicked();

    void on_login_button_clicked();

    void on_update_password_button_clicked();

private:
    Ui::AdministratorLogin *ui;
    Map* _map;
    string _password;
};

#endif // ADMINISTRATOR_LOGIN_H
