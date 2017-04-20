#include "MainWindow.h"


MainWindow::MainWindow() {
    setWindowTitle(tr("NINAGE"));
    setUnifiedTitleAndToolBarOnMac(true);

    createActions();
    createMenus();
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
}

void MainWindow::createActions() {
    newAct = new QAction(tr("&New"), this);
    
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));

    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
}

void MainWindow::newFile() {
    QMessageBox::warning(this, tr("Error"), tr("Not Implemented"));
}
