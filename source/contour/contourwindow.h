#ifndef CONTOURWINDOW_H
#define CONTOURWINDOW_H

#include <QMainWindow>

namespace Ui {
class ContourWindow;
}

class ContourWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContourWindow(QWidget *parent = nullptr);
    ~ContourWindow();

private:
    Ui::ContourWindow *ui;
};

#endif // CONTOURWINDOW_H
