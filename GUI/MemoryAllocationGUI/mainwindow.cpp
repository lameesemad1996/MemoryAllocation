#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "processesinputform.h"
#include <QSpinBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTreeWidgetItemIterator>
#include "outputt.h"
#include "Segmentt.h"

MainWindow* MainWindow::s_instance = nullptr;

MainWindow* MainWindow::instance() { return s_instance; }

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    assert(!s_instance); //another instance already exists!
    s_instance = this;
    //MainWindow::mainWindowPtr = this;
    ui->holeStartSpinBox_2->setRange(0,10000000);
    ui->holeSizeSpinBox_2->setRange(0,10000000);
    ui->memorySizeSpinBox->setRange(0,10000000);
    totalHoleSize = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

Memory MainWindow::fillOldProcess(list<Segment> holesSegList, long memSize, bool &invalidTotalMemSizeFlag)
{
        Memory returnable;
        returnable.setSize(memSize);
        long ID = 0;

        //corner case: if no holes entered
        if (holesSegList.empty())
        {
            Segment newOldProSeg("Old Process", 0, memSize, Segment::oldProcess);
            newOldProSeg.setAllocated(true);
            returnable.OldProcessSegmentsList.push_back(newOldProSeg);
            returnable.memorySegmentsList.push_back(newOldProSeg);
            return returnable;
        }

        int lastAllocAdd = 0;
        list<Segment>::iterator it;

        Segment::sortSegListByBaseAdd_ascending(holesSegList);
        Segment::collect(holesSegList);

        long lastAddress = 0;

        for (it = holesSegList.begin(); it != holesSegList.end(); ++it)
        {
            Segment::sortSegListByBaseAdd_ascending(holesSegList);
            Segment::collect(holesSegList);

            //iterator to check if last element in list
            list<Segment>::iterator itLast = ++it;
            it--;

            //only the first iteration
            if (it == holesSegList.begin())
            {
                lastAllocAdd = 0;
                if (it->getBase() != 0)
                {
                    Segment newOldProSeg("Old Process", 0, it->getBase(), Segment::oldProcess);
                    lastAllocAdd = it->getBase() + it->getLimit();
                    newOldProSeg.setID(ID);
                    newOldProSeg.setAllocated(true);
                    returnable.OldProcessSegmentsList.push_back(newOldProSeg);
                    returnable.memorySegmentsList.push_back(newOldProSeg);
                    it->setID(ID + 1);
                    returnable.memorySegmentsList.push_back(*it);
                    ID += 2;
                }
                else
                {
                    it->setID(ID);
                    returnable.memorySegmentsList.push_back(*it);
                    ID++;
                    lastAllocAdd = it->getLimit();
                }
            }
            //iterations other than the first one
            else
            {
                //check if this is the last iteration to save the last address accessed
                list<Segment>::iterator newIt = ++it;
                it--;

                if (newIt == holesSegList.end())
                {
                    lastAddress = it->getBase() + it->getLimit() - 1;
                }

                long currentBase = it->getBase();
                it--;
                long prevBase = it->getBase();
                long prevLimit = it->getLimit();
                it++;

                if (currentBase < (prevBase + prevLimit))
                {
                    std::cout << "This is not a valid hole." << endl;
                    continue;
                }

                if (currentBase != lastAllocAdd)
                {
                    Segment newOldProSeg("Old Process", lastAllocAdd, currentBase - lastAllocAdd, Segment::oldProcess);
                    newOldProSeg.setID(ID);
                    newOldProSeg.setAllocated(true);
                    returnable.OldProcessSegmentsList.push_back(newOldProSeg);
                    returnable.memorySegmentsList.push_back(newOldProSeg);
                    it->setID(ID + 1);
                    returnable.memorySegmentsList.push_back(*it);
                    ID += 2;
                    lastAllocAdd = it->getBase() + it->getLimit();
                }
                else
                {
                    it->setID(ID);
                    returnable.memorySegmentsList.push_back(*it);
                    ID++;
                    lastAllocAdd = it->getBase() + it->getLimit();
                }
            }
        }
        if (lastAddress >= memSize)
        {
            std::cout << "This memory is too small." << endl;
            invalidTotalMemSizeFlag = true;
        }
        else if (lastAllocAdd < memSize - 1)
        {
            Segment newOldProSeg("Old Process", lastAllocAdd, memSize - lastAllocAdd, Segment::oldProcess);
            newOldProSeg.setID(ID);
            newOldProSeg.setAllocated(true);
            returnable.OldProcessSegmentsList.push_back(newOldProSeg);
            returnable.memorySegmentsList.push_back(newOldProSeg);
        }
        return returnable;
}

void MainWindow::on_addHolePushButton_clicked()
{
    long holeStartAddress = ui->holeStartSpinBox_2->value();
    long holeSize = ui->holeSizeSpinBox_2->value();
    totalHoleSize += holeSize;
    Segment newhole("Free", holeStartAddress, holeSize, Segment::free);
    holesList.push_back(newhole);
    QTreeWidgetItem *newHoleItem = new QTreeWidgetItem(ui->HoleTreeWidget);
    newHoleItem->setText(0,QString::fromStdString(to_string(newhole.getID())));
    newHoleItem->setText(1,QString::fromStdString(to_string(newhole.getBase())));
    newHoleItem->setText(2,QString::fromStdString(to_string(newhole.getLimit())));
    ui->HoleTreeWidget->addTopLevelItem(newHoleItem);
    ui->holeSizeSpinBox_2->setValue(0);
    ui->holeStartSpinBox_2->setValue(0);
}

void MainWindow::on_enterProcessesPushButton_clicked()
{
    long memSize = ui->memorySizeSpinBox->value();
    this->myMem = fillOldProcess(holesList, memSize, this->invalidTotalMemSizeFlag);
    //this->oldProcessList = Segment::filterOldProcess(myMem.memorySegmentsList);
    //Outputt::showOP(myMem, memSize/20);
    processesinputform* processInputForm = new processesinputform();
    processInputForm->setFixedSize(950,850);
    QMainWindow* processWindowPtr = new QMainWindow();
    processWindowPtr->setWindowModality(Qt::WindowModal);
    processWindowPtr->setCentralWidget(processInputForm);
    processWindowPtr->adjustSize();
    processWindowPtr->show();
}
