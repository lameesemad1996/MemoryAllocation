#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QWidget>

namespace Ui {
class inputform;
}

class inputform : public QWidget
{
    Q_OBJECT

public:
    explicit inputform(QWidget *parent = nullptr);
    ~inputform();

private:
    Ui::inputform *ui;
};

#endif // INPUTFORM_H
