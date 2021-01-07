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

QSqlQueryModel * client::recherche_client(int ID_CLIENT)
   {
   QSqlQuery q;
   q.prepare("select * from client where ID_CLIENT=:ID_CLIENT");
   q.bindValue(":ID_CLIENT", ID_CLIENT);
   q.exec();
   QSqlQueryModel * model = new QSqlQueryModel;
   model->setQuery(q);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE_ARTICLES"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT_ACHETE"));
   QSqlRecord rec = model->record(0);
   int id = rec.value("ID_CLIENT").toInt();
   if( id == ID_CLIENT){
       return model;
     }
   return nullptr;
   }

QSqlQueryModel * client::recherche_client_QUANTITE_ARTICLES(QString QUANTITE_ARTICLES)
{
QSqlQuery q;
q.prepare("select * from client where QUANTITE_ARTICLES=:QUANTITE_ARTICLES");
q.bindValue(":QUANTITE_ARTICLES", QUANTITE_ARTICLES);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE_ARTICLES"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT_ACHETE"));
QSqlRecord rec = model->record(0);
QString :QUANTITE_ARTICLES = rec.value("QUANTITE_ARTICLES").toString();
if( QUANTITE_ARTICLES == QUANTITE_ARTICLES){
    return model;
  }
return nullptr;
}

QSqlQueryModel * client::recherche_client_STATUT(QString STATUT)
{
QSqlQuery q;
q.prepare("select * from client where STATUT=:STATUT");
q.bindValue(":STATUT", STATUT);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE_ARTICLES"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT_ACHETE"));
QSqlRecord rec = model->record(0);
QString :STATUT = rec.value("STATUT").toString();
if( STATUT == STATUT){
    return model;
  }
return nullptr;
}

QSqlQueryModel * client::recherche_client_PRODUIT_ACHETE(QString PRODUIT_ACHETE)
{
QSqlQuery q;
q.prepare("select * from client where PRODUIT_ACHETE=:PRODUIT_ACHETE");
q.bindValue(":PRODUIT_ACHETE", PRODUIT_ACHETE);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE_ARTICLES"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT_ACHETE"));
QSqlRecord rec = model->record(0);
QString :PRODUIT_ACHETE = rec.value("PRODUIT_ACHETE").toString();
if( PRODUIT_ACHETE == PRODUIT_ACHETE){
    return model;
  }
return nullptr;
}



/*QSqlQueryModel * client::rechercher(const int &ID_CLIENT)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from client where(ID_CLIENT LIKE '"+ID_CLIENT+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE_ARTICLES"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRODUIT_ACHETE"));



        return model;
}

*/
