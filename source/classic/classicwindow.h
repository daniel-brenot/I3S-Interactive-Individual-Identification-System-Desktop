#ifndef CLASSICWINDOW_H
#define CLASSICWINDOW_H

#include <QMainWindow>

namespace Ui {
class ClassicWindow;
}

class ClassicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClassicWindow(QWidget *parent = nullptr);
    ~ClassicWindow();

private:
    Ui::ClassicWindow *ui;
};

#endif // CLASSICWINDOW_H
