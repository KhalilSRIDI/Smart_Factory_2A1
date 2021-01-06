#include "login.h"

login::login()
{

}
int login::connecter(QString nomUtilisateur,QString motDePasse)
{
    QSqlQuery qry;
    qry.prepare("Select * from PROFILS where nom_utilisateur =:nom_utilisateur and mdp=:mdp");
    qry.bindValue(":nom_utilisateur",nomUtilisateur);
    qry.bindValue(":mdp",this->hash(motDePasse));
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    QSqlRecord rec = model->record(0);
    QString nu = rec.value("nom_utilisateur").toString();
    int mdpU = rec.value("mdp").toInt();
    int matricule = rec.value("matricule").toInt();
    if( nu == nomUtilisateur && mdpU == this->hash(motDePasse) && nomUtilisateur != 0)
        return matricule;
    else
        return 0;
}
int login::recupererDepartement(int matricule)
{
    QSqlQuery qry;
    qry.prepare("Select * from PERSONNELS where matricule=:matricule");
    qry.bindValue(":matricule",matricule);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    QSqlRecord rec = model->record(0);
    QString dep = rec.value("departement").toString();
    QString fct = rec.value("fonction").toString();
    if(fct!="Chef De Departement")
    {
        if(dep=="Ressources Humaines")
            return 1;
        else if(dep=="Stock")
            return 2;
        else if(dep=="Achats")
            return 3;
        else if(dep=="Ventes")
            return 4;
        else if(dep=="Ameliorations")
            return 5;
        else if(dep=="Materiels")
            return 6;
    }
    else
        return 7;
}
QString login::infoSession(int matricule)
{
    QSqlQuery qry;
    qry.prepare("Select * from PERSONNELS where matricule =:matricule");
    qry.bindValue(":matricule",matricule);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    QSqlRecord rec = model->record(0);
    QString nom = rec.value("nom").toString();
    QString prenom = rec.value("prenom").toString();
        return nom+' '+prenom;

}
QByteArray login::recupererImage(int matricule)
{
    QSqlQuery qry;
    qry.prepare("Select * from PERSONNELS where matricule =:matricule");
    qry.bindValue(":matricule",matricule);
    qry.exec();
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery(qry);
    QSqlRecord rec = model->record(0);
    QByteArray img=rec.value("image").toByteArray();
    return img;

}
int login::hash(QString motDePasse)
{
    std::hash<std::string> hash;
    return hash(motDePasse.toStdString());
}
