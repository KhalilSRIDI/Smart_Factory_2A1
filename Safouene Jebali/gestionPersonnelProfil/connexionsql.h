#ifndef CONNEXIONSQL_H
#define CONNEXIONSQL_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
class connexionSQL
{
private:
    QSqlDatabase db;
public:
    connexionSQL();
    bool ouvrirConnexion();
    void fermerConnexion();
};
#endif // CONNEXIONSQL_H
