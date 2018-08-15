#ifndef RENAMEDATABASE_H
#define RENAMEDATABASE_H

#include <QDialog>

namespace Ui {
class RenameDatabase;
}

class RenameDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit RenameDatabase(QWidget *parent, std::string dbFolder);
    ~RenameDatabase();

private:
    Ui::RenameDatabase *ui;
};

#endif // RENAMEDATABASE_H
