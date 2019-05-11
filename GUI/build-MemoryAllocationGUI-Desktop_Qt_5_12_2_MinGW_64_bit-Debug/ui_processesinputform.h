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
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_2;
    QTreeWidget *treeWidget_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *processesinputform)
    {
        if (processesinputform->objectName().isEmpty())
            processesinputform->setObjectName(QString::fromUtf8("processesinputform"));
        processesinputform->resize(800, 600);
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
        verticalLayoutWidget->setGeometry(QRect(20, 40, 761, 501));
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
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_7->addWidget(label_3);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_7->addWidget(lineEdit);


        horizontalLayout_6->addLayout(horizontalLayout_7);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_6->addWidget(label_4);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_6->addWidget(spinBox_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_6->addWidget(pushButton);


        horizontalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 5);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_8->addWidget(label_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_9->addWidget(lineEdit_2);


        horizontalLayout_8->addLayout(horizontalLayout_9);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_8->addWidget(label_6);

        spinBox_3 = new QSpinBox(verticalLayoutWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        horizontalLayout_8->addWidget(spinBox_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_8->addWidget(pushButton_2);


        horizontalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(horizontalLayout_5);

        treeWidget_2 = new QTreeWidget(verticalLayoutWidget);
        treeWidget_2->setObjectName(QString::fromUtf8("treeWidget_2"));

        verticalLayout->addWidget(treeWidget_2);

        pushButton_3 = new QPushButton(processesinputform);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(340, 550, 111, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        retranslateUi(processesinputform);

        QMetaObject::connectSlotsByName(processesinputform);
    } // setupUi

    void retranslateUi(QWidget *processesinputform)
    {
        processesinputform->setWindowTitle(QApplication::translate("processesinputform", "Form", nullptr));
        label_3->setText(QApplication::translate("processesinputform", "Process Name", nullptr));
        label_4->setText(QApplication::translate("processesinputform", "Number of Segments", nullptr));
        pushButton->setText(QApplication::translate("processesinputform", "Add Process", nullptr));
        label_5->setText(QApplication::translate("processesinputform", "Segment Name", nullptr));
        label_6->setText(QApplication::translate("processesinputform", "Segment Size", nullptr));
        pushButton_2->setText(QApplication::translate("processesinputform", "Add Segment", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_2->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("processesinputform", "Segment Size", nullptr));
        ___qtreewidgetitem->setText(4, QApplication::translate("processesinputform", "Segment Name", nullptr));
        ___qtreewidgetitem->setText(3, QApplication::translate("processesinputform", "Segment ID", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("processesinputform", "Deallocate", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("processesinputform", "Allocate", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("processesinputform", "Process ID", nullptr));
        pushButton_3->setText(QApplication::translate("processesinputform", "GO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class processesinputform: public Ui_processesinputform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSESINPUTFORM_H
