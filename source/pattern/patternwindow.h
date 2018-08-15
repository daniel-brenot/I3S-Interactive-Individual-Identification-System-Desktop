#ifndef PATTERNWINDOW_H
#define PATTERNWINDOW_H

#include <QMainWindow>
#include "pattern/settings.h"
#include "database.h"
#include "QSettings"
namespace Ui {
class PatternWindow;
}

class PatternWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PatternWindow(QWidget *parent = nullptr);
    ~PatternWindow();
    
private slots:
    void on_actionOpen_image_triggered();
    void on_actionSave_fingerprint_triggered();
    void on_actionClose_image_triggered();
    void on_actionPrint_image_triggered();
    void on_actionExit_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionSearch_in_database_triggered();
    void on_actionInsert_in_database_triggered();
    void on_actionReload_database_triggered();
    void on_actionChange_database_triggered();
    void on_actionNew_Database_triggered();
    void on_actionRename_database_triggered();
    void on_actionEdit_database_list_triggered();
    void on_actionEdit_metadata_triggered();
    void on_actionBatch_compare_triggered();
    void on_actionProcess_batch_results_triggered();
    void on_actionOptions_results_triggered();
    void on_actionOptions_general_triggered();
    void on_actionSimple_evaluation_triggered();
    void on_actionElaborate_evaluation_triggered();
    void on_actionRedo_database_triggered();
    void on_actionRedo_individual_triggered();
    void on_actionZoom_in_triggered();
    void on_actionZoom_out_triggered();
    void on_actionShow_extended_toolbar_toggled(bool arg1);
    void on_actionOpen_manual_triggered();
    void on_actionCheck_for_updates_triggered();
    void on_actionGo_to_the_I3S_website_triggered();
    void on_actionVideo_tutorials_at_the_I3S_YouTube_channel_triggered();
    void on_actionFollow_us_on_facebook_triggered();
    void on_actionAbout_I3S_triggered();

private:
    Ui::PatternWindow *ui;
    std::vector<std::string> databaseList;
    Database *db;
    Settings * settings;
};

#endif // PATTERNWINDOW_H
