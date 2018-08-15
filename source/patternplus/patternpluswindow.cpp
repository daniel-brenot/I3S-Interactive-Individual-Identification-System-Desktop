#include "patternpluswindow.h"
#include "ui_patternpluswindow.h"

PatternPlusWindow::PatternPlusWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PatternPlusWindow)
{
    ui->setupUi(this);
}

PatternPlusWindow::~PatternPlusWindow()
{
    delete ui;
}
