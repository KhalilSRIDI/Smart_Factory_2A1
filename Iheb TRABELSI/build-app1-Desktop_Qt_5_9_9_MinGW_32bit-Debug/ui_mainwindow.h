/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Client;
    QGroupBox *groupBoxAjouterC;
    QLabel *label_4;
    QLineEdit *lineEditId;
    QLabel *label_5;
    QLineEdit *lineEditStatut;
    QLineEdit *lineEditQuantitearticles;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *lineEditProduitAchete;
    QPushButton *pushButtonAjouter;
    QPushButton *pushButtonAnnuler;
    QGroupBox *groupBoxConsulterC;
    QTableWidget *tableWidgetClient;
    QPushButton *pushButtonRechercher;
    QPushButton *pushButtonModifier;
    QPushButton *pushButtonSupprimer;
    QCheckBox *checkBoxExcel;
    QCheckBox *checkBoxPDF;
    QPushButton *pushButtonExport;
    QLineEdit *lineEdit_Rechercher;
    QPushButton *pushButtonRetour;
    QPushButton *pushButtonMenuPrincipal;
    QWidget *Commande;
    QGroupBox *groupBoxConsulterC_2;
    QTableWidget *tableWidgetClient_2;
    QPushButton *pushButtonRechercher_2;
    QPushButton *pushButtonModifier_2;
    QPushButton *pushButtonSupprimer_2;
    QCheckBox *checkBoxExcel_2;
    QCheckBox *checkBoxPDF_2;
    QPushButton *pushButtonExport_2;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBoxAjouterC_2;
    QLabel *label_10;
    QLineEdit *lineEditIDCOMMANDE;
    QLabel *label_11;
    QLineEdit *lineEditRefferenceCommande;
    QLabel *label_12;
    QLineEdit *lineEditQuantite;
    QLabel *label_13;
    QLineEdit *lineEditID;
    QLabel *label_14;
    QComboBox *DateEditCommande_2;
    QLabel *label_15;
    QLineEdit *lineEditEtat;
    QPushButton *pushButtonAjouter_2;
    QPushButton *pushButtonAnnuler_2;
    QPushButton *pushButtonRetour_2;
    QPushButton *pushButtonMenuPrincipal_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1229, 678);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 80, 1141, 521));
        Client = new QWidget();
        Client->setObjectName(QStringLiteral("Client"));
        groupBoxAjouterC = new QGroupBox(Client);
        groupBoxAjouterC->setObjectName(QStringLiteral("groupBoxAjouterC"));
        groupBoxAjouterC->setGeometry(QRect(40, 30, 331, 401));
        label_4 = new QLabel(groupBoxAjouterC);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 131, 41));
        lineEditId = new QLineEdit(groupBoxAjouterC);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));
        lineEditId->setGeometry(QRect(200, 40, 113, 22));
        label_5 = new QLabel(groupBoxAjouterC);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 81, 161, 31));
        lineEditStatut = new QLineEdit(groupBoxAjouterC);
        lineEditStatut->setObjectName(QStringLiteral("lineEditStatut"));
        lineEditStatut->setGeometry(QRect(200, 140, 113, 22));
        lineEditQuantitearticles = new QLineEdit(groupBoxAjouterC);
        lineEditQuantitearticles->setObjectName(QStringLiteral("lineEditQuantitearticles"));
        lineEditQuantitearticles->setGeometry(QRect(200, 90, 113, 22));
        label_7 = new QLabel(groupBoxAjouterC);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 130, 121, 31));
        label_9 = new QLabel(groupBoxAjouterC);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 180, 121, 31));
        lineEditProduitAchete = new QLineEdit(groupBoxAjouterC);
        lineEditProduitAchete->setObjectName(QStringLiteral("lineEditProduitAchete"));
        lineEditProduitAchete->setGeometry(QRect(200, 190, 113, 22));
        pushButtonAjouter = new QPushButton(groupBoxAjouterC);
        pushButtonAjouter->setObjectName(QStringLiteral("pushButtonAjouter"));
        pushButtonAjouter->setGeometry(QRect(110, 330, 93, 28));
        pushButtonAnnuler = new QPushButton(groupBoxAjouterC);
        pushButtonAnnuler->setObjectName(QStringLiteral("pushButtonAnnuler"));
        pushButtonAnnuler->setGeometry(QRect(220, 330, 93, 28));
        groupBoxConsulterC = new QGroupBox(Client);
        groupBoxConsulterC->setObjectName(QStringLiteral("groupBoxConsulterC"));
        groupBoxConsulterC->setGeometry(QRect(390, 30, 721, 421));
        tableWidgetClient = new QTableWidget(groupBoxConsulterC);
        if (tableWidgetClient->columnCount() < 4)
            tableWidgetClient->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetClient->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetClient->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetClient->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetClient->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidgetClient->rowCount() < 3)
            tableWidgetClient->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetClient->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetClient->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetClient->setVerticalHeaderItem(2, __qtablewidgetitem6);
        tableWidgetClient->setObjectName(QStringLiteral("tableWidgetClient"));
        tableWidgetClient->setGeometry(QRect(30, 110, 601, 251));
        pushButtonRechercher = new QPushButton(groupBoxConsulterC);
        pushButtonRechercher->setObjectName(QStringLiteral("pushButtonRechercher"));
        pushButtonRechercher->setGeometry(QRect(260, 30, 93, 28));
        pushButtonModifier = new QPushButton(groupBoxConsulterC);
        pushButtonModifier->setObjectName(QStringLiteral("pushButtonModifier"));
        pushButtonModifier->setGeometry(QRect(310, 380, 141, 28));
        pushButtonSupprimer = new QPushButton(groupBoxConsulterC);
        pushButtonSupprimer->setObjectName(QStringLiteral("pushButtonSupprimer"));
        pushButtonSupprimer->setGeometry(QRect(480, 380, 141, 28));
        checkBoxExcel = new QCheckBox(groupBoxConsulterC);
        checkBoxExcel->setObjectName(QStringLiteral("checkBoxExcel"));
        checkBoxExcel->setGeometry(QRect(490, 80, 83, 22));
        checkBoxPDF = new QCheckBox(groupBoxConsulterC);
        checkBoxPDF->setObjectName(QStringLiteral("checkBoxPDF"));
        checkBoxPDF->setGeometry(QRect(490, 50, 83, 22));
        pushButtonExport = new QPushButton(groupBoxConsulterC);
        pushButtonExport->setObjectName(QStringLiteral("pushButtonExport"));
        pushButtonExport->setGeometry(QRect(480, 20, 70, 30));
        lineEdit_Rechercher = new QLineEdit(groupBoxConsulterC);
        lineEdit_Rechercher->setObjectName(QStringLiteral("lineEdit_Rechercher"));
        lineEdit_Rechercher->setGeometry(QRect(19, 30, 221, 31));
        pushButtonRetour = new QPushButton(Client);
        pushButtonRetour->setObjectName(QStringLiteral("pushButtonRetour"));
        pushButtonRetour->setGeometry(QRect(540, 460, 111, 28));
        pushButtonMenuPrincipal = new QPushButton(Client);
        pushButtonMenuPrincipal->setObjectName(QStringLiteral("pushButtonMenuPrincipal"));
        pushButtonMenuPrincipal->setGeometry(QRect(680, 460, 111, 28));
        tabWidget->addTab(Client, QString());
        Commande = new QWidget();
        Commande->setObjectName(QStringLiteral("Commande"));
        groupBoxConsulterC_2 = new QGroupBox(Commande);
        groupBoxConsulterC_2->setObjectName(QStringLiteral("groupBoxConsulterC_2"));
        groupBoxConsulterC_2->setGeometry(QRect(440, 20, 681, 421));
        tableWidgetClient_2 = new QTableWidget(groupBoxConsulterC_2);
        if (tableWidgetClient_2->columnCount() < 6)
            tableWidgetClient_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetClient_2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetClient_2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetClient_2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetClient_2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetClient_2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetClient_2->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        if (tableWidgetClient_2->rowCount() < 3)
            tableWidgetClient_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetClient_2->setVerticalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetClient_2->setVerticalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetClient_2->setVerticalHeaderItem(2, __qtablewidgetitem15);
        tableWidgetClient_2->setObjectName(QStringLiteral("tableWidgetClient_2"));
        tableWidgetClient_2->setGeometry(QRect(0, 110, 721, 251));
        pushButtonRechercher_2 = new QPushButton(groupBoxConsulterC_2);
        pushButtonRechercher_2->setObjectName(QStringLiteral("pushButtonRechercher_2"));
        pushButtonRechercher_2->setGeometry(QRect(260, 30, 93, 28));
        pushButtonModifier_2 = new QPushButton(groupBoxConsulterC_2);
        pushButtonModifier_2->setObjectName(QStringLiteral("pushButtonModifier_2"));
        pushButtonModifier_2->setGeometry(QRect(310, 380, 141, 28));
        pushButtonSupprimer_2 = new QPushButton(groupBoxConsulterC_2);
        pushButtonSupprimer_2->setObjectName(QStringLiteral("pushButtonSupprimer_2"));
        pushButtonSupprimer_2->setGeometry(QRect(480, 380, 141, 28));
        checkBoxExcel_2 = new QCheckBox(groupBoxConsulterC_2);
        checkBoxExcel_2->setObjectName(QStringLiteral("checkBoxExcel_2"));
        checkBoxExcel_2->setGeometry(QRect(490, 80, 83, 22));
        checkBoxPDF_2 = new QCheckBox(groupBoxConsulterC_2);
        checkBoxPDF_2->setObjectName(QStringLiteral("checkBoxPDF_2"));
        checkBoxPDF_2->setGeometry(QRect(490, 50, 83, 22));
        pushButtonExport_2 = new QPushButton(groupBoxConsulterC_2);
        pushButtonExport_2->setObjectName(QStringLiteral("pushButtonExport_2"));
        pushButtonExport_2->setGeometry(QRect(480, 20, 70, 30));
        lineEdit_3 = new QLineEdit(groupBoxConsulterC_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(19, 30, 221, 31));
        groupBoxAjouterC_2 = new QGroupBox(Commande);
        groupBoxAjouterC_2->setObjectName(QStringLiteral("groupBoxAjouterC_2"));
        groupBoxAjouterC_2->setGeometry(QRect(20, 20, 401, 401));
        label_10 = new QLabel(groupBoxAjouterC_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 30, 161, 41));
        lineEditIDCOMMANDE = new QLineEdit(groupBoxAjouterC_2);
        lineEditIDCOMMANDE->setObjectName(QStringLiteral("lineEditIDCOMMANDE"));
        lineEditIDCOMMANDE->setGeometry(QRect(200, 40, 113, 22));
        label_11 = new QLabel(groupBoxAjouterC_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 81, 161, 31));
        lineEditRefferenceCommande = new QLineEdit(groupBoxAjouterC_2);
        lineEditRefferenceCommande->setObjectName(QStringLiteral("lineEditRefferenceCommande"));
        lineEditRefferenceCommande->setGeometry(QRect(200, 90, 113, 22));
        label_12 = new QLabel(groupBoxAjouterC_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 131, 131, 31));
        lineEditQuantite = new QLineEdit(groupBoxAjouterC_2);
        lineEditQuantite->setObjectName(QStringLiteral("lineEditQuantite"));
        lineEditQuantite->setGeometry(QRect(200, 140, 113, 22));
        label_13 = new QLabel(groupBoxAjouterC_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 180, 121, 31));
        lineEditID = new QLineEdit(groupBoxAjouterC_2);
        lineEditID->setObjectName(QStringLiteral("lineEditID"));
        lineEditID->setGeometry(QRect(200, 190, 113, 22));
        label_14 = new QLabel(groupBoxAjouterC_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 230, 121, 31));
        DateEditCommande_2 = new QComboBox(groupBoxAjouterC_2);
        DateEditCommande_2->setObjectName(QStringLiteral("DateEditCommande_2"));
        DateEditCommande_2->setGeometry(QRect(202, 240, 111, 22));
        label_15 = new QLabel(groupBoxAjouterC_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 290, 121, 31));
        lineEditEtat = new QLineEdit(groupBoxAjouterC_2);
        lineEditEtat->setObjectName(QStringLiteral("lineEditEtat"));
        lineEditEtat->setGeometry(QRect(200, 290, 113, 22));
        pushButtonAjouter_2 = new QPushButton(groupBoxAjouterC_2);
        pushButtonAjouter_2->setObjectName(QStringLiteral("pushButtonAjouter_2"));
        pushButtonAjouter_2->setGeometry(QRect(200, 350, 93, 28));
        pushButtonAnnuler_2 = new QPushButton(groupBoxAjouterC_2);
        pushButtonAnnuler_2->setObjectName(QStringLiteral("pushButtonAnnuler_2"));
        pushButtonAnnuler_2->setGeometry(QRect(300, 350, 93, 28));
        pushButtonRetour_2 = new QPushButton(Commande);
        pushButtonRetour_2->setObjectName(QStringLiteral("pushButtonRetour_2"));
        pushButtonRetour_2->setGeometry(QRect(540, 450, 111, 28));
        pushButtonMenuPrincipal_2 = new QPushButton(Commande);
        pushButtonMenuPrincipal_2->setObjectName(QStringLiteral("pushButtonMenuPrincipal_2"));
        pushButtonMenuPrincipal_2->setGeometry(QRect(660, 450, 111, 28));
        tabWidget->addTab(Commande, QString());
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 161, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1229, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des clients", Q_NULLPTR));
        groupBoxAjouterC->setTitle(QApplication::translate("MainWindow", "Ajouter client", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Identifiant du client :", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Quantit\303\251 d'articles :", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Statut :", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Produit achet\303\251 :", Q_NULLPTR));
        pushButtonAjouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButtonAnnuler->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        groupBoxConsulterC->setTitle(QApplication::translate("MainWindow", "Consulter client", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetClient->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Idnetifiant du client", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetClient->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Quantit\303\251 d'articles", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetClient->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Statut", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetClient->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Produit achet\303\251", Q_NULLPTR));
        pushButtonRechercher->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pushButtonModifier->setText(QApplication::translate("MainWindow", "Modifier ", Q_NULLPTR));
        pushButtonSupprimer->setText(QApplication::translate("MainWindow", "Supprimer ", Q_NULLPTR));
        checkBoxExcel->setText(QApplication::translate("MainWindow", "EXCEL", Q_NULLPTR));
        checkBoxPDF->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        pushButtonExport->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        pushButtonRetour->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        pushButtonMenuPrincipal->setText(QApplication::translate("MainWindow", "Menu Principal", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Client), QApplication::translate("MainWindow", "Client", Q_NULLPTR));
        groupBoxConsulterC_2->setTitle(QApplication::translate("MainWindow", "Consulter commande", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetClient_2->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Identidiant du commande", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetClient_2->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Quantit\303\251", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetClient_2->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "R\303\251ff\303\251rence", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetClient_2->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Identifiant du client", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetClient_2->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Date du commande", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetClient_2->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Etat", Q_NULLPTR));
        pushButtonRechercher_2->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pushButtonModifier_2->setText(QApplication::translate("MainWindow", "Modifier ", Q_NULLPTR));
        pushButtonSupprimer_2->setText(QApplication::translate("MainWindow", "Supprimer ", Q_NULLPTR));
        checkBoxExcel_2->setText(QApplication::translate("MainWindow", "EXCEL", Q_NULLPTR));
        checkBoxPDF_2->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        pushButtonExport_2->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        groupBoxAjouterC_2->setTitle(QApplication::translate("MainWindow", "Ajouter commande", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Identifiant du commande :", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "R\303\251fference du commande :", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Quantit\303\251 d'articles :", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Identifiant du client :", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Date du commande :", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Etat :", Q_NULLPTR));
        pushButtonAjouter_2->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButtonAnnuler_2->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        pushButtonRetour_2->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        pushButtonMenuPrincipal_2->setText(QApplication::translate("MainWindow", "Menu Principal", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Commande), QApplication::translate("MainWindow", "Commande", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Gestion de ventes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
