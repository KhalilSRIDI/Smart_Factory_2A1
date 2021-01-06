#include "profils.h"

profils::profils()
{

}
profils::profils(int m,QString nU,QString e,QString mdp)
{
    matricule = m;
    nomUtilisateur = nU;
    email = e;
    motDePasse = mdp;
}
bool profils::ajouter()
{
    login l;
    QSqlQuery qry;
    qry.prepare("INSERT INTO PROFILS (MATRICULE,NOM_UTILISATEUR,MDP,email)"
                "VALUES (:MATRICULE,:NOM_UTILISATEUR,:MDP,:email)");
    qry.bindValue(":MATRICULE",matricule);
    qry.bindValue(":NOM_UTILISATEUR",nomUtilisateur);
    qry.bindValue(":email",email);
    qry.bindValue(":MDP",l.hash(motDePasse));
    return qry.exec();
}
QSqlQueryModel * profils::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery("select * from profils cross Join personnels where profils.matricule = personnels.matricule");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom utilisateur"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mot De Passe"));
    return model;
}
bool profils::supprimer(int id)
{
    QSqlQuery qry;
    qry.prepare("Delete from PROFILS where ID = :ID");
    qry.bindValue(":ID",id);
    return qry.exec();
}
QSqlQueryModel * profils::modifier()
{
    QSqlTableModel *model= new QSqlTableModel();
    model->setTable("PROFILS");
    model->select();
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Mot De Passe"));
    return  model;
}
QSqlQueryModel *profils::trier(QString critere,QString AD)
{
    QSqlQuery qry;
    qry.prepare("select * from PROFILS order by "+critere+" "+AD);
    qry.exec();
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(qry);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Matricule"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("E-mail"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Mot De Passe"));
    return model;
}

int profils::verifUsername(int matricule,QString nomUtilisateur)
{
    QSqlQuery qry;
    qry.prepare("select nom,prenom from personnels where matricule=:matricule");
    qry.bindValue(":matricule",matricule);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    QSqlRecord rec = model->record(0);
    QString nom = rec.value("nom").toString();
    QString prenom = rec.value("prenom").toString();
    QString test=nom+'.'+prenom;
    if(nomUtilisateur==test)
        return 1;
    else
        return 0;

}
