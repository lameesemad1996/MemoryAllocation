#ifndef PROCESSESINPUTFORM_H
#define PROCESSESINPUTFORM_H

#include <QWidget>

namespace Ui {
class processesinputform;
}

class processesinputform : public QWidget
{
    Q_OBJECT

public:
    explicit processesinputform(QWidget *parent = nullptr);
    ~processesinputform();

private:
    Ui::processesinputform *ui;
};

#endif // PROCESSESINPUTFORM_H
