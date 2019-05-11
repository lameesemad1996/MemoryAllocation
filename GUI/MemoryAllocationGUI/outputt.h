#ifndef OUTPUTT_H
#define OUTPUTT_H

#include <QWidget>

namespace Ui {
class Outputt;
}

class Outputt : public QWidget
{
    Q_OBJECT

public:
    explicit Outputt(QWidget *parent = nullptr);
    ~Outputt();

private:
    Ui::Outputt *ui;
};

#endif // OUTPUTT_H
