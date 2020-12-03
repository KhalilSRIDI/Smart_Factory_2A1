#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "commande.h"

#include <QApplication>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableclient->setModel(tmp_client.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAjouter_clicked()
{
    int ID_CLIENT=ui->lineEditId->text();
    QString QUANTITE_ARTICLES=ui->lineEditQuantitearticles->text();
    QString STATUT=ui->lineEditStatut->text();
    QString PRODUIT_ACHETE=ui->lineEditProduitAchete->text();

    client client(ID_CLIENT, QUANTITE_ARTICLES, STATUT, PRODUIT_ACHETE);
    bool test= client.ajouter();
    ui->tableclient->setModel(tmp_client.afficher());//refresh

     if(test)
   {ui->tableclient->setModel(tmpclient.afficher());//refresh
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
    int ID_CLIENT = ui->lineEditId->text();
    bool test=tmp_client.supprimer(ID_CLIENT);
    if(test)
    {ui->tmp_client->setModel(tmp_client.afficher());//refresh
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
        ui->tableclient->setModel(tableModel);
        ui->pushButtonModifier->setText("Tableau Modifiable");

    }

}


void MainWindow::on_pushButtonRechercher_clicked()
{
    QString str=ui->lineEdit_3->text();
    ui->tableclient->setModel(tmp_client.rechercher(str));
}

void MainWindow::on_pushButtonAjouter_2_clicked()
{
    int ID_COMMANDE=ui->lineEditNom_2->text().toInt();
    QString REFFERENCE_PRODUIT=ui->lineEditRefferenceClient_2->text();
    QString QUANTITE=ui->lineEditQuantiteArticles_2->text();
    int ID_CLIENT=ui->lineEditStatut_2->text().toInt();
    QString DATE_COMMANDE=ui->DateEditCommande_2->date().toString("dd/MM/yyyy");
    QString ETAT=ui->lineEditProduitAchete_2->text();

    commande commande(ID_COMMANDE, REFFERENCE_PRODUIT, QUANTITE, ID_CLIENT, DATE_COMMANDE, ETAT);
    bool test= commande.ajouter();
    ui->tablecommande->setModel(tmp_commande.afficher());//refresh

     if(test)
   {ui->tablecommande->setModel(tmp_commande.afficher());//refresh
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
        ui->tablecommande->setModel(tableModel);
        ui->pushButtonModifier->setText("Tableau Modifiable");
}

void MainWindow::on_pushButtonSupprimer_2_clicked()
{
    int ID_COMMANDE=ui->lineEditIDCOMMANDE->text().toInt();
    bool test=tmp_commande.supprimer(ID_COMMANDE);
    if(test)
    {ui->tmp_commande->setModel(tmp_commande.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("commande supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButtonRechercher_2_clicked()
{
    QString str=ui->lineEdit_3->text();
    ui->tabclient->setModel(tmpclient.recherche(str));
}
