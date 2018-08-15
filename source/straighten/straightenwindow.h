#ifndef STRAIGHTENWINDOW_H
#define STRAIGHTENWINDOW_H

#include <QMainWindow>

namespace Ui {
class StraightenWindow;
}

class StraightenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StraightenWindow(QWidget *parent = nullptr);
    ~StraightenWindow();

private:
    Ui::StraightenWindow *ui;
};

#endif // STRAIGHTENWINDOW_H
