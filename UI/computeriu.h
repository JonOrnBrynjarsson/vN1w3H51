#ifndef COMPUTERIU_H
#define COMPUTERIU_H

#include <QWidget>

namespace Ui {
class computerIU;
}

class computerIU : public QWidget
{
    Q_OBJECT

public:
    explicit computerIU(QWidget *parent = 0);
    ~computerIU();

private:
    Ui::computerIU *ui;
};

#endif // COMPUTERIU_H
