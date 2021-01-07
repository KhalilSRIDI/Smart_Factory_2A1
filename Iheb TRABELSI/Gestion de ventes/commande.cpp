#include "commande.h"

commande::commande()
{

}

bool commande::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO commande (ID_COMMANDE, REFFERENCE_PRODUIT, QUANTITE, ID_CLIENT, DATE_COMMANDE, ETAT) VALUES (:ID_COMMANDE, :REFFERENCE_PRODUIT, :QUANTITE, :ID_CLIENT, :DATE_COMMANDE, :ETAT)");
    query.bindValue(":ID_COMMANDE", ID_COMMANDE);
    query.bindValue(":REFFERENCE_PRODUIT", REFFERENCE_PRODUIT);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.bindValue(":DATE_COMMANDE", DATE_COMMANDE);
    query.bindValue(":ETAT", ETAT);
    return query.exec();
}

bool commande::supprimer(int ID_COMMANDE)
{
    QSqlQuery qry;
    //int ID_COMMANDE = int::number(ID_COMMANDE);
    qry.prepare("Delete from commande where ID_COMMANDE = :ID_COMMANDE");
    qry.bindValue(":ID_COMMANDE",ID_COMMANDE);
    return qry.exec();
}



QSqlQueryModel *commande::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM commande");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_COMMANDE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("REFFERENCE_PRODUIT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_COMMANDE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT"));
    return model;
}


bool commande::modifier(QString ETAT)
{
    QSqlQuery query;
    QString res= QString(ETAT);
    query.prepare("UPDATE commande SET (ID_COMMANDE, REFFERENCE_PRODUIT, QUANTITE, ID_CLIENT, DATE_COMMANDE, ETAT) VALUES (:ID_COMMANDE, :REFFERENCE_PRODUIT, :QUANTITE, :ID_CLIENT, :DATE_COMMANDE, :ETAT)");
    query.bindValue(":ID_COMMANDE", ID_COMMANDE);
    query.bindValue(":REFFERENCE_PRODUIT", REFFERENCE_PRODUIT);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.bindValue(":DATE_COMMANDE", DATE_COMMANDE);
    query.bindValue(":ETAT", ETAT);


    return    query.exec();
}

QSqlQueryModel * commande::recherche_ID_COMMANDE(int ID_COMMANDE)
{
QSqlQuery q;
q.prepare("select * from commande where ID_COMMANDE=:ID_COMMANDE");
q.bindValue(":ID_COMMANDE", ID_COMMANDE);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_COMMANDE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("REFFERENCE_PRODUIT"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_COMMANDE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT"));
QSqlRecord rec = model->record(0);
QString :ID_COMMANDE = rec.value("ID_COMMANDE").toInt();
if( ID_COMMANDE == ID_COMMANDE){
    return model;
  }
return nullptr;
}

QSqlQueryModel * commande::recherche_REFFERENCE_PRODUIT(QString REFFERENCE_PRODUIT)
{
QSqlQuery q;
q.prepare("select * from commande where REFFERENCE_PRODUIT=:REFFERENCE_PRODUIT");
q.bindValue(":REFFERENCE_PRODUIT", REFFERENCE_PRODUIT);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_COMMANDE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("REFFERENCE_PRODUIT"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_COMMANDE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT"));
QSqlRecord rec = model->record(0);
QString :REFFERENCE_PRODUIT = rec.value("REFFERENCE_PRODUIT").toString();
if( REFFERENCE_PRODUIT == REFFERENCE_PRODUIT){
    return model;
  }
return nullptr;
}

QSqlQueryModel * commande::recherche_QUANTITE(QString QUANTITE)
{
QSqlQuery q;
q.prepare("select * from commande where QUANTITE=:QUANTITE");
q.bindValue(":QUANTITE", QUANTITE);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_COMMANDE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("REFFERENCE_PRODUIT"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_COMMANDE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT"));
QSqlRecord rec = model->record(0);
QString :QUANTITE = rec.value("QUANTITE").toString();
if( QUANTITE == QUANTITE){
    return model;
  }
return nullptr;
}

QSqlQueryModel * commande::recherche_ID_CLIENT(int ID_CLIENT)
{
QSqlQuery q;
q.prepare("select * from commande where ID_CLIENT=:ID_CLIENT");
q.bindValue(":ID_CLIENT", ID_CLIENT);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_COMMANDE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("REFFERENCE_PRODUIT"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_COMMANDE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT"));
QSqlRecord rec = model->record(0);
QString :ID_CLIENT = rec.value("ID_CLIENT").toInt();
if( ID_CLIENT == ID_CLIENT){
    return model;
  }
return nullptr;
}

QSqlQueryModel * commande::recherche_ETAT(QString ETAT)
{
QSqlQuery q;
q.prepare("select * from commande where ETAT=:ETAT");
q.bindValue(":ETAT", ETAT);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_COMMANDE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("REFFERENCE_PRODUIT"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_COMMANDE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT"));
QSqlRecord rec = model->record(0);
QString :ETAT = rec.value("ETAT").toString();
if( ETAT == ETAT){
    return model;
  }
return nullptr;
}



/*QSqlQueryModel * commande::rechercher(const QString &ETAT)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from commande where(ETAT LIKE '"+ETAT+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("REFFERENCE_PRODUIT "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_COMMANDE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ETAT"));



        return model;
}

*/
