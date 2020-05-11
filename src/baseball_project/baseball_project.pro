TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    stadium.cpp \
    date.cpp \
    helpers.cpp \
    stadium_container.cpp \
    save_load.cpp \
    sort_functions.cpp \
    map.cpp \
    edge.cpp \
    edge_container.cpp \
    point.cpp \
    point_container.cpp

HEADERS += \
    constants.h \
    stadium.h \
    date.h \
    helpers.h \
    stadium_container.h \
    save_load.h \
    sort_functions.h \
    map.h \
    edge.h \
    edge_container.h \
    point.h \
    point_container.h \
    container.h
