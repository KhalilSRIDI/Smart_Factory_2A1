#ifndef GESTIONMATERIEL_H
#define GESTIONMATERIEL_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlTableModel>
#include <QSqlRecord>

class materiel
{
public:
    materiel();
    materiel(QString,QString,QDate,int);
    QString get_reference(){return reference;}
    QString get_modele(){return modele;}
    QDate get_DATE_ACHAT(){return DATE_ACHAT;}
    int get_nombre_maintenance(){return nombre_maintenance;}

    void setreference(QString r){reference=r;}
    void setmodele(QString mo){modele=mo;}
    void set_DATE_ACHAT(QDate d){DATE_ACHAT= d;}
    void set_nombre_maintenance(int nbm){nombre_maintenance=nbm;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    QSqlQueryModel * recherche_materiel(QString reference);
    QSqlQueryModel * recherche_materiel_modele(QString modele);
    QSqlQueryModel * recherche_materiel_nbr_maintenance(int nombre_maintenance);
    QSqlQueryModel * trier_materiel();
    QSqlQueryModel * trier_materielmodele();
    QSqlQueryModel * trier_materiel_dateachat();
    QSqlQueryModel * trier_materiel_nbr_maintenance();
private:
    QString reference,modele;
    QDate DATE_ACHAT;
    int nombre_maintenance;
};

#endif // GESTIONMATERIEL_H
