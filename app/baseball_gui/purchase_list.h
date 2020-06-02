#ifndef PURCHASE_LIST_H
#define PURCHASE_LIST_H

#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/souvenirs_container.h"
#include <QDialog>


namespace Ui {
class purchase_list;
}

class purchase_list : public QDialog
{
    Q_OBJECT

public:
    explicit purchase_list(Map* map, SouvenirsContainer* purchaseList, QWidget *parent = nullptr);
    ~purchase_list();

    void display_list();

private slots:
    void on_buy_clicked();

private:
    Ui::purchase_list *ui;
    Map* _map;
    SouvenirsContainer* list;
};

#endif // PURCHASE_LIST_H
