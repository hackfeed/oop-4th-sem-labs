TEMPLATE = app
TARGET = lab_04.exe
INCLUDEPATH += ./include

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += ./include/*
FORMS += ./meta/mainwindow.ui
SOURCES += ./src/*
DESTDIR = ./bin
OBJECTS_DIR = ./build
MOC_DIR = ./build
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
