#ifndef GESTIONMAINTENANCE_H
#define GESTIONMAINTENANCE_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlTableModel>
#include <QSqlRecord>

class maintenance
{
public:
    maintenance();
    maintenance(QString,QString,QString,QString,QDate,QDate,QString,QString);
    QString get_ID_maintenance(){return ID_maintenance;}
    QString get_reference(){return reference;}
    QString get_modele(){return modele;}
    QString get_matricule(){return matricule;}
    QDate get_DATE_ACHAT(){return DATE_ACHAT;}
    QDate get_date_de_maintenance(){return date_de_maintenance;}
    QString get_dernier_probleme(){return dernier_probleme;}
    QString get_type_de_maintenance(){return type_de_maintenance;}
    void set_ID_maintenance(QString ID){ID_maintenance=ID;}
    void set_reference(QString r){reference=r;}
    void set_modele(QString mo){modele=mo;}
    void set_matricule(QString ma){matricule=ma;}
    void set_DATE_ACHAT(QDate d){DATE_ACHAT= d;}
    void set_date_de_maintenance(QDate dm){date_de_maintenance= dm;}
    void set_dernier_probleme(QString p){dernier_probleme=p;}
    void set_type_de_maintenance(QString type){type_de_maintenance=type;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    QSqlQueryModel * recherche_maintenance(QString ID_maintenance);
    QSqlQueryModel * recherche_maintenance_reference(QString reference);
    QSqlQueryModel * recherche_maintenance_modele(QString modele);
    QSqlQueryModel * recherche_maintenance_matricule(QString matricule);
    QSqlQueryModel * recherche_maintenance_type(QString type_de_maintenance);
    QSqlQueryModel * trier_maintenance_ID();
    QSqlQueryModel * trier_maintenance_reference();
    QSqlQueryModel * trier_maintenance_modele();
    QSqlQueryModel * trier_maintenance_matricule();
    QSqlQueryModel * trier_maintenance_dateachat();
    QSqlQueryModel * trier_maintenance_date_derniere_maintenance();
private:
    QString ID_maintenance,reference,modele,matricule,dernier_probleme,type_de_maintenance;
    QDate DATE_ACHAT,date_de_maintenance;
};

#endif // GESTIONMAINTENANCE_H
