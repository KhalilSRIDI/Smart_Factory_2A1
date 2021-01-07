#ifndef PERSONNELS_H
#define PERSONNELS_H
#include "connexionsql.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QString>
#include <QDate>
class personnels
{
    QString cin;
    QString nom ;
    QString prenom ;
    QString numTel ;
    QString sexe ;
    QString etatCivile;
    QDate dateNaissance ;
    QString gouvernoratOrigin;
    QString gouvernoratHabitation ;
    QString diplomeEtude ;
    QDate dateRecrutement;
    QString typeContrat ;
    QString departement;
    QString unite ;
    QString fonction ;
    int salaire ;
    QByteArray image;
public:
    personnels();
    personnels(QString,QString,QString,QString,QString,QString,QDate,QString,QString,QString,QDate,QString,QString,QString,QString,int,QByteArray);

    QString get_cin(){return cin;}
    QString get_nom(){return nom;}
    QString get_prenom() {return prenom;}
    QString get_numTel(){return numTel;}
    QString get_sexe(){return sexe;};
    QString get_etatCivile(){return etatCivile ;}
    QDate get_dateNaissance(){return dateNaissance;}
    QString get_gouvernoratOrigin(){return gouvernoratOrigin;}
    QString get_gouvernoratHabitation(){return gouvernoratHabitation;}
    QString get_diplomeEtude(){return diplomeEtude;}
    QDate get_dateRecrutement(){return dateRecrutement;}
    QString get_typeContrat() {return typeContrat;}
    QString get_fonction(){return fonction;}
    QString get_departement(){return departement;}
    QString get_unite(){return unite;}
    int get_salaire(){return salaire;}
    QByteArray get_image(){return image;}

    bool ajouter();
    QSqlQueryModel * modifier();
    QSqlQueryModel * afficher();
    bool supprimer(int);

    QSqlQueryModel *trier(QString,QString);
    QSqlQueryModel *trier(QString,QString,QString,QString,QString);

    QSqlQueryModel *chercherNom(QString);
    QSqlQueryModel *chercher(int);
    QSqlQueryModel *chercherFonction(QString);
    QSqlQueryModel *chercher(QDate,QDate);
    QSqlQueryModel *chercher(QString,QString,int);

    int calculerTC(QString);
    int calculerSE(QString,QString);
    int calculerSF(QString,QString);

    QSqlQueryModel *rechercher_rfid(QString);

private:

};
#endif // PERSONNELS_H
