#include "renamedatabase.h"
#include "ui_renamedatabase.h"

RenameDatabase::RenameDatabase(QWidget *parent, std::string dbFolder) :
    QDialog(parent),
    ui(new Ui::RenameDatabase)
{
    ui->setupUi(this);
}

RenameDatabase::~RenameDatabase()
{
    delete ui;
}
