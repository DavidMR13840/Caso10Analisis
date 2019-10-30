TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    matroidprocessor.h \
    matroid.h
QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp
