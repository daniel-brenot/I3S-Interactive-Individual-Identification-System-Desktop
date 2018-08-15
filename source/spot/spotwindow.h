#ifndef SPOTWINDOW_H
#define SPOTWINDOW_H

#include <QMainWindow>

namespace Ui {
class SpotWindow;
}

class SpotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpotWindow(QWidget *parent = nullptr);
    ~SpotWindow();

private:
    Ui::SpotWindow *ui;
};

#endif // SPOTWINDOW_H
