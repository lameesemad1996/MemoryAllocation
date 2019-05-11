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
    QPushButton *enterProcessesPushButton;
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

    void setupUi(QWidget *holessinputform)
    {
        if (holessinputform->objectName().isEmpty())
            holessinputform->setObjectName(QString::fromUtf8("holessinputform"));
        holessinputform->resize(791, 599);
        enterProcessesPushButton = new QPushButton(holessinputform);
        enterProcessesPushButton->setObjectName(QString::fromUtf8("enterProcessesPushButton"));
        enterProcessesPushButton->setGeometry(QRect(220, 390, 111, 28));
        enterProcessesPushButton->setStyleSheet(QString::fromUtf8("font: large \"Arial\""));
        verticalLayoutWidget = new QWidget(holessinputform);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 90, 451, 291));
        holeDetailsVerticalLayout = new QVBoxLayout(verticalLayoutWidget);
        holeDetailsVerticalLayout->setObjectName(QString::fromUtf8("holeDetailsVerticalLayout"));
        holeDetailsVerticalLayout->setContentsMargins(0, 0, 0, 0);
        holeDetailsLabel = new QLabel(verticalLayoutWidget);
        holeDetailsLabel->setObjectName(QString::fromUtf8("holeDetailsLabel"));
        holeDetailsLabel->setStyleSheet(QString::fromUtf8("font: bold large \"Arial\""));

        holeDetailsVerticalLayout->addWidget(holeDetailsLabel);

        holeDetailsHorizontalLayout = new QHBoxLayout();
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
        addHolePushButton->setStyleSheet(QString::fromUtf8("margin-bottom: 5px;\n"
"font: large \"Arial\""));

        holeDetailsVerticalLayout->addWidget(addHolePushButton);

        HoleTreeWidget = new QTreeWidget(verticalLayoutWidget);
        HoleTreeWidget->setObjectName(QString::fromUtf8("HoleTreeWidget"));

        holeDetailsVerticalLayout->addWidget(HoleTreeWidget);

        horizontalLayoutWidget = new QWidget(holessinputform);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(180, 30, 161, 51));
        memorySizeHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        memorySizeHorizontalLayout->setObjectName(QString::fromUtf8("memorySizeHorizontalLayout"));
        memorySizeHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        memorySizeLabel = new QLabel(horizontalLayoutWidget);
        memorySizeLabel->setObjectName(QString::fromUtf8("memorySizeLabel"));
        memorySizeLabel->setStyleSheet(QString::fromUtf8("font: bold large \"Arial\""));

        memorySizeHorizontalLayout->addWidget(memorySizeLabel);

        memorySizeSpinBox = new QSpinBox(horizontalLayoutWidget);
        memorySizeSpinBox->setObjectName(QString::fromUtf8("memorySizeSpinBox"));

        memorySizeHorizontalLayout->addWidget(memorySizeSpinBox);


        retranslateUi(holessinputform);

        QMetaObject::connectSlotsByName(holessinputform);
    } // setupUi

    void retranslateUi(QWidget *holessinputform)
    {
        holessinputform->setWindowTitle(QApplication::translate("holessinputform", "Form", nullptr));
        enterProcessesPushButton->setText(QApplication::translate("holessinputform", "Enter Proccesses", nullptr));
        holeDetailsLabel->setText(QApplication::translate("holessinputform", "Hole Details", nullptr));
        holeStartLabel_2->setText(QApplication::translate("holessinputform", "Hole Start ", nullptr));
        holeSizeLabel_2->setText(QApplication::translate("holessinputform", "Hole Size", nullptr));
        addHolePushButton->setText(QApplication::translate("holessinputform", "Add Hole", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = HoleTreeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("holessinputform", "Size", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("holessinputform", "Start Address", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("holessinputform", "ID", nullptr));
        memorySizeLabel->setText(QApplication::translate("holessinputform", "Memory Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class holessinputform: public Ui_holessinputform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOLESSINPUTFORM_H
