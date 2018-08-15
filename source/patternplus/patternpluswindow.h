#ifndef PATTERNPLUSWINDOW_H
#define PATTERNPLUSWINDOW_H

#include <QMainWindow>

namespace Ui {
class PatternPlusWindow;
}

class PatternPlusWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PatternPlusWindow(QWidget *parent = nullptr);
    ~PatternPlusWindow();

private:
    Ui::PatternPlusWindow *ui;
};

#endif // PATTERNPLUSWINDOW_H
