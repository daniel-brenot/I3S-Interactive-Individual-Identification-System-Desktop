#include "optionsresults.h"
#include "ui_optionsresults.h"

OptionsResults::OptionsResults(QWidget *parent, Settings * settings) :
    QDialog(parent),
    ui(new Ui::OptionsResults)
{
    this->settings=settings;
    ui->setupUi(this);

    //loads the settings into the ui
    ui->radLoggingOn->setChecked(settings->loggingResults==loggingOn);
    ui->radLoggingOff->setChecked(settings->loggingResults==loggingOff);
    ui->radShowFileName->setChecked(settings->resultsType==fileResults);
    ui->radShowFolderName->setChecked(settings->resultsType==folderResults);
    ui->radShowAllMatches->setChecked(settings->matchType==allMatches);
    ui->radShowBestMatch->setChecked(settings->matchType==bestMatching);
    ui->radShowTop50->setChecked(settings->numResults==fiftyResults);
    ui->radShowAll->setChecked(settings->numResults==allResults);
    ui->txtNumBatchResults->setText(std::to_string(settings->batchResults).c_str());
}

OptionsResults::~OptionsResults()
{
    delete ui;
}

void OptionsResults::on_btnClose_clicked()
{
    this->close();
}

void OptionsResults::on_radLoggingOff_clicked()
{
    settings->loggingResults=loggingOff;
    settings->saveSettings();
}

void OptionsResults::on_radLoggingOn_clicked()
{
    settings->loggingResults=loggingOn;
    settings->saveSettings();
}

void OptionsResults::on_radShowFileName_clicked()
{
    settings->resultsType=fileResults;
    settings->saveSettings();
}

void OptionsResults::on_radShowFolderName_clicked()
{
    settings->resultsType=folderResults;
    settings->saveSettings();
}

void OptionsResults::on_radShowAllMatches_clicked()
{
    settings->matchType=allMatches;
    settings->saveSettings();
}

void OptionsResults::on_radShowBestMatch_clicked()
{
    settings->matchType=bestMatching;
    settings->saveSettings();
}

void OptionsResults::on_radShowTop50_clicked()
{
    settings->numResults=fiftyResults;
    settings->saveSettings();
}

void OptionsResults::on_radShowAll_clicked()
{
    settings->numResults=allResults;
    settings->saveSettings();
}

//Cancels any non-digit inputs from going onto the text field. Could be more efficient I believe
void OptionsResults::on_txtNumBatchResults_textChanged(const QString &text)
{
    for(unsigned int i=0;i<text.length();i++)
    {
        if(!text[i].isNumber()){
            ui->txtNumBatchResults->setText(text.toStdString().erase(i).c_str());
            return;
        }
    }
    settings->batchResults=ui->txtNumBatchResults->text().toInt();
    settings->saveSettings();
}
