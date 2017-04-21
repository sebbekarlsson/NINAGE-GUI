#include "include/MainWindow.h"


MainWindow::MainWindow() {
    int scale = 1;
    int width = (640) * scale;
    int height = (width / 16 * 9) * scale;
    
    this->setMinimumSize(width, height);

    setWindowTitle(tr("NINAGE"));
    setUnifiedTitleAndToolBarOnMac(true);

    createActions();
    createMenus();
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(file_newAct);
    fileMenu->addAction(file_openAct);
}

void MainWindow::createActions() {
    file_newAct = new QAction(tr("&New"), this);
    
    file_newAct->setShortcuts(QKeySequence::New);
    file_newAct->setStatusTip(tr("Create a new project"));

    connect(file_newAct, &QAction::triggered, this, &MainWindow::newFile);
    
    file_openAct = new QAction(tr("&Open"), this);

    file_openAct->setStatusTip(tr("Open existing project"));

    connect(file_openAct, &QAction::triggered, this, &MainWindow::openProject);
}

void MainWindow::newFile() {
    QMessageBox::warning(this, tr("Error"), tr("Not Implemented"));
}

void MainWindow::openProject() {
    QMessageBox::warning(this, tr("Error"), tr("Not Implemented"));
}
