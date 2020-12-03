#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
        bool test=c.createconnection(); //pour savoir si la connection est-elle etablie
        if(test)
          //  qDebug() <<"Connection réussite";
            QMessageBox::information(nullptr , QObject::tr("database is open"),
                                     QObject::tr("Connection successful\n" "Click OK to exit"),QMessageBox::Ok);
        else
                      // qDebug()  <<"erreur de connection";

            QMessageBox::critical(nullptr , QObject::tr("database is not open"),
                                  QObject::tr("Connection failed\n" "Click Cancel to exit"),QMessageBox::Cancel);

    w.show();
    return a.exec();
}
