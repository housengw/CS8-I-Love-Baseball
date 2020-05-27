#ifndef UPDATE_PASSWORD_H
#define UPDATE_PASSWORD_H
#include "../../src/baseball_project/constants.h"
#include "../../src/baseball_project/helpers.h"
#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui
{
    class UpdatePassword;
}

class UpdatePassword : public QDialog
{
    Q_OBJECT

  public:
    explicit UpdatePassword(string password, QWidget *parent = nullptr);
    ~UpdatePassword();

  private slots:
    void on_cancel_button_clicked();

    void on_confirm_button_clicked();

  private:
    Ui::UpdatePassword *ui;
    string _password;
};

#endif // UPDATE_PASSWORD_H
