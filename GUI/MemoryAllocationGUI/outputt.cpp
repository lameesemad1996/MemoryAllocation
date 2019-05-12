#include "outputt.h"
#include "ui_outputt.h"
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarLegendMarker>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>
#include <QMainWindow>
#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <cstdlib>
#include <QColor>
#include <QVBoxLayout>
#include <QDockWidget>
#include <Qt>
#include "Segmentt.h"
#include "Processs.h"
#include "Memoryy.h"

Outputt::Outputt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outputt)
{
    ui->setupUi(this);
}

Outputt::~Outputt()
{
    delete ui;
}

QColor Outputt::chooseColor (long parentID)
{
    int choose = parentID % 13;

    switch (choose)
    {
    case 0:
        return Qt::yellow;
    case 1:
        return Qt::darkBlue;
    case 2:
        return Qt::darkCyan;
    case 3:
        return Qt::blue;
    case 4:
        return Qt::green;
    case 5:
        return Qt::magenta;
    case 6:
        return Qt::cyan;
    case 7:
        return Qt::darkYellow;
    case 8:
        return Qt::black;
    case 9:
        return Qt::darkGray;
    case 10:
        return Qt::darkGreen;
    case 11:
        return Qt::red;
    case 12:
        return Qt::darkMagenta;
    default:
        return Qt::white;
    }
}

list<Segment> Outputt::getOP(Memory myMem)
{
    return myMem.memorySegmentsList;
}

void Outputt::showOP(Memory myMem, long tickInterval)
{
    list<Segment> opList;
    opList = getOP(myMem);

    list<Segment>::iterator it = opList.begin();

    //determining number of segments
    unsigned long long length = opList.size();


    //creating sets (a set for each process)
    QtCharts::QBarSet* sets[100000];

    //append sets to series
    QtCharts::QStackedBarSeries *series = new QtCharts::QStackedBarSeries();

    for(int i = 0; i < length; i++)
    {
        if(it->getState() == Segment::free)
        {
            sets[i] = new QtCharts::QBarSet(QString::fromStdString("Hole"));
            *sets[i] << it->getLimit();
            sets[i]->setColor(Qt::lightGray);
            series->append(sets[i]);
        }
        else
        {
            sets[i] = new QtCharts::QBarSet(QString::fromStdString(it->getName()));
            if(it->getName() == "Old Process")
                sets[i]->setColor(Qt::darkRed);
            else
            {
                cout << it->getParentProcessId() << endl;
                QColor color = Outputt::chooseColor(it->getParentProcessId());
                sets[i]->setColor(color);
            }
            *sets[i] << it->getLimit();
            series->append(sets[i]);
        }
        it++;
    }

    //chart creation
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Memory Contents");

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    axisY->setTickType(QtCharts::QValueAxis::TickType::TicksDynamic);
    axisY->setTickInterval(tickInterval);
    axisY->setTickAnchor(0);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    //legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //adding a view
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    //set chart to be central widget and set size of chart window
    QMainWindow* windowPtr = new QMainWindow();
    windowPtr->setWindowModality(Qt::WindowModal);
    windowPtr->setCentralWidget(chartView);
    windowPtr->resize(420, 300);
    windowPtr->show();

}

