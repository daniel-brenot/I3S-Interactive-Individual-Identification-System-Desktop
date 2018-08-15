#include "optionsgeneral.h"
#include "ui_optionsgeneral.h"
#include "QColorDialog"
#include "QColor"
OptionsGeneral::OptionsGeneral(QWidget *parent, Settings * settings) :
    QDialog(parent),
    ui(new Ui::OptionsGeneral)
{
    this->settings=settings;
    ui->setupUi(this);
    ui->radExpertOn->setChecked(settings->expertMode==expertOn);
    ui->radExpertOff->setChecked(settings->expertMode==expertOff);
    ui->radAskUpdates->setChecked(settings->updatePolicy==askUpdate);
    ui->radAutoUpdates->setChecked(settings->updatePolicy==autoUpdate);
    ui->radNeverUpdates->setChecked(settings->updatePolicy==neverUpdate);
    ui->txtNumThreads->setText(std::to_string(settings->numThreads).c_str());


    //Set color selectors
    QPalette referencePalette = ui->btnReferenceColor->palette();
    QPalette regionPalette = ui->btnRegionColor->palette();
    QPalette circlePalette = ui->btnCircleColor->palette();
    QPalette centerPalette = ui->btnCenterColor->palette();
    referencePalette.setColor(QPalette::Button, QColor(settings->referenceColor.red,settings->referenceColor.green,settings->referenceColor.blue));
    regionPalette.setColor(QPalette::Button, QColor(settings->regionColor.red,settings->regionColor.green,settings->regionColor.blue));
    circlePalette.setColor(QPalette::Button, QColor(settings->circleColor.red,settings->circleColor.green,settings->circleColor.blue));
    centerPalette.setColor(QPalette::Button, QColor(settings->centerColor.red,settings->centerColor.green,settings->centerColor.blue));
    ui->btnReferenceColor->setAutoFillBackground(true);
    ui->btnRegionColor->setAutoFillBackground(true);
    ui->btnCircleColor->setAutoFillBackground(true);
    ui->btnCenterColor->setAutoFillBackground(true);
    ui->btnReferenceColor->setPalette(referencePalette);
    ui->btnRegionColor->setPalette(regionPalette);
    ui->btnCircleColor->setPalette(circlePalette);
    ui->btnCenterColor->setPalette(centerPalette);
    ui->btnReferenceColor->setFlat(true);
    ui->btnRegionColor->setFlat(true);
    ui->btnCircleColor->setFlat(true);
    ui->btnCenterColor->setFlat(true);
    ui->btnReferenceColor->update();
    ui->btnRegionColor->update();
    ui->btnCircleColor->update();
    ui->btnCenterColor->update();
}

OptionsGeneral::~OptionsGeneral()
{
    delete ui;
}

void OptionsGeneral::on_btnClose_clicked()
{
    this->close();
}


void OptionsGeneral::on_radExpertOn_clicked()
{
    settings->expertMode=expertOn;
    settings->saveSettings();
}

void OptionsGeneral::on_radExpertOff_clicked()
{
    settings->expertMode=expertOff;
    settings->saveSettings();
}

void OptionsGeneral::on_radAutoUpdates_clicked()
{
    settings->updatePolicy=autoUpdate;
    settings->saveSettings();
}

void OptionsGeneral::on_radAskUpdates_clicked()
{
    settings->updatePolicy=askUpdate;
    settings->saveSettings();
}

void OptionsGeneral::on_radNeverUpdates_clicked()
{
    settings->updatePolicy=neverUpdate;
    settings->saveSettings();
}

//Cancels any non-digit inputs from going onto the text field. Could be more efficient I believe
void OptionsGeneral::on_txtNumThreads_textChanged(const QString &text)
{
    for(unsigned int i=0;i<text.length();i++)
    {
        if(!text[i].isNumber()){
            ui->txtNumThreads->setText(text.toStdString().erase(i).c_str());
            return;
        }
    }
    settings->numThreads=ui->txtNumThreads->text().toInt();
    settings->saveSettings();
}

void OptionsGeneral::on_btnReferenceColor_clicked()
{
    QColor newColor = QColorDialog().getColor(QColor(settings->referenceColor.red,settings->referenceColor.green,settings->referenceColor.blue),this);
    settings->referenceColor.red=newColor.red();
    settings->referenceColor.green=newColor.green();
    settings->referenceColor.blue=newColor.blue();
    settings->saveSettings();
    QPalette referencePalette = ui->btnReferenceColor->palette();
    referencePalette.setColor(QPalette::Button, QColor(settings->referenceColor.red,settings->referenceColor.green,settings->referenceColor.blue));
    ui->btnReferenceColor->setPalette(referencePalette);
    ui->btnReferenceColor->update();
}

void OptionsGeneral::on_btnRegionColor_clicked()
{
    QColor newColor = QColorDialog().getColor(QColor(settings->regionColor.red,settings->regionColor.green,settings->regionColor.blue),this);
    settings->regionColor.red=newColor.red();
    settings->regionColor.green=newColor.green();
    settings->regionColor.blue=newColor.blue();
    settings->saveSettings();
    QPalette regionPalette = ui->btnRegionColor->palette();
    regionPalette.setColor(QPalette::Button, QColor(settings->regionColor.red,settings->regionColor.green,settings->regionColor.blue));
    ui->btnRegionColor->setPalette(regionPalette);
    ui->btnRegionColor->update();
}

void OptionsGeneral::on_btnCircleColor_clicked()
{
    QColor newColor = QColorDialog().getColor(QColor(settings->circleColor.red,settings->circleColor.green,settings->circleColor.blue),this);
    settings->circleColor.red=newColor.red();
    settings->circleColor.green=newColor.green();
    settings->circleColor.blue=newColor.blue();
    settings->saveSettings();
    QPalette circlePalette = ui->btnCircleColor->palette();
    circlePalette.setColor(QPalette::Button, QColor(settings->circleColor.red,settings->circleColor.green,settings->circleColor.blue));
    ui->btnCircleColor->setPalette(circlePalette);
    ui->btnCircleColor->update();
}

void OptionsGeneral::on_btnCenterColor_clicked()
{
    QColor newColor = QColorDialog().getColor(QColor(settings->centerColor.red,settings->centerColor.green,settings->centerColor.blue),this);
    settings->centerColor.red=newColor.red();
    settings->centerColor.green=newColor.green();
    settings->centerColor.blue=newColor.blue();
    settings->saveSettings();
    QPalette centerPalette = ui->btnCenterColor->palette();
    centerPalette.setColor(QPalette::Button, QColor(settings->centerColor.red,settings->centerColor.green,settings->centerColor.blue));
    ui->btnCenterColor->setPalette(centerPalette);
    ui->btnCenterColor->update();
}
