#include "connection.h"
#include "QSqlDatabase"

connection::connection()
{

}

bool connection::createconnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("iheb");
    db.setPassword("iheb");

    if(db.open())
        test=true;
    return test ;
}
