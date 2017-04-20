#ifndef MAINWINDOW_H

#include <string>
#include <iostream>
#include <QtWidgets>
#include <QMainWindow>
#include <QTextEdit>
#include <QListWidget>


class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow();

        private slots:
            void newFile();

    private:
        void createActions();
        void createMenus();

        QMenu *fileMenu;
        QAction *newAct;
};
#endif
