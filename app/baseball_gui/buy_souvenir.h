#ifndef BUY_SOUVENIR_H
#define BUY_SOUVENIR_H


#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/souvenirs_container.h"
#include <QDialog>

namespace Ui {
class buy_souvenir;
}

class buy_souvenir : public QDialog
{
    Q_OBJECT

public:
    explicit buy_souvenir(Map* map, SouvenirsContainer* purchaseList, string stadium_name, QWidget *parent = nullptr);
    ~buy_souvenir();

    void display_List();

private slots:
    void on_buy_clicked();

private:
    Ui::buy_souvenir *ui;
    Map* _map;
    SouvenirsContainer* _purchaseList;
    string _stadium_name;
    Stadium* _stadium;
};

#endif // BUY_SOUVENIR_H
