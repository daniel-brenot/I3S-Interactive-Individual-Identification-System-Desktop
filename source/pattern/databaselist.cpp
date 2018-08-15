#include "databaselist.h"
#include "ui_databaselist.h"
#include "settings.h"
#include "QFileDialog"
#include "QLineEdit"
#include "QInputDialog"
#include "database.h"

DatabaseList::DatabaseList(QWidget *parent, Settings * settings) :
    QDialog(parent),
    ui(new Ui::DatabaseList),
    settings(settings)
{
    ui->setupUi(this);
    refreshDatabaseList();
}

DatabaseList::~DatabaseList()
{
    delete ui;
}

//Refreshes the ui database list to match the list in the settings
void DatabaseList::refreshDatabaseList(){
    ui->lstDatabases->clear();
    for(QString name:settings->dbList){
        ui->lstDatabases->addItem(name.toStdString().c_str());
    }
}

/*
 * Opens a folder dialogue and creates a metadata file in the chosen directory,also adds the record to the database list
*/
void DatabaseList::on_btnAddNew_clicked()
{
    QString file = QFileDialog::getExistingDirectory(this,tr("New database directory"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(file.isEmpty())return;
    Database database = Database(file);
    settings->dbList.push_back(file);
    settings->saveSettings();
    refreshDatabaseList();
}

//Opens a folder dialog to select an existing database.
void DatabaseList::on_btnAddExisting_clicked()
{
    QString file = QFileDialog::getExistingDirectory(this,tr("Existing database directory"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(file.isEmpty())return;
    //Do the check to see if the directory is a database

    //TODO convert old database files to the new format

    settings->dbList.push_back(file);
    settings->saveSettings();
    refreshDatabaseList();
}

void DatabaseList::on_btnRemove_clicked()
{
    QListWidgetItem * toRemove = ui->lstDatabases->currentItem();
    if(toRemove==nullptr)return;
    //find in list and remove, then save settings
    settings->dbList.removeAt(settings->dbList.indexOf(toRemove->text()));
    settings->saveSettings();
    refreshDatabaseList();
}

/*
 * sets the selected database as the current one
*/
void DatabaseList::on_btnLoad_clicked()
{
    QListWidgetItem * toLoad = ui->lstDatabases->currentItem();
    if(toLoad==nullptr)return;
    //Verify database and load the database into the ui

}

void DatabaseList::on_btnClose_clicked()
{
    this->close();
}

void DatabaseList::on_btnRename_clicked()
{
    //Stores if the user accepted the rename
    bool ok;
    //Stores the new name of the database
    QString newName = QInputDialog::getText(this,tr("Rename Database"),tr("New name:"),QLineEdit::Normal,QDir::home().dirName(), &ok);
    if(!ok)return;

    //Open the database file here and change the name
}
