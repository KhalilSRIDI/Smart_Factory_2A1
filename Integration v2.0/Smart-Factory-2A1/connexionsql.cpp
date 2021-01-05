#include "connexionsql.h"
connexionSQL::connexionSQL()
{
}
bool connexionSQL::ouvrirConnexion()
{
    bool testOuverture=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("SmartFactory");
    db.setUserName("khalil2");
    db.setPassword("khalil2");
    if (db.open())
        testOuverture=true;
    return  testOuverture;
}
void connexionSQL::fermerConnexion()
{db.close();}
