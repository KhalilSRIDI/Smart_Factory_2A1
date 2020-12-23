#include "connexionsql.h"
connexionSQL::connexionSQL()
{
}
bool connexionSQL::ouvrirConnexion()
{
    bool testOuverture=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("gestionPersonnelProfil");
    db.setUserName("safwen");
    db.setPassword("safwen");
    if (db.open())
        testOuverture=true;
    return  testOuverture;
}
void connexionSQL::fermerConnexion()
{db.close();}
