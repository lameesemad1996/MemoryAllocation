/********************************************************************************
** Form generated from reading UI file 'holessinputform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOLESSINPUTFORM_H
#define UI_HOLESSINPUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_holessinputform
{
public:
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *spinBox_3;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_2;
    QTreeWidget *treeWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QWidget *holessinputform)
    {
        if (holessinputform->objectName().isEmpty())
            holessinputform->setObjectName(QString::fromUtf8("holessinputform"));
        holessinputform->resize(564, 450);
        pushButton = new QPushButton(holessinputform);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 390, 111, 28));
        pushButton->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));
        verticalLayoutWidget = new QWidget(holessinputform);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 90, 451, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: bold large \"Arial\""));

        verticalLayout->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 5);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_6->addWidget(label_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        spinBox_3 = new QSpinBox(verticalLayoutWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        horizontalLayout_7->addWidget(spinBox_3);


        horizontalLayout_6->addLayout(horizontalLayout_7);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));

        horizontalLayout_6->addWidget(label_4);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_6->addWidget(spinBox_2);


        horizontalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_4);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("margin-bottom: 5px;\n"
"font: large \"Arial\""));

        verticalLayout->addWidget(pushButton_2);

        treeWidget = new QTreeWidget(verticalLayoutWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        horizontalLayoutWidget = new QWidget(holessinputform);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(180, 30, 161, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: bold large \"Arial\""));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(horizontalLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);


        retranslateUi(holessinputform);

        QMetaObject::connectSlotsByName(holessinputform);
    } // setupUi

    void retranslateUi(QWidget *holessinputform)
    {
        holessinputform->setWindowTitle(QApplication::translate("holessinputform", "Form", nullptr));
        pushButton->setText(QApplication::translate("holessinputform", "Go to Processes", nullptr));
        label_2->setText(QApplication::translate("holessinputform", "Hole Details", nullptr));
        label_3->setText(QApplication::translate("holessinputform", "Hole Start ", nullptr));
        label_4->setText(QApplication::translate("holessinputform", "Hole Size", nullptr));
        pushButton_2->setText(QApplication::translate("holessinputform", "Add Hole", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("holessinputform", "Size", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("holessinputform", "Start Address", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("holessinputform", "ID", nullptr));
        label->setText(QApplication::translate("holessinputform", "Memory Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class holessinputform: public Ui_holessinputform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOLESSINPUTFORM_H
