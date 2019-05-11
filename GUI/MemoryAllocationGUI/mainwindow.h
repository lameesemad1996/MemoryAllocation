#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "Memoryy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Memory myMem;
    list<Segment> holesList;
    list<Segment> oldProcessList;
    long totalHoleSize;
    bool invalidTotalMemSizeFlag;
    Memory fillOldProcess(list<Segment> holesSegList, long memSize, bool &invalidTotalMemSizeFlag);

private slots:

    void on_addHolePushButton_clicked();

    void on_enterProcessesPushButton_clicked();


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
