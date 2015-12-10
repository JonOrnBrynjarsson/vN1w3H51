#ifndef REMOVEUI_H
#define REMOVEUI_H

#include <QWidget>

namespace Ui {
class removeUI;
}

class removeUI : public QWidget
{
    Q_OBJECT

public:
    explicit removeUI(QWidget *parent = 0);
    ~removeUI();

private:
    Ui::removeUI *ui;
};

#endif // REMOVEUI_H
