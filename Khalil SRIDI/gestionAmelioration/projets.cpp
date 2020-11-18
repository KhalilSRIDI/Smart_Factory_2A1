#include "projets.h"

projets::projets()
{

}

bool projets::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PROJETS (ID_PROJET, DEPARTEMENT, TEAM_LEADER, DATE_LANCEMENT, COUTS_PREVUS, REVENUES_PROJETES, NOM) VALUES (:ID_PROJET, :DEPARTEMENT, :TEAM_LEADER, :DATE_LANCEMENT, :COUTS_PREVUS, :REVENUES_PROJETES, :NOM)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":ID_PROJET", ID_PROJET);
    query.bindValue(":DEPARTEMENT", DEPARTEMENT);
    query.bindValue(":TEAM_LEADER", TEAM_LEADER);
    query.bindValue(":DATE_LANCEMENT", DATE_LANCEMENT);
    query.bindValue(":COUTS_PREVUS", COUTS_PREVUS);
    query.bindValue(":REVENUES_PROJETES", REVENUES_PROJETES);
    return query.exec();
}



QSqlQueryModel *projets::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PROJETS");
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DEPARTEMENT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEAM_LEADER"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_LANCEMENT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("COUTS_PREVUS"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("REVENUES_PROJETES"));
    return model;
}
