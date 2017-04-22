#include "include/MainWindow.h"
#include "include/NewProjectWindow.h"


QLabel* createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    return label;
}

MainWindow::MainWindow() {
    int scale = 1;
    int width = (640) * scale;
    int height = (width / 16 * 9) * scale;
    
    this->setMinimumSize(width, height);

    setWindowTitle(tr("NINAGE"));
    setUnifiedTitleAndToolBarOnMac(true);

    BorderLayout *blayout = new BorderLayout;
    QWidget *widget = new QWidget(this);

    blayout->addWidget(createLabel("Center"), BorderLayout::Center);
    blayout->addWidget(createLabel("North"), BorderLayout::North);
    blayout->addWidget(createLabel("West"), BorderLayout::West);
    blayout->addWidget(createLabel("East 1"), BorderLayout::East);
    blayout->addWidget(createLabel("East 2") , BorderLayout::East);
    blayout->addWidget(createLabel("South"), BorderLayout::South);

    widget->setLayout(blayout);
    
    this->setCentralWidget(widget);
    
    
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
    NewProjectWindow * win = new NewProjectWindow();
    win->show();
}

void MainWindow::openProject() {
    QMessageBox::warning(this, tr("Error"), tr("Not Implemented"));
}
