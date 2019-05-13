#include "processesinputform.h"
#include "ui_processesinputform.h"
#include "mainwindow.h"
#include <QSpinBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTreeWidgetItemIterator>
#include "outputt.h"
#include "Segmentt.h"
#include "Processs.h"
#include <list>
#include <iterator>
#include <QMessageBox>

processesinputform::processesinputform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processesinputform)
{
    ui->setupUi(this);
    indexNow = -1;
    iteration++;
    ui->segSizeSpinBox->setRange(0,2000000000);
    ui->noOfSegSpinBox->setRange(0,2000000000);

    for(oldIt = MainWindow::instance()->myMem.OldProcessSegmentsList.begin() ; oldIt != MainWindow::instance()->myMem.OldProcessSegmentsList.end(); ++oldIt)
    {
        QTreeWidgetItem* newOldProcessItem = new QTreeWidgetItem(ui->oldProcessTreeWidget);
        newOldProcessItem->setText(0, QString::fromStdString(to_string(oldIt->getID())));
        newOldProcessItem->setText(1, "Old Process");
        newOldProcessItem->setText(2, "True");
        newOldProcessItem->setText(3, QString::fromStdString(to_string(oldIt->getBase())));
        newOldProcessItem->setText(4, QString::fromStdString(to_string(oldIt->getLimit())));
    }
}

processesinputform::~processesinputform()
{
    delete ui;
}

long processesinputform::staticLengthOfList = 0;
long processesinputform::iteration = -1;

void processesinputform::on_addProcessPushButton_clicked()
{
    if(indexNow == -1)
    {
        string processName = ui->processNameLineEdit->text().toUtf8().constData();
        long noOfSeg = ui->noOfSegSpinBox->value();
        Process newprocess(processName);
        newprocess.setNoOfSeg(noOfSeg);
        listOfInputProcesses.push_back(newprocess);
        QTreeWidgetItem* newProcessItem = new QTreeWidgetItem(ui->processSegmentTreeWidget);
        newProcessItem->setText(0, QString::fromStdString(to_string(newprocess.getID())));
        newProcessItem->setText(1, QString::fromStdString(newprocess.getName()));
        newProcessItem->setText(2, "False");
        listOfItemProcesses.push_back(newProcessItem);

        //incrementing index to process list, iterator to process list and iterator to item list
        indexNow ++;
        staticLengthOfList++;
        if(indexNow == 0)
        {
            itemIt = listOfItemProcesses.begin();
            processIt = listOfInputProcesses.begin();
        }
        else
        {
            itemIt++;
            processIt++;
        }
    }
    else
    {
        if ((*itemIt)->childCount() < processIt->getNoOfSeg())
        {
            QMessageBox::information(this,tr("Cannot Add Process"),tr("Complete segment entry for the previous process"));
        }
        else
        {
            string processName = ui->processNameLineEdit->text().toUtf8().constData();
            long noOfSeg = ui->noOfSegSpinBox->value();
            Process newprocess(processName);
            newprocess.setNoOfSeg(noOfSeg);
            listOfInputProcesses.push_back(newprocess);
            QTreeWidgetItem* newProcessItem = new QTreeWidgetItem(ui->processSegmentTreeWidget);
            newProcessItem->setText(0, QString::fromStdString(to_string(newprocess.getID())));
            newProcessItem->setText(1, QString::fromStdString(newprocess.getName()));
            newProcessItem->setText(2, "False");
            listOfItemProcesses.push_back(newProcessItem);

            //incrementing index to process list, iterator to process list and iterator to item list
            staticLengthOfList++;
            indexNow ++;
            if(indexNow == 0)
            {
                itemIt = listOfItemProcesses.begin();
                processIt = listOfInputProcesses.begin();
            }
            else
            {
                itemIt++;
                processIt++;
            }
        }
    }
    ui->processNameLineEdit->setText("");
    ui->noOfSegSpinBox->setValue(0);
}

void processesinputform::on_addSegmentPushButton_clicked()
{
    if(indexNow == -1)
    {
        QMessageBox::information(this,tr("Cannot Add Segment"),tr("Add a parent process first"));
    }
    else if ((*itemIt)->childCount() == processIt->getNoOfSeg())
    {
        QMessageBox::information(this,tr("Cannot Add Segment"),tr("Process segments are complete"));
    }
    else
    {
        string segmentName = ui->segNameLineEdit->text().toUtf8().constData();
        long segmentSize = ui->segSizeSpinBox->value();
        Segment newsegment(segmentName,segmentSize);
        processIt->addSegment(newsegment);
        QTreeWidgetItem* newSegmentItem = new QTreeWidgetItem();   //*itemIt
        (*itemIt)->addChild(newSegmentItem);
        //newSegmentItem->setText(3, QString::fromStdString(to_string(newsegment.getID())));
        newSegmentItem->setText(3, QString::fromStdString(to_string((*itemIt)->childCount())));
        newSegmentItem->setText(4, QString::fromStdString(newsegment.getName()));
        newSegmentItem->setText(5,QString::fromStdString(to_string(newsegment.getSize())));
        (*itemIt)->setExpanded(true);
    }
    ui->segNameLineEdit->setText("");
    ui->segSizeSpinBox->setValue(0);
}

void processesinputform::on_allocatePushButton_clicked()
{
    Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
    if(allocationTypeEnum == allocationType::firstFit)
    {
        QTreeWidgetItem* selectedItemPtr = ui->processSegmentTreeWidget->currentItem();
        QString allocated = "True";
        if(selectedItemPtr == nullptr)
        {
            QMessageBox::information(this,tr("Cannot Allocate"),tr("Please select a process to allocate"));
        }
        else if (selectedItemPtr->data(2,0).toString() == allocated)
        {
            QMessageBox::information(this,tr("Cannot Allocate"),tr("This process is already allocated"));
        }
        else
        {
            long processId = std::stol((selectedItemPtr->data(0,0)).toString().toUtf8().constData());
            if(iteration != 0)
            {
                processId -= (staticLengthOfList+1);
            }
            list<Process>::iterator proIt = listOfInputProcesses.begin();
            std::advance(proIt, processId);
            Process inputToFn = *proIt;
            bool isAllocatedFlag = MainWindow::instance()->myMem.first_fit_allocate(inputToFn);
            if(isAllocatedFlag)
            {
                Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
                Outputt::showOP(MainWindow::instance()->myMem, (MainWindow::instance()->myMem.getSize())/20);
                selectedItemPtr->setText(2, "True");
            }
            else
            {
                QMessageBox::information(this,tr("Cannot Allocate"),tr("There is no enough memory"));
            }
        }
    }
    else if(allocationTypeEnum == allocationType::bestFit)
    {
        QTreeWidgetItem* selectedItemPtr = ui->processSegmentTreeWidget->currentItem();
        QString allocated = "True";
        if(selectedItemPtr == nullptr)
        {
            QMessageBox::information(this,tr("Cannot Allocate"),tr("Please select a process to allocate"));
        }
        else if (selectedItemPtr->data(2,0).toString() == allocated)
        {
            QMessageBox::information(this,tr("Cannot Allocate"),tr("This process is already allocated"));
        }
        else
        {
            long processId = std::stol((selectedItemPtr->data(0,0)).toString().toUtf8().constData());
            if(iteration != 0)
            {
                processId -= (staticLengthOfList+1);
            }
            list<Process>::iterator proIt = listOfInputProcesses.begin();
            std::advance(proIt, processId);
            Process inputToFn = *proIt;
            bool isAllocatedFlag = MainWindow::instance()->myMem.best_fit_allocate(inputToFn);
            if(isAllocatedFlag)
            {
                Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
                Outputt::showOP(MainWindow::instance()->myMem, (MainWindow::instance()->myMem.getSize())/20);
                selectedItemPtr->setText(2, "True");
            }
            else
            {
                QMessageBox::information(this,tr("Cannot Allocate"),tr("There is no enough memory"));
            }
        }
    }
    else if(allocationTypeEnum == allocationType::worstFit)
    {
        QTreeWidgetItem* selectedItemPtr = ui->processSegmentTreeWidget->currentItem();
        QString allocated = "True";
        if(selectedItemPtr == nullptr)
        {
            QMessageBox::information(this,tr("Cannot Allocate"),tr("Please select a process to allocate"));
        }
        else if (selectedItemPtr->data(2,0).toString() == allocated)
        {
            QMessageBox::information(this,tr("Cannot Allocate"),tr("This process is already allocated"));
        }
        else
        {
            long processId = std::stol((selectedItemPtr->data(0,0)).toString().toUtf8().constData());
            if(iteration != 0)
            {
                processId -= (staticLengthOfList+1);
            }
            list<Process>::iterator proIt = listOfInputProcesses.begin();
            std::advance(proIt, processId);
            Process inputToFn = *proIt;
            bool isAllocatedFlag = MainWindow::instance()->myMem.worst_fit_allocate(inputToFn);
            if(isAllocatedFlag)
            {
                Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
                Outputt::showOP(MainWindow::instance()->myMem, (MainWindow::instance()->myMem.getSize())/20);
                selectedItemPtr->setText(2, "True");
            }
            else
            {
                QMessageBox::information(this,tr("Cannot Allocate"),tr("This process is already allocated"));
            }
        }
    }
}

void processesinputform::on_deallocatePushButton_clicked()
{
    Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
    QTreeWidgetItem* selectedItemPtr = ui->processSegmentTreeWidget->currentItem();

    QString allocated = "False";

    if(selectedItemPtr == nullptr)
    {
        QMessageBox::information(this,tr("Cannot Deallocate"),tr("Please select a process to deallocate"));
    }
    else if (selectedItemPtr->data(2,0).toString() == allocated)
    {
        QMessageBox::information(this,tr("Cannot Deallocate"),tr("This process is already deallocated"));
    }
    else if (selectedItemPtr != nullptr)
    {
        long processId = std::stol((selectedItemPtr->data(0,0)).toString().toUtf8().constData());
        if(iteration != 0)
        {
            processId -= (staticLengthOfList+1);
        }
        list<Process>::iterator proIt = listOfInputProcesses.begin();
        std::advance(proIt, processId);
        Process inputToFn = *proIt;
        MainWindow::instance()->myMem.deallocate(inputToFn);
        Outputt::showOP(MainWindow::instance()->myMem, (MainWindow::instance()->myMem.getSize())/20);
        selectedItemPtr->setText(2, "False");
    }
    Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);

}

void processesinputform::on_drawPushButton_clicked()
{
    Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
    Outputt::showOP(MainWindow::instance()->myMem, (MainWindow::instance()->myMem.getSize())/20);
}

void processesinputform::on_firstFitCheckBox_stateChanged()
{
    if(ui->firstFitCheckBox->isChecked())
    {
        allocationTypeEnum = allocationType::firstFit;
        ui->bestFitCheckBox->setDisabled(true);
        ui->worstFitCheckBox->setDisabled(true);
    }
    else
    {
        allocationTypeEnum = allocationType::none;
        ui->bestFitCheckBox->setEnabled(true);
        ui->worstFitCheckBox->setEnabled(true);
        ui->firstFitCheckBox->setEnabled(true);
    }
}

void processesinputform::on_bestFitCheckBox_stateChanged()
{
    if(ui->bestFitCheckBox->isChecked())
    {
        allocationTypeEnum = allocationType::bestFit;
        ui->firstFitCheckBox->setDisabled(true);
        ui->worstFitCheckBox->setDisabled(true);
    }
    else
    {
        allocationTypeEnum = allocationType::none;
        ui->bestFitCheckBox->setEnabled(true);
        ui->worstFitCheckBox->setEnabled(true);
        ui->firstFitCheckBox->setEnabled(true);
    }
}

void processesinputform::on_worstFitCheckBox_stateChanged()
{
    if(ui->worstFitCheckBox->isChecked())
    {
        allocationTypeEnum = allocationType::worstFit;
        ui->bestFitCheckBox->setDisabled(true);
        ui->firstFitCheckBox->setDisabled(true);
    }
    else
    {
        allocationTypeEnum = allocationType::none;
        ui->bestFitCheckBox->setEnabled(true);
        ui->worstFitCheckBox->setEnabled(true);
        ui->firstFitCheckBox->setEnabled(true);
    }
}

void processesinputform::on_deallocatePushButton_2_clicked()
{
    Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
    QTreeWidgetItem* selectedOldItemPtr = ui->oldProcessTreeWidget->currentItem();

    QString allocated = "False";

    if(selectedOldItemPtr == nullptr)
    {
        QMessageBox::information(this,tr("Cannot Deallocate"),tr("Please select a process to deallocate"));
    }
    else if (selectedOldItemPtr != nullptr)
    {
        long itemBaseAdd =std::stol((selectedOldItemPtr->data(3,0)).toString().toUtf8().constData());
        for(oldIt = MainWindow::instance()->myMem.OldProcessSegmentsList.begin() ; oldIt != MainWindow::instance()->myMem.OldProcessSegmentsList.end(); ++oldIt)
        {
            if(itemBaseAdd == oldIt->getBase())
            {
                MainWindow::instance()->myMem.deallocate(*oldIt);
            }
        }
        Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
        Outputt::showOP(MainWindow::instance()->myMem, (MainWindow::instance()->myMem.getSize())/20);
        selectedOldItemPtr->setText(2, "False");
    }
    else
    {
        if(selectedOldItemPtr == nullptr)
        {
            QMessageBox::information(this,tr("Cannot Deallocate"),tr("Please select a process to deallocate"));
        }
    }
    Segment::collectFree(MainWindow::instance()->myMem.memorySegmentsList);
}
