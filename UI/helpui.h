#ifndef HELPUI_H
#define HELPUI_H

#include <QWidget>

namespace Ui {
class HelpUI;
}

class HelpUI : public QWidget
{
    Q_OBJECT

public:
    explicit HelpUI(QWidget *parent = 0);
    ~HelpUI();

private:
    Ui::HelpUI *ui;
};

#endif // HELPUI_H
