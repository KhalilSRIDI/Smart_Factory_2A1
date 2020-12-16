#ifndef LOGIN_H
#define LOGIN_H
#include "connexionsql.h"


class login
{
public:
    login();
    int connecter(QString,QString);
};

#endif // LOGIN_H
