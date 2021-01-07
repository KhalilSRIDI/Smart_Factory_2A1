#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "commande.h"
#include <QTableView>
#include <QApplication>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDate>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidgetClient->setModel(temp_client.afficher());
    ui->tableWidgetClient->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetClient->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetClient_2->setModel(tmp_commande.afficher());
    ui->tableWidgetClient_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetClient_2->setSelectionMode(QAbstractItemView::SingleSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAjouter_clicked()
{
    int ID_CLIENT=ui->lineEditId->text().toInt();
    QString QUANTITE_ARTICLES=ui->lineEditQuantitearticles->text();
    QString STATUT=ui->lineEditStatut->text();
    QString PRODUIT_ACHETE=ui->lineEditProduitAchete->text();

    client client(ID_CLIENT, QUANTITE_ARTICLES, STATUT, PRODUIT_ACHETE);
    bool test= client.ajouter();
    ui->tableWidgetClient->setModel(temp_client.afficher());//refresh

     if(test)
   {ui->tableWidgetClient->setModel(temp_client.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("client ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButtonSupprimer_clicked()
{
    int ID_CLIENT = ui->lineEditId->text().toInt();
    bool test=temp_client.supprimer(ID_CLIENT);
    if(test)
    {ui->tableWidgetClient->setModel(temp_client.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButtonModifier_clicked()
{

    if(ui->pushButtonModifier->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("CLIENT");
        tableModel->select();
        ui->tableWidgetClient->setModel(tableModel);
        ui->pushButtonModifier->setText("Tableau Modifiable");

    }

}


/*void MainWindow::on_pushButtonRechercher_clicked()
{
    QString str=ui->lineEdit_3->text();
    ui->tableWidgetClient->setModel(temp_client.rechercher(str));
}*/

void MainWindow::on_pushButtonAjouter_2_clicked()
{
    int ID_COMMANDE=ui->lineEditIDCOMMANDE->text().toInt();
    QString REFFERENCE_PRODUIT=ui->lineEditRefferenceCommande->text();
    QString QUANTITE=ui->lineEditQuantite->text();
    int ID_CLIENT=ui->lineEditID->text().toInt();
    QString DATE_COMMANDE=ui->DateEditCommande_2->date().toString("dd/MM/yyyy");
    QString ETAT=ui->lineEditEtat->text();

    commande commande(ID_COMMANDE, REFFERENCE_PRODUIT, QUANTITE, ID_CLIENT, DATE_COMMANDE, ETAT);
    bool test= commande.ajouter();
    ui->tableWidgetClient_2->setModel(tmp_commande.afficher());//refresh

     if(test)
   {ui->tableWidgetClient_2->setModel(tmp_commande.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                     QObject::tr("commande ajoutée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButtonModifier_2_clicked()
{
    if(ui->pushButtonModifier->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("COMMANDE");
        tableModel->select();
        ui->tableWidgetClient_2->setModel(tableModel);
        ui->pushButtonModifier->setText("Tableau Modifiable");
}}



/*void MainWindow::on_pushButtonRechercher_2_clicked()
{
    QString str=ui->lineEdit_3->text();
    ui->tableWidgetclient->setModel(temp_client.recherche(str));
}}*/

void MainWindow::on_pushButtonSupprimer_2_clicked()
{
    int ID_COMMANDE=ui->lineEditIDCOMMANDE->text().toInt();
    bool test=tmp_commande.supprimer(ID_COMMANDE);
    if(test)
    {ui->tableWidgetClient_2->setModel(tmp_commande.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("commande supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

