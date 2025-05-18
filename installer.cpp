#include "installer.h"
#include "ui_installer.h"

Installer::Installer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Installer)
{
    ui->setupUi(this);

    switch (activeUI) {
    case uiID::INTRO:
        ui->introFrame->show();
        ui->installationLocationFrame->hide();
        break;
    case uiID::INSTALLATION_LOCATION:
        ui->introFrame->hide();
        ui->installationLocationFrame->show();
        break;
    case uiID::CONFIRMATION:
        break;
    default:
        break;
    }
}

Installer::~Installer()
{
    delete ui;
}
