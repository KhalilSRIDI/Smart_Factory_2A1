/********************************************************************************
** Form generated from reading UI file 'modifierprofil.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERPROFIL_H
#define UI_MODIFIERPROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_modifierProfil
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *modifierProfil)
    {
        if (modifierProfil->objectName().isEmpty())
            modifierProfil->setObjectName(QStringLiteral("modifierProfil"));
        modifierProfil->resize(400, 300);
        buttonBox = new QDialogButtonBox(modifierProfil);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(modifierProfil);
        QObject::connect(buttonBox, SIGNAL(accepted()), modifierProfil, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), modifierProfil, SLOT(reject()));

        QMetaObject::connectSlotsByName(modifierProfil);
    } // setupUi

    void retranslateUi(QDialog *modifierProfil)
    {
        modifierProfil->setWindowTitle(QApplication::translate("modifierProfil", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class modifierProfil: public Ui_modifierProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERPROFIL_H
