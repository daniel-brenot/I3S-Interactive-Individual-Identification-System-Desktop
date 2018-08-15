#ifndef STARTUPSELECTOR_H
#define STARTUPSELECTOR_H

#include <QFrame>

namespace Ui {
class StartupSelector;
}

class StartupSelector : public QFrame
{
    Q_OBJECT

public:
    explicit StartupSelector(QWidget *parent = nullptr);
    ~StartupSelector();

private slots:
    void on_btnPattern_clicked();

    void on_btnClassic_clicked();

    void on_btnContour_clicked();

    void on_btnSpot_clicked();

    void on_btnPatternPlus_clicked();

    void on_btnStraighten_clicked();

private:
    Ui::StartupSelector *ui;
};

#endif // STARTUPSELECTOR_H
