#ifndef COMPUTERTYPEUI_H
#define COMPUTERTYPEUI_H

#include <QWidget>

namespace Ui {
class computertypeUI;
}

class computertypeUI : public QWidget
{
    Q_OBJECT

public:
    explicit computertypeUI(QWidget *parent = 0);
    ~computertypeUI();

private:
    Ui::computertypeUI *ui;
};

#endif // COMPUTERTYPEUI_H
