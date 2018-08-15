#include "contourwindow.h"
#include "ui_contourwindow.h"

ContourWindow::ContourWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ContourWindow)
{
    ui->setupUi(this);
}

ContourWindow::~ContourWindow()
{
    delete ui;
}
