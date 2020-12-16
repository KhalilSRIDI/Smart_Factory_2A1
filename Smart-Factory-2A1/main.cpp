#include "smart_factory_2a1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexionSQL c;
    bool verifConnexion = c.ouvrirConnexion();
    Smart_Factory_2A1 s;
    if(verifConnexion)
    {
        s.show();
        s.statusBar()->showMessage("DATABASE CONNECTED",5000);
    }
    return a.exec();
}
