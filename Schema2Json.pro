TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread

SOURCES += \
    src/SchemaJsonConv.cpp \
    test/SchemaJsonConv_Test.cpp

HEADERS += \
    src/SchemaJsonConv.h

### Apache
INCLUDEPATH += /usr/include/arrow
INCLUDEPATH += /usr/include/arrow-glib

LIBS += -larrow

### GTest
INCLUDEPATH += -I/usr/src/gtest
LIBS += -lgtest -L/usr/lib

