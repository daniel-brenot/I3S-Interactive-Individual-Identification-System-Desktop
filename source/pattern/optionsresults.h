#ifndef OPTIONSRESULTS_H
#define OPTIONSRESULTS_H

#include <QDialog>
#include "settings.h"

namespace Ui {
class OptionsResults;
}

class OptionsResults : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsResults(QWidget *parent, Settings * settings);
    ~OptionsResults();

private slots:
    void on_btnClose_clicked();

    void on_radLoggingOff_clicked();

    void on_radLoggingOn_clicked();

    void on_radShowFileName_clicked();

    void on_radShowFolderName_clicked();

    void on_radShowAllMatches_clicked();

    void on_radShowBestMatch_clicked();

    void on_radShowTop50_clicked();

    void on_radShowAll_clicked();

    void on_txtNumBatchResults_textChanged(const QString &arg1);

private:
    Ui::OptionsResults *ui;
    Settings * settings;
};

#endif // OPTIONSRESULTS_H
