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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *holeDetailsVerticalLayout;
    QLabel *holeDetailsLabel;
    QHBoxLayout *holeDetailsHorizontalLayout;
    QLabel *holeStartLabel_2;
    QSpinBox *holeStartSpinBox_2;
    QLabel *holeSizeLabel_2;
    QSpinBox *holeSizeSpinBox_2;
    QPushButton *addHolePushButton;
    QTreeWidget *HoleTreeWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *memorySizeHorizontalLayout;
    QLabel *memorySizeLabel;
    QSpinBox *memorySizeSpinBox;
    QPushButton *enterProcessesPushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(598, 460);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius:  6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 90, 451, 291));
        holeDetailsVerticalLayout = new QVBoxLayout(verticalLayoutWidget);
        holeDetailsVerticalLayout->setSpacing(6);
        holeDetailsVerticalLayout->setContentsMargins(11, 11, 11, 11);
        holeDetailsVerticalLayout->setObjectName(QString::fromUtf8("holeDetailsVerticalLayout"));
        holeDetailsVerticalLayout->setContentsMargins(0, 0, 0, 20);
        holeDetailsLabel = new QLabel(verticalLayoutWidget);
        holeDetailsLabel->setObjectName(QString::fromUtf8("holeDetailsLabel"));
        holeDetailsLabel->setStyleSheet(QString::fromUtf8("font: bold large \"Arial\""));

        holeDetailsVerticalLayout->addWidget(holeDetailsLabel);

        holeDetailsHorizontalLayout = new QHBoxLayout();
        holeDetailsHorizontalLayout->setSpacing(6);
        holeDetailsHorizontalLayout->setObjectName(QString::fromUtf8("holeDetailsHorizontalLayout"));
        holeStartLabel_2 = new QLabel(verticalLayoutWidget);
        holeStartLabel_2->setObjectName(QString::fromUtf8("holeStartLabel_2"));
        holeStartLabel_2->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        holeDetailsHorizontalLayout->addWidget(holeStartLabel_2);

        holeStartSpinBox_2 = new QSpinBox(verticalLayoutWidget);
        holeStartSpinBox_2->setObjectName(QString::fromUtf8("holeStartSpinBox_2"));

        holeDetailsHorizontalLayout->addWidget(holeStartSpinBox_2);

        holeSizeLabel_2 = new QLabel(verticalLayoutWidget);
        holeSizeLabel_2->setObjectName(QString::fromUtf8("holeSizeLabel_2"));
        holeSizeLabel_2->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        holeDetailsHorizontalLayout->addWidget(holeSizeLabel_2);

        holeSizeSpinBox_2 = new QSpinBox(verticalLayoutWidget);
        holeSizeSpinBox_2->setObjectName(QString::fromUtf8("holeSizeSpinBox_2"));

        holeDetailsHorizontalLayout->addWidget(holeSizeSpinBox_2);


        holeDetailsVerticalLayout->addLayout(holeDetailsHorizontalLayout);

        addHolePushButton = new QPushButton(verticalLayoutWidget);
        addHolePushButton->setObjectName(QString::fromUtf8("addHolePushButton"));
        addHolePushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius:  6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"	margin-bottom: 20px;\n"
"	margin-top: 10px;\n"
"	font: large \"Arial\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy;\n"
"}\n"
""));

        holeDetailsVerticalLayout->addWidget(addHolePushButton);

        HoleTreeWidget = new QTreeWidget(verticalLayoutWidget);
        HoleTreeWidget->setObjectName(QString::fromUtf8("HoleTreeWidget"));
        HoleTreeWidget->setStyleSheet(QString::fromUtf8(""));

        holeDetailsVerticalLayout->addWidget(HoleTreeWidget);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(180, 30, 201, 51));
        memorySizeHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        memorySizeHorizontalLayout->setSpacing(6);
        memorySizeHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        memorySizeHorizontalLayout->setObjectName(QString::fromUtf8("memorySizeHorizontalLayout"));
        memorySizeHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        memorySizeLabel = new QLabel(horizontalLayoutWidget);
        memorySizeLabel->setObjectName(QString::fromUtf8("memorySizeLabel"));
        memorySizeLabel->setStyleSheet(QString::fromUtf8("font: bold large \"Arial\""));

        memorySizeHorizontalLayout->addWidget(memorySizeLabel);

        memorySizeSpinBox = new QSpinBox(horizontalLayoutWidget);
        memorySizeSpinBox->setObjectName(QString::fromUtf8("memorySizeSpinBox"));

        memorySizeHorizontalLayout->addWidget(memorySizeSpinBox);

        enterProcessesPushButton = new QPushButton(centralWidget);
        enterProcessesPushButton->setObjectName(QString::fromUtf8("enterProcessesPushButton"));
        enterProcessesPushButton->setGeometry(QRect(240, 390, 111, 28));
        enterProcessesPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius:  6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy;\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        holeDetailsLabel->setText(QApplication::translate("MainWindow", "Hole Details", nullptr));
        holeStartLabel_2->setText(QApplication::translate("MainWindow", "Hole Start ", nullptr));
        holeSizeLabel_2->setText(QApplication::translate("MainWindow", "Hole Size", nullptr));
        addHolePushButton->setText(QApplication::translate("MainWindow", "Add Hole", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = HoleTreeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Size", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Start Address", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "ID", nullptr));
        memorySizeLabel->setText(QApplication::translate("MainWindow", "Memory Size", nullptr));
        enterProcessesPushButton->setText(QApplication::translate("MainWindow", "Enter Proccesses", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
