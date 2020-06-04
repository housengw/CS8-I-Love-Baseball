#ifndef MANAGE_EDGES_H
#define MANAGE_EDGES_H
#include "../../src/baseball_project/map.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ManageEdges;
}

class ManageEdges : public QDialog
{
    Q_OBJECT

public:
    explicit ManageEdges(Map* map, QWidget *parent = nullptr);
    ~ManageEdges();

private slots:
    void on_add_button_clicked();

    void on_remove_button_clicked();

private:
    void update_table();
    Ui::ManageEdges *ui;
    Map* _map;
};

#endif // MANAGE_EDGES_H
