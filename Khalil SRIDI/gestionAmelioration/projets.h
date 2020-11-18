#ifndef PROJETS_H
#define PROJETS_H

#include<qstring.h>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
class projets {
public:
    projets();

    projets(QString n,QString d,QString t,QString date,QString c,QString r):NOM(n),DEPARTEMENT(d),TEAM_LEADER(t),DATE_LANCEMENT(date),COUTS_PREVUS(c),REVENUES_PROJETES(r) {}

    //getters
    int getIdProjet() { return ID_PROJET; };
    QString getNom(){return NOM;};
    QString getDepartement() { return DEPARTEMENT; };
    QString getTeamLeader() { return TEAM_LEADER; };
    QString getDateLancement() { return DATE_LANCEMENT; };
    QString getCout() { return COUTS_PREVUS; };
    QString getRevenus() { return REVENUES_PROJETES; };

    //setters
    void setIdProjet(int id_projet) { ID_PROJET = id_projet; }
    void setNom(QString nom){NOM=nom;}
    void setDepartement(QString departement) { DEPARTEMENT = departement; }
    void setTeamLeader(QString teamLeader) { TEAM_LEADER = teamLeader; }
    void setDateLancement(QString dateLancement) { DATE_LANCEMENT = dateLancement; }
    void setCout(QString cout) { COUTS_PREVUS = cout; }
    void setRevenus(QString revenus) { REVENUES_PROJETES = revenus; }

    //fonctions
    bool ajouter();
    QSqlQueryModel *afficher();

private:
    int ID_PROJET;
    QString NOM;
    QString DEPARTEMENT;
    QString TEAM_LEADER;
    QString DATE_LANCEMENT;
    QString COUTS_PREVUS;
    QString REVENUES_PROJETES;

};

#endif // PROJETS_H
