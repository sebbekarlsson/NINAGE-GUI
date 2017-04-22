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

    layout = new BorderLayout;
    centralWidget = new QWidget(this);

    QWidget *northWidget = new QWidget(this);
    QHBoxLayout *northLayout = new QHBoxLayout(this);

    north_playButton = new QPushButton("Run", this);
    QPixmap north_playButton_pixmap("src/assets/image/play-5-xl.png");
    QIcon north_playButton_icon(north_playButton_pixmap);
    north_playButton->setIcon(north_playButton_icon);
    north_playButton->setIconSize(QSize(16, 16));
    northLayout->addWidget(north_playButton);
    
    north_createObjectButton = new QPushButton("Object", this);
    QPixmap north_createObjectButton_pixmap("src/assets/image/3006.png");
    QIcon north_createObjectButton_icon(north_createObjectButton_pixmap);
    north_createObjectButton->setIcon(north_createObjectButton_icon);
    north_createObjectButton->setIconSize(QSize(16, 16));
    northLayout->addWidget(north_createObjectButton);

    north_createSceneButton = new QPushButton("Scene", this);
    QPixmap north_createSceneButton_pixmap("src/assets/image/window.png");
    QIcon north_createSceneButton_icon(north_createSceneButton_pixmap);
    north_createSceneButton->setIcon(north_createSceneButton_icon);
    north_createSceneButton->setIconSize(QSize(16, 16));
    northLayout->addWidget(north_createSceneButton);

    north_createSpriteButton = new QPushButton("Sprite");
    QPixmap north_createSpriteButton_pixmap("src/assets/image/art.png");
    QIcon north_createSpriteButton_icon(north_createSpriteButton_pixmap);
    north_createSpriteButton->setIcon(north_createSpriteButton_icon);
    north_createSpriteButton->setIconSize(QSize(16, 16));
    northLayout->addWidget(north_createSpriteButton);

    northWidget->setLayout(northLayout);


    layout->addWidget(createLabel("Center"), BorderLayout::Center);
    layout->addWidget(northWidget, BorderLayout::North);
    layout->addWidget(createLabel("West"), BorderLayout::West);
    //layout->addWidget(createLabel("East"), BorderLayout::East);
    //layout->addWidget(createLabel("East 2") , BorderLayout::East);
    layout->addWidget(createLabel("South"), BorderLayout::South);

    centralWidget->setLayout(layout);
    
    this->setCentralWidget(centralWidget);
    
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
