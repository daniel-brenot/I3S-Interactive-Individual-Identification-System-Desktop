#include "straightenwindow.h"
#include "ui_straightenwindow.h"

StraightenWindow::StraightenWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StraightenWindow)
{
    ui->setupUi(this);
}

StraightenWindow::~StraightenWindow()
{
    delete ui;
}
