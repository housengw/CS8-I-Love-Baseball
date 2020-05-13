#ifndef VIEW_DISTANCES_H
#define VIEW_DISTANCES_H
#include "../../src/baseball_project/map.h"
#include "../../src/baseball_project/helpers.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ViewDistances;
}

class ViewDistances : public QDialog
{
    Q_OBJECT

public:
    explicit ViewDistances(Map* map, QWidget *parent = nullptr);
    ~ViewDistances();

private slots:
    void on_get_distance_button_clicked();

private:
    Ui::ViewDistances *ui;
    Map* _map;
};

#endif // VIEW_DISTANCES_H
