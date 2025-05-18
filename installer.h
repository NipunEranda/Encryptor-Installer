#ifndef INSTALLER_H
#define INSTALLER_H

#include <QMainWindow>
#include <QApplication>
#include "ui_installer.h"

enum class uiID {
    NONE,
    INTRO,
    INSTALLATION_LOCATION,
    CONFIRMATION
};

enum class navigateUI{
    STAY,
    NEXTUI,
    PREVIOUSUI
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Installer;
}
QT_END_NAMESPACE

class Installer : public QMainWindow
{
    Q_OBJECT

public:
    Installer(QWidget *parent = nullptr);
    ~Installer();

private slots:
    void onNextClick() {
        loadUI(navigateUI::NEXTUI);
    }
    void onPreviousClick() {
        loadUI(navigateUI::PREVIOUSUI);
    }
    void loadUI(navigateUI navigation) {
        ui->introFrame->hide();
        ui->installationLocationFrame->hide();

        switch (activeUI) {
            case uiID::INTRO:
                ui->introFrame->show();
                ui->BackBtn->hide();

                if(navigation == navigateUI::NEXTUI){
                    ui->introFrame->hide();
                    ui->installationLocationFrame->show();
                    ui->BackBtn->show();
                }
                break;
            case uiID::INSTALLATION_LOCATION:
                ui->installationLocationFrame->show();
                ui->BackBtn->show();

                if(navigation == navigateUI::PREVIOUSUI){
                    ui->installationLocationFrame->hide();
                    ui->introFrame->show();
                    ui->BackBtn->hide();
                }
                break;
            case uiID::CONFIRMATION:
                ui->BackBtn->show();
                break;
            default:
                break;
        }
    }
    void closeInstaller() {
        QApplication::quit();
    }

private:
    Ui::Installer *ui;
    uiID activeUI = uiID::INTRO;
};
#endif // INSTALLER_H
