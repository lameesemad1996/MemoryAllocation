#ifndef PROCESSESINPUTFORM_H
#define PROCESSESINPUTFORM_H

#include <QWidget>
#include "Processs.h"
#include "Segmentt.h"
#include "Memoryy.h"
#include <QTreeWidgetItem>

namespace Ui {
class processesinputform;
}

class processesinputform : public QWidget
{
    Q_OBJECT

public:
    explicit processesinputform(QWidget *parent = nullptr);
    ~processesinputform();
    list<Process> listOfInputProcesses;
    list<QTreeWidgetItem*> listOfItemProcesses;
    list<QTreeWidgetItem*> listOfItemOldProcesses;
    long indexNow;
    list<QTreeWidgetItem*>::iterator itemIt;
    list<Process>::iterator processIt;
    list<Segment>::iterator oldIt;
    static long staticLengthOfList;
    static long iteration;
    enum allocationType {firstFit, bestFit, worstFit, none} allocationTypeEnum;

private slots:
    void on_addProcessPushButton_clicked();

    void on_addSegmentPushButton_clicked();

    void on_deallocatePushButton_clicked();

    void on_allocatePushButton_clicked();

    void on_drawPushButton_clicked();

    void on_firstFitCheckBox_stateChanged();

    void on_bestFitCheckBox_stateChanged();

    void on_worstFitCheckBox_stateChanged();

private:
    Ui::processesinputform *ui;
};

#endif // PROCESSESINPUTFORM_H
