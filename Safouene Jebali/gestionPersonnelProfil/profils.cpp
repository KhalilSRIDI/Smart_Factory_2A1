#include "profils.h"

profils::profils()
{

}
profils::profils(int m,QString nU,QString mdp)
{
    matricule = m;
    nomUtilisateur = nU;
    motDePasse = mdp;
}
bool profils::ajouter()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO PROFILS (MATRICULE,NOM_UTILISATEUR,MDP)"
                "VALUES (:MATRICULE,:NOM_UTILISATEUR,:MDP)");
    qry.bindValue(":MATRICULE",matricule);
    qry.bindValue(":NOM_UTILISATEUR",nomUtilisateur);
    qry.bindValue(":MDP",motDePasse);
    return qry.exec();
}
QSqlQueryModel * profils::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery("select * from profils cross Join personnels where profils.matricule = personnels.matricule");
    return model;
}
bool profils::supprimer(int id)
{
    QSqlQuery qry;
    QString idS = QString::number(id);
    qry.prepare("Delete from PROFILS where ID = :ID");
    qry.bindValue(":ID",idS);
    return qry.exec();
}

