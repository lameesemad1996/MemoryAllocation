#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "Memoryy.h"
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* instance();
    //static QWidget* mainWindowPtr;
    Memory myMem;
    list<Segment> holesList;
    //list<Segment> oldProcessList;
    long totalHoleSize;
    bool invalidTotalMemSizeFlag;
    Memory fillOldProcess(list<Segment> holesSegList, long memSize, bool &invalidTotalMemSizeFlag);
    long sumAddHolePressed;

private:
    static MainWindow* s_instance;

private slots:

    void on_addHolePushButton_clicked();

    void on_enterProcessesPushButton_clicked();


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
