#include "profils.h"

profils::profils()
{

}
profils::profils(int m,QString nU,QString n,QString p,int nT,QString e,QString mdp,QString s,QDate dN,QString dep,QString u)
{
    matricule = m;
    nomUtilisateur = nU;
    nom = n;
    prenom = p;
    numTel = nT;
    email = e;
    sexe = s;
    motDePasse = mdp;
    dateNaissance = dN;
    departement = dep;
    unite  = u;
}
bool profils::ajouter()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO PROFILS (MATRICULE,NOM_UTILISATEUR,NOM, PRENOM,NUM_TEL,EMAIL,MDP,SEXE,UNITE,DEPARTEMENT,DATE_NAISSANCE)"
                "VALUES (:MATRICULE,:NOM_UTILISATEUR,:NOM, :PRENOM,:NUM_TEL,:EMAIL,:MDP,:SEXE,:UNITE,:DEPARTEMENT,:DATE_NAISSANCE)");
    qry.bindValue(":MATRICULE",matricule);
    qry.bindValue(":NOM_UTILISATEUR",nomUtilisateur);
    qry.bindValue(":NOM",nom);
    qry.bindValue(":PRENOM",prenom);
    qry.bindValue(":NUM_TEL",numTel);
    qry.bindValue(":EMAIL",email);
    qry.bindValue(":SEXE",sexe);
    qry.bindValue(":MDP",motDePasse);
    qry.bindValue(":DATE_NAISSANCE",dateNaissance);
    qry.bindValue(":DEPARTEMENT",departement);
    qry.bindValue(":UNITE",unite);
    return qry.exec();
}
QSqlQueryModel * profils::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery("SELECT * from PROFILS");
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

