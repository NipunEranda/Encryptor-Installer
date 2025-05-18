#ifndef INSTALLER_H
#define INSTALLER_H

#include <QMainWindow>

enum class uiID {
    INTRO,
    INSTALLATION_LOCATION,
    CONFIRMATION
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

private:
    Ui::Installer *ui;
    uiID activeUI = uiID::INTRO;
};
#endif // INSTALLER_H
