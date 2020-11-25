#ifndef PROFILS_H
#define PROFILS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>

class profils
{
    int matricule;
    QString nomUtilisateur;
    QString nom ;
    QString prenom ;
    int numTel ;
    QString email ;
    QString motDePasse ;
    QString sexe ;
    QDate dateNaissance ;
    QString departement;
    QString unite ;
public:
    profils();
    profils(int,QString,QString,QString,int,QString,QString,QString,QDate,QString,QString);
    int get_matricule(){return matricule;}
    QString get_nom(){return nom;}
    QString get_prenom() {return prenom;}
    int get_numTel(){return numTel;}
    QString get_email(){return email;}
    QString get_motDePasse(){return motDePasse;}
    QString get_sexe(){return sexe;};
    QDate get_dateNaissance(){return dateNaissance;}
    QString get_departement(){return departement;}
    QString get_unite(){return unite;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // PROFILS_H
