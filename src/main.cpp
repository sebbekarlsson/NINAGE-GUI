#include <QApplication>
#include <QFileInfo>
#include <string>
#include "lib/ResourceManager/ResourceManager.h"
#include "MainWindow.h"


QUrl getAbsPath(std::string path) {
    return QUrl::fromLocalFile(
        QFileInfo(QString::fromStdString(path)).absoluteFilePath()
    );
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow * mainwin = new MainWindow();

    mainwin->show();

    return a.exec();
}
