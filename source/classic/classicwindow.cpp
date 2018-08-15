#include "classicwindow.h"
#include "ui_classicwindow.h"

ClassicWindow::ClassicWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClassicWindow)
{
    ui->setupUi(this);
}

ClassicWindow::~ClassicWindow()
{
    delete ui;
}
