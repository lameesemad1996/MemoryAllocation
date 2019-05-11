#ifndef HOLESSINPUTFORM_H
#define HOLESSINPUTFORM_H

#include <QWidget>

namespace Ui {
class holessinputform;
}

class holessinputform : public QWidget
{
    Q_OBJECT

public:
    explicit holessinputform(QWidget *parent = nullptr);
    ~holessinputform();

private:
    Ui::holessinputform *ui;
};

#endif // HOLESSINPUTFORM_H
