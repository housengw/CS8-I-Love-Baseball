#ifndef VIEW_SOUVENIR_LIST_H
#define VIEW_SOUVENIR_LIST_H

#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/stadium.h"
#include <QDialog>

namespace Ui
{
class view_souvenir_list;
}

class view_souvenir_list : public QDialog
{
    Q_OBJECT

  public:
    explicit view_souvenir_list(Map *map,
                                Stadium *stadium,
                                QWidget *parent = nullptr);
    ~view_souvenir_list();

    void display_List();

  private slots:
    void on_pushButton_clicked();

  private:
    Ui::view_souvenir_list *ui;
    Stadium *_stadium;
    Map *_map;
};

#endif // VIEW_SOUVENIR_LIST_H
