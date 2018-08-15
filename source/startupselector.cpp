#include "startupselector.h"
#include "ui_startupselector.h"
#include "classic/classicwindow.h"
#include "pattern/patternwindow.h"
#include "contour/contourwindow.h"
#include "spot/spotwindow.h"
#include "patternplus/patternpluswindow.h"
#include "straighten/straightenwindow.h"

StartupSelector::StartupSelector(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::StartupSelector)
{
    ui->setupUi(this);
}

StartupSelector::~StartupSelector()
{
    delete ui;
}

void StartupSelector::on_btnClassic_clicked()
{
    ui->lblMessage->setText("Classic not yet supported");
    //this->close();
    //ClassicWindow * newWin = new ClassicWindow();
    //newWin->show();
}

void StartupSelector::on_btnPattern_clicked()
{
    this->close();
    PatternWindow * newWin = new PatternWindow();
    newWin->show();
}

void StartupSelector::on_btnContour_clicked()
{
    ui->lblMessage->setText("Contour not yet supported");
    //this->close();
    //ContourWindow * newWin = new ContourWindow();
    //newWin->show();
}

void StartupSelector::on_btnSpot_clicked()
{
    ui->lblMessage->setText("Spot not yet supported");
    //this->close();
    //SpotWindow * newWin = new SpotWindow();
    //newWin->show();
}

void StartupSelector::on_btnPatternPlus_clicked()
{
    ui->lblMessage->setText("Pattern+ not yet supported");
    //this->close();
    //PatternPlusWindow * newWin = new PatternPlusWindow();
    //newWin->show();
}

void StartupSelector::on_btnStraighten_clicked()
{
    ui->lblMessage->setText("Straighten not yet supported");
    //this->close();
    //StraightenWindow * newWin = new StraightenWindow();
    //newWin->show();
}
