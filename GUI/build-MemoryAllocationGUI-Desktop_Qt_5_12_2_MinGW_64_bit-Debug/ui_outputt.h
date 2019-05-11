/********************************************************************************
** Form generated from reading UI file 'outputt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTT_H
#define UI_OUTPUTT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Outputt
{
public:

    void setupUi(QWidget *Outputt)
    {
        if (Outputt->objectName().isEmpty())
            Outputt->setObjectName(QString::fromUtf8("Outputt"));
        Outputt->resize(400, 300);

        retranslateUi(Outputt);

        QMetaObject::connectSlotsByName(Outputt);
    } // setupUi

    void retranslateUi(QWidget *Outputt)
    {
        Outputt->setWindowTitle(QApplication::translate("Outputt", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Outputt: public Ui_Outputt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTT_H
