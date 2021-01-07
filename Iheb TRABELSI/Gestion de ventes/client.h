#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>

class client
{
public:
     client();
     client(int id,QString q,QString s,QString p):ID_CLIENT(id),QUANTITE_ARTICLES(q),STATUT(s),PRODUIT_ACHETE(p) {}

     //getters
      int getIDClient(){return ID_CLIENT;};
      QString getQuantiteArticles() { return QUANTITE_ARTICLES; };
      QString getStatut() { return STATUT; };
      QString getProduitAchete() { return PRODUIT_ACHETE; };

      //setters
      void setNom(int id){ID_CLIENT=id;}
      void setQuantiteArticles(QString quantitearticles) { QUANTITE_ARTICLES = quantitearticles; }
      void setStatut(QString statut) { STATUT = statut; }
      void setProduitAchete(QString produitachete) { PRODUIT_ACHETE = produitachete; }

      //fonctions
      bool ajouter();
      bool supprimer(int idclient);
      QSqlQueryModel *afficher();
      bool modifier(int id);
      QSqlQueryModel *recherche_client(int ID_CLIENT);
      QSqlQueryModel *recherche_client_QUANTITE_ARTICLES(QString QUANTITE_ARTICLES);
      QSqlQueryModel *recherche_client_STATUT(QString STATUT);
      QSqlQueryModel *recherche_client_PRODUIT_ACHETE(QString PRODUIT_ACHETE);


private:
      int ID_CLIENT;
      QString QUANTITE_ARTICLES;
      QString STATUT;
      QString PRODUIT_ACHETE;

};

#endif // CLIENT_H
