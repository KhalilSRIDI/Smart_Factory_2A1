#ifndef PROJETS_H
#define PROJETS_H

#include<QString>
#include<qstring.h>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QtDebug>

class projets {
public:
    projets();

    projets(QString n,QString d,QString t,QString date,QString c,QString r):NOM(n),DEPARTEMENT(d),TEAM_LEADER(t),DATE_LANCEMENT(date),COUTS_PREVUS(c),REVENUS_PROJETES(r) {}

    //getters
    QString getNom(){return NOM;};
    QString getDepartement() { return DEPARTEMENT; };
    QString getTeamLeader() { return TEAM_LEADER; };
    QString getDateLancement() { return DATE_LANCEMENT; };
    QString getCout() { return COUTS_PREVUS; };
    QString getRevenus() { return REVENUS_PROJETES; };

    //setters
    void setNom(QString nom){NOM=nom;}
    void setDepartement(QString departement) { DEPARTEMENT = departement; }
    void setTeamLeader(QString teamLeader) { TEAM_LEADER = teamLeader; }
    void setDateLancement(QString dateLancement) { DATE_LANCEMENT = dateLancement; }
    void setCout(QString cout) { COUTS_PREVUS = cout; }
    void setRevenus(QString revenus) { REVENUS_PROJETES = revenus; }

    //fonctions
    bool ajouter();
    bool supprimer(int idprojet);
    QSqlQueryModel *afficher();
    QSqlQueryModel *chercher(QString input,int critere);

private:
    QString NOM;
    QString DEPARTEMENT;
    QString TEAM_LEADER;
    QString DATE_LANCEMENT;
    QString COUTS_PREVUS;
    QString REVENUS_PROJETES;

};

#endif // PROJETS_H
