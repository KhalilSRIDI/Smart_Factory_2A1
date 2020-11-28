#ifndef PERSONNELS_H
#define PERSONNELS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QString>
#include <QDate>
class personnels
{
    int cin;
    QString nom ;
    QString prenom ;
    int numTel ;
    QString email ;
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
public:
    personnels();
    personnels(int,QString,QString,int,QString,QString,QString,QDate,QString,QString,QString,QDate,QString,QString,QString,QString,int);
    int get_cin(){return cin;}
    QString get_nom(){return nom;}
    QString get_prenom() {return prenom;}
    int get_numTel(){return numTel;}
    QString get_email(){return email;}
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
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel *trier(QString,QString);
    QSqlQueryModel *trier(QString,QString,QString,QString,QString);
    QSqlQueryModel *chercherPersonnel(QString);



    QSqlQueryModel *chercherPersonnel(int);
    QSqlQueryModel *chercherPersonnelFonction(QString);
    QSqlQueryModel *chercherPersonnelPeriodeRec(QDate,QDate);
    QSqlQueryModel *chercherPersonnel3C(QString,QString,int);

private:
};
#endif // PERSONNELS_H
