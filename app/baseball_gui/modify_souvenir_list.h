#ifndef MODIFY_SOUVENIR_LIST_H
#define MODIFY_SOUVENIR_LIST_H

#include <QDialog>
#include "../../src/baseball_project/stadium.h"
#include "../../src/baseball_project/map.h"
#include <QString>

namespace Ui {
class modify_souvenir_list;
}

class modify_souvenir_list : public QDialog
{
    Q_OBJECT

public:
    explicit modify_souvenir_list(Map* map, string staduim_name, QWidget *parent = nullptr);
    ~modify_souvenir_list();

    void display_List();
    void update_textBox();
    void clear_table();

private slots:

    void on_index_currentIndexChanged(const QString &arg1);

    void on_modify_clicked();

    void on_delete_2_clicked();


    void on_add_clicked();

private:
    Ui::modify_souvenir_list *ui;
    string _stadium_name;
    Map* _map;
    Stadium* _stadium;
};

#endif // MODIFY_SOUVENIR_LIST_H
