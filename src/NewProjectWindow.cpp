#include "include/NewProjectWindow.h"


NewProjectWindow::NewProjectWindow() {
    int scale = 1;
    int width = (640) * scale;
    int height = (width / 16 * 9) * scale;
    
    this->setMinimumSize(width, height);

    setWindowTitle(tr("New Project"));
    setUnifiedTitleAndToolBarOnMac(true);

    createActions();
}

void NewProjectWindow::createActions() {
    createAct = new QAction(tr("&Create"), this);
    createAct->setStatusTip(tr("Create a new project"));

    connect(createAct, &QAction::triggered, this, &NewProjectWindow::create);
}

void NewProjectWindow::create() {
    QMessageBox::warning(this, tr("Error"), tr("Not Implemented"));
}
