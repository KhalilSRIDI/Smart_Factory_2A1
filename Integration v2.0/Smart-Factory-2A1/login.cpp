#include "login.h"

login::login()
{

}
int login::connecter(QString nomUtilisateur,QString motDePasse)
{
    QSqlQuery qry;
    qry.prepare("Select * from PROFILS where nom_utilisateur =:nom_utilisateur and mdp=:mdp");
    qry.bindValue(":nom_utilisateur",nomUtilisateur);
    qry.bindValue(":mdp",motDePasse);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    QSqlRecord rec = model->record(0);
    QString nu = rec.value("nom_utilisateur").toString();
    QString mdpU = rec.value("mdp").toString();
    if( nu == nomUtilisateur && mdpU == motDePasse && nomUtilisateur != 0)
        return 1;
    else
        return 0;
}
int login::recupererDepartement(int matricule)
{
//    QSqlQuery qry;
//    qry.prepare("Select * from PROFILS where nom_utilisateur =:nom_utilisateur and mdp=:mdp");
//    qry.bindValue(":nom_utilisateur",nomUtilisateur);
//    qry.bindValue(":mdp",motDePasse);
//    qry.exec();
//    QSqlQueryModel * model = new QSqlQueryModel;
//    model->setQuery(qry);
//    QSqlRecord rec = model->record(0);
//    QString nu = rec.value("nom_utilisateur").toString();
//    QString mdpU = rec.value("mdp").toString();
//    if( nu == nomUtilisateur && mdpU == motDePasse && nomUtilisateur != 0)
//        return 1;
//    else
//        return 0;


}
