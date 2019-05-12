/********************************************************************************
** Form generated from reading UI file 'processesinputform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSESINPUTFORM_H
#define UI_PROCESSESINPUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_processesinputform
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *processNameLabel;
    QLineEdit *processNameLineEdit;
    QLabel *noOfSegLabel;
    QSpinBox *noOfSegSpinBox;
    QPushButton *addProcessPushButton;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *segNameLabel;
    QLineEdit *segNameLineEdit;
    QLabel *segSizeLabel;
    QSpinBox *segSizeSpinBox;
    QPushButton *addSegmentPushButton;
    QTreeWidget *processSegmentTreeWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *firstFitCheckBox;
    QCheckBox *bestFitCheckBox;
    QCheckBox *worstFitCheckBox;
    QPushButton *allocatePushButton;
    QPushButton *deallocatePushButton;
    QPushButton *drawPushButton;
    QTreeWidget *oldProcessTreeWidget;
    QLabel *oldProcessLabel;

    void setupUi(QWidget *processesinputform)
    {
        if (processesinputform->objectName().isEmpty())
            processesinputform->setObjectName(QString::fromUtf8("processesinputform"));
        processesinputform->resize(950, 850);
        processesinputform->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayoutWidget = new QWidget(processesinputform);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 761, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 5);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        processNameLabel = new QLabel(verticalLayoutWidget);
        processNameLabel->setObjectName(QString::fromUtf8("processNameLabel"));
        processNameLabel->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_7->addWidget(processNameLabel);

        processNameLineEdit = new QLineEdit(verticalLayoutWidget);
        processNameLineEdit->setObjectName(QString::fromUtf8("processNameLineEdit"));

        horizontalLayout_7->addWidget(processNameLineEdit);


        horizontalLayout_6->addLayout(horizontalLayout_7);

        noOfSegLabel = new QLabel(verticalLayoutWidget);
        noOfSegLabel->setObjectName(QString::fromUtf8("noOfSegLabel"));
        noOfSegLabel->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_6->addWidget(noOfSegLabel);

        noOfSegSpinBox = new QSpinBox(verticalLayoutWidget);
        noOfSegSpinBox->setObjectName(QString::fromUtf8("noOfSegSpinBox"));

        horizontalLayout_6->addWidget(noOfSegSpinBox);

        addProcessPushButton = new QPushButton(verticalLayoutWidget);
        addProcessPushButton->setObjectName(QString::fromUtf8("addProcessPushButton"));
        addProcessPushButton->setEnabled(true);
        addProcessPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"	padding: 4px;\n"
"    border-radius:  6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"	font: large \"Arial\";\n"
"	margin-left: 30px;\n"
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
"}\n"
""));

        horizontalLayout_6->addWidget(addProcessPushButton);


        horizontalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 5);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        segNameLabel = new QLabel(verticalLayoutWidget);
        segNameLabel->setObjectName(QString::fromUtf8("segNameLabel"));
        segNameLabel->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_8->addWidget(segNameLabel);

        segNameLineEdit = new QLineEdit(verticalLayoutWidget);
        segNameLineEdit->setObjectName(QString::fromUtf8("segNameLineEdit"));

        horizontalLayout_8->addWidget(segNameLineEdit);

        segSizeLabel = new QLabel(verticalLayoutWidget);
        segSizeLabel->setObjectName(QString::fromUtf8("segSizeLabel"));
        segSizeLabel->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_8->addWidget(segSizeLabel);

        segSizeSpinBox = new QSpinBox(verticalLayoutWidget);
        segSizeSpinBox->setObjectName(QString::fromUtf8("segSizeSpinBox"));

        horizontalLayout_8->addWidget(segSizeSpinBox);

        addSegmentPushButton = new QPushButton(verticalLayoutWidget);
        addSegmentPushButton->setObjectName(QString::fromUtf8("addSegmentPushButton"));
        addSegmentPushButton->setEnabled(true);
        addSegmentPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"	padding: 4px;\n"
"    border-radius:  6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"	font: large \"Arial\";\n"
"	margin-left: 30px;\n"
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
"}\n"
""));

        horizontalLayout_8->addWidget(addSegmentPushButton);


        horizontalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(horizontalLayout_5);

        processSegmentTreeWidget = new QTreeWidget(verticalLayoutWidget);
        processSegmentTreeWidget->setObjectName(QString::fromUtf8("processSegmentTreeWidget"));

        verticalLayout->addWidget(processSegmentTreeWidget);

        verticalLayoutWidget_2 = new QWidget(processesinputform);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(800, 220, 131, 182));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        firstFitCheckBox = new QCheckBox(verticalLayoutWidget_2);
        firstFitCheckBox->setObjectName(QString::fromUtf8("firstFitCheckBox"));

        verticalLayout_2->addWidget(firstFitCheckBox);

        bestFitCheckBox = new QCheckBox(verticalLayoutWidget_2);
        bestFitCheckBox->setObjectName(QString::fromUtf8("bestFitCheckBox"));

        verticalLayout_2->addWidget(bestFitCheckBox);

        worstFitCheckBox = new QCheckBox(verticalLayoutWidget_2);
        worstFitCheckBox->setObjectName(QString::fromUtf8("worstFitCheckBox"));

        verticalLayout_2->addWidget(worstFitCheckBox);

        allocatePushButton = new QPushButton(verticalLayoutWidget_2);
        allocatePushButton->setObjectName(QString::fromUtf8("allocatePushButton"));
        allocatePushButton->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        allocatePushButton->setFont(font);
        allocatePushButton->setStyleSheet(QString::fromUtf8("margin-bottom: 10px;\n"
"margin-top: 3px;\n"
"font: large \"Arial\";"));

        verticalLayout_2->addWidget(allocatePushButton);

        deallocatePushButton = new QPushButton(verticalLayoutWidget_2);
        deallocatePushButton->setObjectName(QString::fromUtf8("deallocatePushButton"));
        deallocatePushButton->setEnabled(true);
        deallocatePushButton->setFont(font);
        deallocatePushButton->setStyleSheet(QString::fromUtf8("margin-bottom: 10px;\n"
"font: large \"Arial\""));

        verticalLayout_2->addWidget(deallocatePushButton);

        drawPushButton = new QPushButton(verticalLayoutWidget_2);
        drawPushButton->setObjectName(QString::fromUtf8("drawPushButton"));
        drawPushButton->setEnabled(true);
        drawPushButton->setFont(font);
        drawPushButton->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        verticalLayout_2->addWidget(drawPushButton);

        oldProcessTreeWidget = new QTreeWidget(processesinputform);
        oldProcessTreeWidget->setObjectName(QString::fromUtf8("oldProcessTreeWidget"));
        oldProcessTreeWidget->setGeometry(QRect(20, 560, 631, 261));
        oldProcessLabel = new QLabel(processesinputform);
        oldProcessLabel->setObjectName(QString::fromUtf8("oldProcessLabel"));
        oldProcessLabel->setGeometry(QRect(30, 530, 151, 26));
        oldProcessLabel->setStyleSheet(QString::fromUtf8("font: large \"Arial\";\n"
"font-size: 14px;"));

        retranslateUi(processesinputform);

        QMetaObject::connectSlotsByName(processesinputform);
    } // setupUi

    void retranslateUi(QWidget *processesinputform)
    {
        processesinputform->setWindowTitle(QApplication::translate("processesinputform", "Form", nullptr));
        processNameLabel->setText(QApplication::translate("processesinputform", "Process Name", nullptr));
        noOfSegLabel->setText(QApplication::translate("processesinputform", "Number of Segments", nullptr));
        addProcessPushButton->setText(QApplication::translate("processesinputform", "Add Process", nullptr));
        segNameLabel->setText(QApplication::translate("processesinputform", "Segment Name", nullptr));
        segSizeLabel->setText(QApplication::translate("processesinputform", "Segment Size", nullptr));
        addSegmentPushButton->setText(QApplication::translate("processesinputform", "Add Segment", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = processSegmentTreeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("processesinputform", "Segment Size", nullptr));
        ___qtreewidgetitem->setText(4, QApplication::translate("processesinputform", "Segment Name", nullptr));
        ___qtreewidgetitem->setText(3, QApplication::translate("processesinputform", "Segment ID", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("processesinputform", "Allocated", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("processesinputform", "Process Name", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("processesinputform", "Process ID", nullptr));
        firstFitCheckBox->setText(QApplication::translate("processesinputform", "First Fit", nullptr));
        bestFitCheckBox->setText(QApplication::translate("processesinputform", "Best Fit", nullptr));
        worstFitCheckBox->setText(QApplication::translate("processesinputform", "Worst Fit", nullptr));
        allocatePushButton->setText(QApplication::translate("processesinputform", "Allocate", nullptr));
        deallocatePushButton->setText(QApplication::translate("processesinputform", "Deallocate", nullptr));
        drawPushButton->setText(QApplication::translate("processesinputform", "Show", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = oldProcessTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(4, QApplication::translate("processesinputform", "Segment Size", nullptr));
        ___qtreewidgetitem1->setText(3, QApplication::translate("processesinputform", "Start Address", nullptr));
        ___qtreewidgetitem1->setText(2, QApplication::translate("processesinputform", "Allocated", nullptr));
        ___qtreewidgetitem1->setText(1, QApplication::translate("processesinputform", "Segment Name", nullptr));
        ___qtreewidgetitem1->setText(0, QApplication::translate("processesinputform", "Segment ID", nullptr));
        oldProcessLabel->setText(QApplication::translate("processesinputform", "Old Process Segments", nullptr));
    } // retranslateUi

};

namespace Ui {
    class processesinputform: public Ui_processesinputform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSESINPUTFORM_H
