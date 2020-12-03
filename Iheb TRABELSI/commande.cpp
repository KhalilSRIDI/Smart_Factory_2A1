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
    int ID_COMMANDE = int::number(ID_COMMANDE);
    qry.prepare("Delete from commande where ID_COMMANDE = :ID_COMMANDE");
    qry.bindValue(":ID_COMMANDE",ID_COMMANDE);
    return qry.exec();
}



QSqlQueryModel *commande::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM Client");
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

QSqlQueryModel * commande::rechercher(const QString &ETAT)
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


