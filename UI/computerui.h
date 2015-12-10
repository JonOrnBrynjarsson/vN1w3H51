#ifndef COMPUTERUI_H
#define COMPUTERUI_H

#include <QWidget>

namespace Ui {
class computerUI;
}

class computerUI : public QWidget
{
    Q_OBJECT

public:
    explicit computerUI(QWidget *parent = 0);
    ~computerUI();

private:
    Ui::computerUI *ui;
};

#endif // COMPUTERUI_H
