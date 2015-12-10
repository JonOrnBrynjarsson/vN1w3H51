#ifndef SCIENTISTUI_H
#define SCIENTISTUI_H

#include <QWidget>
#include <QDebug>


namespace Ui {
class scientistUI;
}

class scientistUI : public QWidget
{
    Q_OBJECT

public:
    explicit scientistUI(QWidget *parent = 0);
    ~scientistUI();

private:
    Ui::scientistUI *ui;
};

#endif // SCIENTISTUI_H
