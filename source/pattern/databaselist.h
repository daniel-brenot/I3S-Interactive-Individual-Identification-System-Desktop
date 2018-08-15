#ifndef DATABASELIST_H
#define DATABASELIST_H

#include <QDialog>
#include "settings.h"

namespace Ui {
class DatabaseList;
}

class DatabaseList : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseList(QWidget *parent, Settings * databases);
    ~DatabaseList();

private slots:
    void on_btnAddNew_clicked();

    void on_btnAddExisting_clicked();

    void on_btnRemove_clicked();

    void on_btnLoad_clicked();

    void on_btnClose_clicked();

    void on_btnRename_clicked();

private:
    Ui::DatabaseList *ui;
    Settings * settings;
    void refreshDatabaseList();
};

#endif // DATABASELIST_H
