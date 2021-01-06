/********************************************************************************
** Form generated from reading UI file 'afficherunpersonnel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHERUNPERSONNEL_H
#define UI_AFFICHERUNPERSONNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_afficherUnPersonnel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *matAffPers;
    QPushButton *rechAffPers;
    QTextBrowser *textAffichePers;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *imprimerBoutton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *afficherUnPersonnel)
    {
        if (afficherUnPersonnel->objectName().isEmpty())
            afficherUnPersonnel->setObjectName(QStringLiteral("afficherUnPersonnel"));
        afficherUnPersonnel->resize(851, 587);
        verticalLayout = new QVBoxLayout(afficherUnPersonnel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(afficherUnPersonnel);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        matAffPers = new QLineEdit(afficherUnPersonnel);
        matAffPers->setObjectName(QStringLiteral("matAffPers"));

        horizontalLayout->addWidget(matAffPers);

        rechAffPers = new QPushButton(afficherUnPersonnel);
        rechAffPers->setObjectName(QStringLiteral("rechAffPers"));

        horizontalLayout->addWidget(rechAffPers);


        verticalLayout->addLayout(horizontalLayout);

        textAffichePers = new QTextBrowser(afficherUnPersonnel);
        textAffichePers->setObjectName(QStringLiteral("textAffichePers"));

        verticalLayout->addWidget(textAffichePers);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        imprimerBoutton = new QPushButton(afficherUnPersonnel);
        imprimerBoutton->setObjectName(QStringLiteral("imprimerBoutton"));

        horizontalLayout_2->addWidget(imprimerBoutton);

        buttonBox = new QDialogButtonBox(afficherUnPersonnel);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(afficherUnPersonnel);
        QObject::connect(buttonBox, SIGNAL(accepted()), afficherUnPersonnel, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), afficherUnPersonnel, SLOT(reject()));

        QMetaObject::connectSlotsByName(afficherUnPersonnel);
    } // setupUi

    void retranslateUi(QDialog *afficherUnPersonnel)
    {
        afficherUnPersonnel->setWindowTitle(QApplication::translate("afficherUnPersonnel", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("afficherUnPersonnel", "Matricule", Q_NULLPTR));
        rechAffPers->setText(QApplication::translate("afficherUnPersonnel", "Rechercher", Q_NULLPTR));
        imprimerBoutton->setText(QApplication::translate("afficherUnPersonnel", "Imprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class afficherUnPersonnel: public Ui_afficherUnPersonnel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHERUNPERSONNEL_H
