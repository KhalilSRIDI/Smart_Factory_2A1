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
        bool modifierMotDePasse(int,QString,QString );

};

#endif // LOGIN_H
