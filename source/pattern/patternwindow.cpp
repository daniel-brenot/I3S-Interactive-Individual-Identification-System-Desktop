#include "patternwindow.h"
#include "ui_patternwindow.h"
#include "QDesktopServices"
#include "pattern/optionsresults.h"
#include "pattern/optionsgeneral.h"
#include "pattern/editmetadata.h"
#include "pattern/databaselist.h"
#include "QFileDialog"
#include "QUrl"
#include "QSettings"
PatternWindow::PatternWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PatternWindow)
{
    //Creates the settings object
    settings = new Settings(new QSettings("I3S","Pattern"));
    //Creates the database object the ui is bound to
    db = new Database();
    ui->setupUi(this);
}

PatternWindow::~PatternWindow()
{
    delete ui;
}

/* UI functions for buttons being triggered*/

//File->Open image
void PatternWindow::on_actionOpen_image_triggered()
{
    std::string file = QFileDialog::getOpenFileName(this,tr("Open Image"), "", tr("Image Files (*.jpg)")).toStdString();
}

//File->Save Fingerprint
void PatternWindow::on_actionSave_fingerprint_triggered()
{

}

//File->Close image
void PatternWindow::on_actionClose_image_triggered()
{

}

//File->Print image
void PatternWindow::on_actionPrint_image_triggered()
{

}

//File->Exit
void PatternWindow::on_actionExit_triggered()
{
    this->close();
}

//Edit->Undo
void PatternWindow::on_actionUndo_triggered()
{

}

//Edit->Redo
void PatternWindow::on_actionRedo_triggered()
{

}

//Database->Search in database
void PatternWindow::on_actionSearch_in_database_triggered()
{

}

//Database->Insert in database
void PatternWindow::on_actionInsert_in_database_triggered()
{

}

//Database->Reload database
void PatternWindow::on_actionReload_database_triggered()
{

}

//Database->Change database
void PatternWindow::on_actionChange_database_triggered()
{

}

//Database->New database
void PatternWindow::on_actionNew_Database_triggered()
{

}

//Database->Rename database
void PatternWindow::on_actionRename_database_triggered()
{

}

//Database->Edit database list
void PatternWindow::on_actionEdit_database_list_triggered()
{
    std::vector<std::string> dbs;
    dbs.push_back("db1");
    DatabaseList * newWin = new DatabaseList(this,settings);
    newWin->show();
}

//Database->Edit metadata
void PatternWindow::on_actionEdit_metadata_triggered()
{
    EditMetadata * newWin = new EditMetadata(this, db);
    newWin->show();
}

//Database->Batch compare
void PatternWindow::on_actionBatch_compare_triggered()
{

}

//Database->Process batch results
void PatternWindow::on_actionProcess_batch_results_triggered()
{

}

//Options->Options results
void PatternWindow::on_actionOptions_results_triggered()
{
    OptionsResults * newWin = new OptionsResults(this, settings);
    newWin->show();
}

//Options->Options general
void PatternWindow::on_actionOptions_general_triggered()
{
    OptionsGeneral * newWin = new OptionsGeneral(this, settings);
    newWin->show();
}

//Expert->Simple evaluation
void PatternWindow::on_actionSimple_evaluation_triggered()
{

}

//Expert->Elaborate evaluation
void PatternWindow::on_actionElaborate_evaluation_triggered()
{

}

//Expert->Redo database
void PatternWindow::on_actionRedo_database_triggered()
{

}

//Expert->Redo individual
void PatternWindow::on_actionRedo_individual_triggered()
{

}

//View->Zoom in
void PatternWindow::on_actionZoom_in_triggered()
{

}

//View->Zoom out
void PatternWindow::on_actionZoom_out_triggered()
{

}

//View->Show extended toolbar
void PatternWindow::on_actionShow_extended_toolbar_toggled(bool arg1)
{
    if(arg1){
        ui->mainToolBar->insertAction(ui->actionToggle_edit_mode,ui->actionOpen_image);
        ui->mainToolBar->insertAction(ui->actionToggle_edit_mode,ui->actionSave_fingerprint);
        ui->mainToolBar->insertAction(ui->actionToggle_edit_mode,ui->actionPrint_image);
        ui->mainToolBar->insertAction(ui->actionToggle_edit_mode,ui->actionSearch_in_database);
        ui->mainToolBar->insertAction(ui->actionToggle_edit_mode,ui->actionZoom_in);
        ui->mainToolBar->insertAction(ui->actionToggle_edit_mode,ui->actionZoom_out);
    }
    else {
        ui->mainToolBar->removeAction(ui->actionOpen_image);
        ui->mainToolBar->removeAction(ui->actionSave_fingerprint);
        ui->mainToolBar->removeAction(ui->actionPrint_image);
        ui->mainToolBar->removeAction(ui->actionSearch_in_database);
        ui->mainToolBar->removeAction(ui->actionZoom_in);
        ui->mainToolBar->removeAction(ui->actionZoom_out);
    }
}

//Help->Open Manual
void PatternWindow::on_actionOpen_manual_triggered()
{
    //TODO attach manual for version
    QDesktopServices::openUrl(QUrl("", QUrl::TolerantMode ));
}

//Help->Check for updates
void PatternWindow::on_actionCheck_for_updates_triggered()
{
    //TODO integrate an updater software
}

//Help->Go to the I3S website
void PatternWindow::on_actionGo_to_the_I3S_website_triggered()
{
    QDesktopServices::openUrl(QUrl("http://www.reijns.com/i3s/", QUrl::TolerantMode ));
}

//Help->Video tutorials at the I3S Youtube channel
void PatternWindow::on_actionVideo_tutorials_at_the_I3S_YouTube_channel_triggered()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/channel/UC0QLj0fuquYTJFe4xe6TKFQ", QUrl::TolerantMode ));
}

//Help->Follow us on facebook
void PatternWindow::on_actionFollow_us_on_facebook_triggered()
{
    QDesktopServices::openUrl(QUrl("https://www.facebook.com/jurgenrenate.photoident", QUrl::TolerantMode ));
}

//Help->Open Manual
void PatternWindow::on_actionAbout_I3S_triggered()
{
    QDesktopServices::openUrl(QUrl("", QUrl::TolerantMode ));
}


