#ifndef FORMATION_H
#define FORMATION_H


#include<QString>
#include<qstring.h>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QtDebug>
#include<qtableview.h>
#include<QFileDialog>
#include<QCoreApplication>

class formation
{
public:
    formation();

    formation(QString n,int p,QString f,QString date,QString d,QString c):NOM(n),PROJET(p),FORMATEUR(f),DATEDEBUT(date),DUREE(d),COUT(c) {}

    //getters
    QString getNom(){return NOM;};
    int getProjet(){return PROJET;};
    QString getFormateur(){return FORMATEUR;};
    QString getDateD(){return DATEDEBUT;};
    QString getDuree(){return DUREE;};
    QString getCout() {return COUT;};

    //setters

    void setNom(QString nom){NOM=nom;}
    void setProjet(int projet){PROJET=projet;}
    void setFormateur(QString formateur){FORMATEUR=formateur;}
    void setDateD(QString date){DATEDEBUT=date;}
    void setDuree(QString duree){DUREE=duree;}
    void SetCout(QString cout){COUT=cout;}

    //fonctions
    bool ajouter();
    bool supprimer(int idformation);
    QSqlQueryModel *afficher();
    QSqlQueryModel *chercher(QString input,int critere);
    void exporterExcel(QTableView *table);
    QSqlQueryModel *trier(QString critere,QString order);

private:
    QString NOM;
    int PROJET;
    QString FORMATEUR;
    QString DATEDEBUT;
    QString DUREE;
    QString COUT;

};


#endif // FORMATION_H

#include<QString>
#include<qstring.h>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
