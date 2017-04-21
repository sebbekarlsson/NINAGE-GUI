QT += core
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NINAGE.out
TEMPLATE = app

SOURCES += src/main.cpp

SOURCES += ./src/lib/ResourceManager/ResourceManager.h
SOURCES += ./src/lib/ResourceManager/ResourceManager.cpp

HEADERS += ./src/include/MainWindow.h
SOURCES += ./src/MainWindow.cpp

HEADERS += ./src/include/NewProjectWindow.h
SOURCES += ./src/NewProjectWindow.cpp
