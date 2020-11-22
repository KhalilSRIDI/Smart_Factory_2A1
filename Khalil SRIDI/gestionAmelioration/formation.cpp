#include "formation.h"

formation::formation()
{

}

bool formation::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO formations (NOM, PROJET, FORMATEUR, DATEDEBUT, DUREE, COUT) VALUES (:NOM, :PROJET, :FORMATEUR, :DATEDEBUT, :DUREE, :COUT)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":PROJET", PROJET);
    query.bindValue(":FORMATEUR", FORMATEUR);
    query.bindValue(":DATEDEBUT", DATEDEBUT);
    query.bindValue(":DUREE", DUREE);
    query.bindValue(":COUT", COUT);
    return query.exec();
}

bool formation::supprimer(int idformation)
{
    QSqlQuery qury;
    QString idf = QString::number(idformation);
    qury.prepare("Delete from FORMATIONS where IDFORMATION = :IDFORMATION");
    qury.bindValue(":IDFORMATION",idf);
    return qury.exec();
}



QSqlQueryModel *formation::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM formations");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDFORMATION"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PROJET"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("FORMATEUR"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEDEBUT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DUREE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("COUT"));
    return model;
}
