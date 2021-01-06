#ifndef LOGIN_H
#define LOGIN_H
#include "connexionsql.h"


class login
{
public:
    login();
    int connecter(QString,QString);
    int recupererDepartement(int);
    QString infoSession(int);
    QByteArray recupererImage(int);
    int hash(QString);

};

#endif // LOGIN_H
