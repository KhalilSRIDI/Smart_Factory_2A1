#include "mainwindow.h"
#include "connexion.h"
#include "gestionmateriel.h"
#include "gestionmaintenance.h"
#include "email.h"
#include "statis.h"
#include <QMessageBox>
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;
    bool test=c.ouvrirconnexion();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click ok to continue."), QMessageBox::Ok);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();

}
