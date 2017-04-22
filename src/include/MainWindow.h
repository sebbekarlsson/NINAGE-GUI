#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <iostream>
#include <QtWidgets>
#include <QMainWindow>
#include <QTextEdit>
#include <QListWidget>
#include "BorderLayout.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow();

        private slots:
            void newFile();
            void openProject();

    private:
        void createActions();
        void createMenus();

        QMenu *fileMenu;
        QAction *file_newAct;
        QAction *file_openAct;
        BorderLayout *layout;
};
#endif
