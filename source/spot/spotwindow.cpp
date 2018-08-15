#include "spotwindow.h"
#include "ui_spotwindow.h"

SpotWindow::SpotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpotWindow)
{
    ui->setupUi(this);
}

SpotWindow::~SpotWindow()
{
    delete ui;
}
