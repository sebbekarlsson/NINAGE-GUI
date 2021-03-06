#include <QApplication>
#include <QFileInfo>
#include <string>
#include "lib/ResourceManager/ResourceManager.h"
#include "include/MainWindow.h"


bool hasProject = false;
std::string projectLocation = "";

QUrl getAbsPath(std::string path) {
    return QUrl::fromLocalFile(
        QFileInfo(QString::fromStdString(path)).absoluteFilePath()
    );
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow * mainwin = new MainWindow();

    //mainwin->windowHandle()->showFullScreen();
    mainwin->show();

    return a.exec();
}
