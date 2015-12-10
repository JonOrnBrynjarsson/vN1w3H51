#ifndef DISPLAYUI_H
#define DISPLAYUI_H

#include <QWidget>

namespace Ui {
class displayUI;
}

class displayUI : public QWidget
{
    Q_OBJECT

public:
    explicit displayUI(QWidget *parent = 0);
    ~displayUI();

private:
    Ui::displayUI *ui;
};

#endif // DISPLAYUI_H
