#include "client.h"
#include <QDebug>

client::client()
{

}

bool client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO client (ID_CLIENT, QUANTITE_ARTICLES, STATUT, PRODUIT_ACHETE) VALUES (:ID_CLIENT, :QUANTITE_ARTICLES, :STATUT, :PRODUIT_ACHETE)");
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.bindValue(":QUANTITE_ARTICLES", QUANTITE_ARTICLES);
    query.bindValue(":STATUT", STATUT);
    query.bindValue(":PRODUIT_ACHETE", PRODUIT_ACHETE);
    return query.exec();
}

bool client::supprimer(int idclient)
{
    QSqlQuery qry;
    QString id = QString::number(idclient);
    qry.prepare("Delete from Client where IDClient = :IDClient");
    qry.bindValue(":IDClient",id);
    return qry.exec();
}



QSqlQueryModel *client::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM Client");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE_ARTICLES"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("STATUT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PRODUIT_ACHETE"));
    return model;
}


bool client::modifier(int id)
{
    QSqlQuery query;
    int res= int(id);
    query.prepare("UPDATE client SET (ID_CLIENT, QUANTITE_ARTICLES, STATUT, PRODUIT_ACHETE) VALUES (:ID_CLIENT, :QUANTITE_ARTICLES, :STATUT, :PRODUIT_ACHETE)");
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.bindValue(":QUANTITE_ARTICLES", QUANTITE_ARTICLES);
    query.bindValue(":STATUT", STATUT);
    query.bindValue(":PRODUIT_ACHETE", PRODUIT_ACHETE);


    return    query.exec();
}

QSqlQueryModel * client::rechercher(const int &ID_CLIENT)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from client where(ID_CLIENT LIKE '"+ID_CLIENT+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE_ARTICLES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRODUIT_ACHETE"));



        return model;
}


