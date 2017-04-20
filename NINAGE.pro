QT += core
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NINAGE.out
TEMPLATE = app

SOURCES += src/main.cpp
SOURCES += ./src/lib/ResourceManager/ResourceManager.cpp
SOURCES += ./src/MainWindow.cpp

HEADERS += ./src/MainWindow.h
