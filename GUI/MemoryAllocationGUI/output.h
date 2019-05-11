#ifndef OUTPUT_H
#define OUTPUT_H
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

using namespace std;

class Output
{
public:
    Output();

    void static showOP(Memory myMem);
    list<Process> static getInputs();
    list<Segment> static getOP(Memory myMem);
    static QMainWindow window;
};

#endif // OUTPUT_H
