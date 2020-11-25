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

bool projets::supprimer(int idprojet)
{
    QSqlQuery qry;
    QString id = QString::number(idprojet);
    qry.prepare("Delete from PROJETS where IDPROJET = :IDPROJET");
    qry.bindValue(":IDPROJET",id);
    return qry.exec();
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

QSqlQueryModel *projets::chercher(QString input,int critere)
{
    QSqlQuery q;
    int inputid;

    if(critere==0)
    {
        inputid=input.toInt();
        q.prepare("SELECT * FROM PROJETS WHERE IDPROJET = :IDPROJET");
        q.bindValue(":IDPROJET",inputid);
        q.exec();
    }
    else if(critere==1)
    {
        q.prepare("SELECT * FROM PROJETS WHERE NOM = :NOM");
        q.bindValue(":NOM",input);
        q.exec();
    }
    else if(critere==2)
    {
        q.prepare("SELECT * FROM PROJETS WHERE DEPARTEMENT = :DEPARTEMENT");
        q.bindValue(":DEPARTEMENT",input);
        q.exec();
    }
    else if(critere==3)
    {
        q.prepare("SELECT * FROM PROJETS WHERE TEAM_LEADER = :TEAM_LEADER");
        q.bindValue(":TEAM_LEADER",input);
        q.exec();
    }
    else if(critere==4)
    {
        q.prepare("SELECT * FROM PROJETS WHERE DATE_LANCEMENT = :DATE_LANCEMENT");
        q.bindValue(":DATE_LANCEMENT",input);
        q.exec();
    }
    else if(critere==5)
    {
        q.prepare("SELECT * FROM PROJETS WHERE COUTS_PREVUS = :COUTS_PREVUS");
        q.bindValue(":COUTS_PREVUS",input);
        q.exec();
    }
    else if(critere==6)
    {
        q.prepare("SELECT * FROM PROJETS WHERE REVENUS_PROJETES = :REVENUS_PROJETES");
        q.bindValue(":REVENUS_PROJETES",input);
        q.exec();
    }


    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDPROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEAM_LEADER"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_LANCEMENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("COUTS_PREVUS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("REVENUS_PROJETES"));

    int num;
    QString index;

    QSqlRecord recp;
    recp = model->record(0);
    if(critere==0)
    {
        num = recp.value("IDPROJET").toInt();
        return model;
    }
    else
    {
        index = recp.value("input").toString();
        return model;
    }

    return nullptr;

}
