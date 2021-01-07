#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>


class commande
{
public:
    commande();
    commande(int idc,QString ref,QString q,int id,QString date,QString e):ID_COMMANDE(idc),REFFERENCE_PRODUIT(ref),QUANTITE(q),ID_CLIENT(id),DATE_COMMANDE(date),ETAT(e) {}


    //getters
     int getIDC(){return ID_COMMANDE;};
     QString getRefferenceProduit() { return REFFERENCE_PRODUIT; };
     QString getQuantite() { return QUANTITE; };
     int getID() { return ID_CLIENT; };
     QString getDateCommande() { return DATE_COMMANDE; };
     QString getEtat() { return ETAT; };

     //setters
     void setIDCommande(int idc){ID_COMMANDE=idc;}
     void setRefferenceProduit(QString refferenceproduit) { REFFERENCE_PRODUIT = refferenceproduit; }
     void setQuantite(QString quantite) { QUANTITE = quantite; }
     void setIDClient(int id) { ID_CLIENT = id; }
     void setDateCommande(QString datecommande) { DATE_COMMANDE = datecommande; }
     void setEtat(QString etat) { ETAT = etat; }

     //fonctions
     bool ajouter();
     bool supprimer(int idcommande); 
     bool modifier(QString ETAT);
     QSqlQueryModel *afficher();
     QSqlQueryModel *recherche_ID_COMMANDE(int ID_COMMANDE);
     QSqlQueryModel *recherche_REFFERENCE_PRODUIT(QString REFFERENCE_PRODUIT);
     QSqlQueryModel *recherche_QUANTITE(QString QUANTITE);
     QSqlQueryModel *recherche_ID_CLIENT(int ID_CLIENT);
     QSqlQueryModel *recherche_ETAT(QString ETAT);


private:
     int ID_COMMANDE;
     QString REFFERENCE_PRODUIT;
     QString QUANTITE;
     int ID_CLIENT;
     QString DATE_COMMANDE;
     QString ETAT;

};

#endif // COMMANDE_H
