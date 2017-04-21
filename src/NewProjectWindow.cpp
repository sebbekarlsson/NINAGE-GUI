#include "include/NewProjectWindow.h"


NewProjectWindow::NewProjectWindow() {
    int scale = 1;
    int width = (640) * scale;
    int height = (width / 16 * 9) * scale;

    this->setMinimumSize(width, height);

    setWindowTitle(tr("New Project"));
    setUnifiedTitleAndToolBarOnMac(true);

    QWidget* widget = new QWidget(this);
    
    projectName = new QLineEdit;
    projectName->setPlaceholderText("Empty Project");

    projectLocationText = new QLineEdit;
    projectLocationText->setText("/tmp");

    createButton = new QPushButton("Create", this);
    selectProjectLocationButton = new QPushButton("Location", this);

    QFormLayout *formLayout = new QFormLayout(this);
    formLayout->addRow("Name", projectName);
    
    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(projectLocationText);
    hBoxLayout->addWidget(selectProjectLocationButton);
    formLayout->addRow("Location", hBoxLayout);


    formLayout->addRow("Done", createButton);
    widget->setLayout(formLayout);

    this->setCentralWidget(widget);


    createActions();
}

void NewProjectWindow::createActions() {
    createAct = new QAction("Create", this);
    createAct->setStatusTip("Create a new project");

    connect(createAct, &QAction::triggered, this, &NewProjectWindow::create);
    connect(createButton, SIGNAL(released()), this, SLOT(create()));
    connect(selectProjectLocationButton, SIGNAL(released()), this, SLOT(selectLocation()));
}

void NewProjectWindow::selectLocation() {
QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                             "/home",
                                             QFileDialog::ShowDirsOnly
                                             | QFileDialog::DontResolveSymlinks);

this->projectLocationText->setText(dir);
}

void NewProjectWindow::create() {
    QMessageBox::warning(this, "Error", "Not Implemented");
}
