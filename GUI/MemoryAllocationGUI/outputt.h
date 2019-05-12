#ifndef OUTPUTT_H
#define OUTPUTT_H

#include "Segmentt.h"
#include "Processs.h"
#include "Memoryy.h"
#include <iostream>
#include <string.h>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include<QHBoxLayout>
#include <list>
#include <iterator>
#include <cstdlib>
#include <QMainWindow>
#include <QColor>
#include <Qt>

namespace Ui {
class Outputt;
}

class Outputt : public QWidget
{
    Q_OBJECT

public:
    explicit Outputt(QWidget *parent = nullptr);
    ~Outputt();
    void static showOP(Memory myMem, long tickInterval);
    list<Segment> static getOP(Memory myMem);
    static QMainWindow window;
    QColor static chooseColor (long parentID);

private:
    Ui::Outputt *ui;
};

#endif // OUTPUTT_H
