/********************************************************************************
** Form generated from reading UI file 'statis.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIS_H
#define UI_STATIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_statis
{
public:
    QCustomPlot *widget;
    QPushButton *pushButton;

    void setupUi(QDialog *statis)
    {
        if (statis->objectName().isEmpty())
            statis->setObjectName(QStringLiteral("statis"));
        statis->resize(735, 401);
        widget = new QCustomPlot(statis);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 711, 321));
        pushButton = new QPushButton(statis);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 370, 93, 28));

        retranslateUi(statis);

        QMetaObject::connectSlotsByName(statis);
    } // setupUi

    void retranslateUi(QDialog *statis)
    {
        statis->setWindowTitle(QApplication::translate("statis", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("statis", "Retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statis: public Ui_statis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIS_H
