#include "formation.h"
#include"ui_mainwindow.h"
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

QSqlQueryModel *formation::chercher(QString input,int critere)
{
    QSqlQuery q;
    int inputid;

    switch (critere) {
    case 0:
        inputid=input.toInt();
        q.prepare("SELECT * FROM formations WHERE IDFORMATION = :IDFORMATION");
        q.bindValue(":IDFORMATION",inputid);
        break;
    case 1:
        q.prepare("SELECT * FROM formations WHERE NOM = :NOM");
        q.bindValue(":NOM",input);
        break;
    case 2:
        q.prepare("SELECT * FROM formations WHERE PROJET = :PROJET");
        q.bindValue(":PROJET",input);
        break;
    case 3:
        q.prepare("SELECT * FROM formations WHERE FORMATEUR = :FORMATEUR");
        q.bindValue(":FORMATEUR",input);
        break;
    case 4:
        q.prepare("SELECT * FROM formations WHERE DATEDEBUT = :DATEDEBUT");
        q.bindValue(":DATEDEBUT",input);
        break;
    case 5:
        q.prepare("SELECT * FROM formations WHERE DUREE = :DUREE");
        q.bindValue(":DUREE",input);
        break;
    case 6:
        q.prepare("SELECT * FROM formations WHERE COUT = :COUT");
        q.bindValue(":COUT",input);
        break;

    }

    q.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDFORMATION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PROJET"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FORMATEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("COUT"));
    int num;
    QSqlRecord rec;
    rec = model->record(critere);
    num = rec.value(critere).toInt();
    if( num == input){
        return model;
    }
    return nullptr;

}
