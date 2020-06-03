#-------------------------------------------------
#
# Project created by QtCreator 2020-04-23T11:19:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = baseball_gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    ../../src/baseball_project/souvenirs_container.cpp \
    buy_souvenir.cpp \
        main.cpp \
        mainwindow.cpp \
    modify_souvenir_list.cpp \
    mouse_event.cpp \
    ../../src/baseball_project/date.cpp \
    ../../src/baseball_project/edge_container.cpp \
    ../../src/baseball_project/edge.cpp \
    ../../src/baseball_project/helpers.cpp \
    ../../src/baseball_project/map.cpp \
    ../../src/baseball_project/point_container.cpp \
    ../../src/baseball_project/point.cpp \
    ../../src/baseball_project/save_load.cpp \
    ../../src/baseball_project/sort_functions.cpp \
    ../../src/baseball_project/stadium_container.cpp \
    ../../src/baseball_project/stadium.cpp \
    purchase_list.cpp \
    view_distances.cpp \
    list_of_stadiums.cpp \
    administrator_login.cpp \
    administrator_actions.cpp \
    manage_stadiums.cpp \
    modify_stadium.cpp \
    view_souvenir_list.cpp \
    update_password.cpp \
    add_stadium.cpp \
    trip_planner.cpp \
    ../../src/baseball_project/dijkstra.cpp \
    manage_edges.cpp

HEADERS += \
    ../../src/baseball_project/souvenirs_container.h \
    buy_souvenir.h \
        mainwindow.h \
    modify_souvenir_list.h \
    mouse_event.h \
    ../../src/baseball_project/constants.h \
    ../../src/baseball_project/container.h \
    ../../src/baseball_project/date.h \
    ../../src/baseball_project/edge_container.h \
    ../../src/baseball_project/edge.h \
    ../../src/baseball_project/helpers.h \
    ../../src/baseball_project/map.h \
    ../../src/baseball_project/point_container.h \
    ../../src/baseball_project/point.h \
    ../../src/baseball_project/save_load.h \
    ../../src/baseball_project/sort_functions.h \
    ../../src/baseball_project/stadium_container.h \
    ../../src/baseball_project/stadium.h \
    purchase_list.h \
    view_distances.h \
    list_of_stadiums.h \
    administrator_login.h \
    administrator_actions.h \
    manage_stadiums.h \
    modify_stadium.h \
    view_souvenir_list.h \
    update_password.h \
    add_stadium.h \
    trip_planner.h \
    ../../src/baseball_project/dijkstra.h \
    manage_edges.h


FORMS += \
    buy_souvenir.ui \
        mainwindow.ui \
    modify_souvenir_list.ui \
    purchase_list.ui \
    view_distances.ui \
    list_of_stadiums.ui \
    view_souvenir_list.ui \
    administrator_login.ui \
    administrator_actions.ui \
    manage_stadiums.ui \
    modify_stadium.ui \
    update_password.ui \
    add_stadium.ui \
    trip_planner.ui \
    manage_edges.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  baseball_gui.qrc

DISTFILES += \
  images/map.jpg \
    Images/Stadiums.png \
    ../../src/baseball_project/baseball_project.pro.user
