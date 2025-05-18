#include "installer.h"
#include "ui_installer.h"

Installer::Installer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Installer)
{
    ui->setupUi(this);
    Installer::loadUI(navigateUI::STAY);
    connect(ui->nextBtn, &QPushButton::clicked, this, &Installer::onNextClick);
    connect(ui->BackBtn, &QPushButton::clicked, this, &Installer::onPreviousClick);
    connect(ui->cancelBtn, &QPushButton::clicked, this,&Installer::closeInstaller);
}

Installer::~Installer()
{
    delete ui;
}
