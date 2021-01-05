#ifndef LOGIN_H
#define LOGIN_H
#include "connexionsql.h"


class login
{
public:
    login();
    int connecter(QString,QString);
    int recupererDepartement(int);
};

#endif // LOGIN_H
