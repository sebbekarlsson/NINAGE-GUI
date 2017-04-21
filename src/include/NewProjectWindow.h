#ifndef NEWPROJECTWINDOW_H
#define NEWPROJECTWINDOW_H

#include <string>
#include <iostream>
#include <QtWidgets>
#include <QMainWindow>
#include <QTextEdit>
#include <QListWidget>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


class NewProjectWindow : public QMainWindow {
    Q_OBJECT

    public:
        NewProjectWindow();

        private slots:
            void create();
            void selectLocation();

    private:
        void createActions();

        QAction *createAct;
        QLineEdit *projectName;
        QLineEdit *projectLocationText;
        QPushButton *selectProjectLocationButton;
        QPushButton *createButton;

};
#endif
