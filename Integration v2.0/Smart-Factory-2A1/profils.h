#ifndef PROFILS_H
#define PROFILS_H
#include "connexionsql.h"
#include "login.h"
#include <QSqlTableModel>
#include <QString>
class profils
{
    int matricule;
    QString nomUtilisateur;
    QString email;
    QString motDePasse ;
public:
    profils();
    profils(int,QString,QString,QString);

    int get_matricule(){return matricule;}
    QString get_nomUtilisateur(){return nomUtilisateur;}
    QString get_email(){return email;}
    QString get_motDePasse(){return motDePasse;}


    bool ajouter();
    QSqlQueryModel * modifier();
    QSqlQueryModel * afficher();
    bool supprimer(int);

    QSqlQueryModel *trier(QString,QString);
    int verifUsername(int matricule,QString nomUtilisateur);
};
#endif // PROFILS_H
