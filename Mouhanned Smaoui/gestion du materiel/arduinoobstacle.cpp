#include "arduinoobstacle.h"
#include "ui_arduinoobstacle.h"
#include "arduinoobstacle.h"
arduinoobstacle::arduinoobstacle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smart)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
}

void arduinoobstacle::update_label()
{
    data=A.read_from_arduino();
    serialBuffer+=QString::fromStdString(data.toStdString());
   qDebug() << "arduino is available but not connected to :" <<serialBuffer;
    ui->lineEdit->setText(serialBuffer);

}
arduinoobstacle::~arduinoobstacle()
{
    delete ui;
}

void arduinoobstacle::on_pushButton_clicked()
{


}


void arduinoobstacle::on_pushButton_on_clicked()
{
    A.write_to_arduino("0");
}

void arduinoobstacle::on_pushButton_off_2_clicked()
{
    A.write_to_arduino("1");
}

void arduinoobstacle::on_pushButton_onrouge_clicked()
{
     A.write_to_arduino("3");
}

void arduinoobstacle::on_pushButton_3_clicked()
{A.write_to_arduino("2");

}
