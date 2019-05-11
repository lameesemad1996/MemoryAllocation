/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_firstFit;
    QPushButton *pushButton_bestFit;
    QPushButton *pushButton_worstFit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(579, 341);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 239, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_firstFit = new QPushButton(centralWidget);
        pushButton_firstFit->setObjectName(QString::fromUtf8("pushButton_firstFit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight SemiConde"));
        font.setPointSize(14);
        pushButton_firstFit->setFont(font);
        pushButton_firstFit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 6px;\n"
"	border: 1px solid gray;\n"
"	background-color: 	rgb(247, 207, 87);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        verticalLayout->addWidget(pushButton_firstFit);

        pushButton_bestFit = new QPushButton(centralWidget);
        pushButton_bestFit->setObjectName(QString::fromUtf8("pushButton_bestFit"));
        pushButton_bestFit->setFont(font);
        pushButton_bestFit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: 	rgb(153, 157, 237);\n"
"	border: 1px solid gray;\n"
"	border-radius: 6px;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        verticalLayout->addWidget(pushButton_bestFit);

        pushButton_worstFit = new QPushButton(centralWidget);
        pushButton_worstFit->setObjectName(QString::fromUtf8("pushButton_worstFit"));
        pushButton_worstFit->setFont(font);
        pushButton_worstFit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 6px;\n"
"	border: 1px solid gray;\n"
"	background-color: 	rgb(247, 207, 87);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));

        verticalLayout->addWidget(pushButton_worstFit);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_firstFit->setText(QApplication::translate("MainWindow", "First Fit", nullptr));
        pushButton_bestFit->setText(QApplication::translate("MainWindow", "Best Fit", nullptr));
        pushButton_worstFit->setText(QApplication::translate("MainWindow", "Worst Fit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
