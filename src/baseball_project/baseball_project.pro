TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    stadium.cpp \
    date.cpp \
    helpers.cpp \
    address.cpp \
    stadium_container.cpp

HEADERS += \
    constants.h \
    stadium.h \
    address.h \
    date.h \
    helpers.h \
    stadium_container.h
