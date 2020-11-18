#include "projets.h"

projets::projets()
{

}

bool projets::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PROJETS (NOM, DEPARTEMENT, TEAM_LEADER, DATE_LANCEMENT, COUTS_PREVUS, REVENUS_PROJETES) VALUES (:NOM, :DEPARTEMENT, :TEAM_LEADER, :DATE_LANCEMENT, :COUTS_PREVUS, :REVENUS_PROJETES)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":DEPARTEMENT", DEPARTEMENT);
    query.bindValue(":TEAM_LEADER", TEAM_LEADER);
    query.bindValue(":DATE_LANCEMENT", DATE_LANCEMENT);
    query.bindValue(":COUTS_PREVUS", COUTS_PREVUS);
    query.bindValue(":REVENUS_PROJETES", REVENUS_PROJETES);
    return query.exec();
}



QSqlQueryModel *projets::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PROJETS");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DEPARTEMENT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEAM_LEADER"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_LANCEMENT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("COUTS_PREVUS"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("REVENUS_PROJETES"));
    return model;
}
