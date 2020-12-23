#include "gestionpersonnelprofil.h"
#include "connexionsql.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexionSQL c;
    bool verifConnexion = c.ouvrirConnexion();

    GestionPersonnelProfil w;
    if(verifConnexion)
    {

        w.show();
        w.statusBar()->showMessage("DATABASE CONNECTED",5000);
    }
    return a.exec();
}
