#include "connexion.h"
Connexion::Connexion()
{

}

bool Connexion::ouvrirconnexion()
{
    bool testOuverture=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("projet2A");
    db.setUserName("mohannad");
    db.setPassword("mohannad");
    if (db.open())
        testOuverture=true;
    return  testOuverture;
}

void Connexion::fermerconnexion()
{db.close();}
