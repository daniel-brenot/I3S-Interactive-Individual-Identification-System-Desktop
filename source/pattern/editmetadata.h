#ifndef EDITMETADATA_H
#define EDITMETADATA_H

#include <QDialog>
#include "database.h"

namespace Ui {
class EditMetadata;
}

class EditMetadata : public QDialog
{
    Q_OBJECT

public:
    explicit EditMetadata(QWidget *parent, Database* db);
    ~EditMetadata();

private slots:
    void on_btnEditDatabaseName_toggled(bool checked);

    void on_btnEditRef1_toggled(bool checked);

    void on_btnEditRef2_toggled(bool checked);

    void on_btnEditRef3_toggled(bool checked);

    void on_btnEditNumKeyPoints_toggled(bool checked);

    void on_btnEditWarpSize_toggled(bool checked);

    void on_btnEditRelKeyDistance_toggled(bool checked);

    void on_btnEditRedWeight_toggled(bool checked);

    void on_btnEditGreenWeight_toggled(bool checked);

    void on_btnEditBlueWeight_toggled(bool checked);

    void on_btnEditMaxDistance_toggled(bool checked);

    void on_btnEditMinDistance_toggled(bool checked);

    void on_btnEditMinRatio_toggled(bool checked);

    void on_btnHelpNumKeyPoints_clicked();

    void on_btnHelpWarpSize_clicked();

    void on_btnHelpRelKeyDistance_clicked();

    void on_btnHelpRedWeight_clicked();

    void on_btnHelpGreenWeight_clicked();

    void on_btnHelpBlueWeight_clicked();

    void on_btnHelpMaxDistance_clicked();

    void on_btnHelpMinDistance_clicked();

    void on_btnHelpMinRatio_clicked();

private:
    Ui::EditMetadata *ui;
    Database * db;
    void disableAll();
    void enableAll();
};

#endif // EDITMETADATA_H
