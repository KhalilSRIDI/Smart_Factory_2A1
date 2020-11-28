#ifndef PROFILS_H
#define PROFILS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QString>
class profils
{
    int matricule;
    QString nomUtilisateur;
    QString motDePasse ;
public:
    profils();
    profils(int,QString,QString);
    int get_matricule(){return matricule;}
    QString get_nomUtilisateur(){return nomUtilisateur;}
    QString get_motDePasse(){return motDePasse;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // PROFILS_H
