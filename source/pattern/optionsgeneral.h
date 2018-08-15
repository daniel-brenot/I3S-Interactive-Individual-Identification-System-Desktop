#ifndef OPTIONSGENERAL_H
#define OPTIONSGENERAL_H

#include <QDialog>
#include "settings.h"

namespace Ui {
class OptionsGeneral;
}

class OptionsGeneral : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsGeneral(QWidget *parent, Settings * settings);
    ~OptionsGeneral();

private slots:
    void on_btnClose_clicked();

    void on_radExpertOn_clicked();

    void on_radExpertOff_clicked();

    void on_radAutoUpdates_clicked();

    void on_radAskUpdates_clicked();

    void on_radNeverUpdates_clicked();

    void on_txtNumThreads_textChanged(const QString &arg1);

    void on_btnReferenceColor_clicked();

    void on_btnRegionColor_clicked();

    void on_btnCircleColor_clicked();

    void on_btnCenterColor_clicked();

private:
    Ui::OptionsGeneral *ui;
    Settings * settings;
};

#endif // OPTIONSGENERAL_H
