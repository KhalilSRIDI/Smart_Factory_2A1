#include "afficherunpersonnel.h"
#include "ui_afficherunpersonnel.h"

afficherUnPersonnel::afficherUnPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficherUnPersonnel)
{
    ui->setupUi(this);
}

afficherUnPersonnel::~afficherUnPersonnel()
{
    delete ui;
}
void afficherUnPersonnel::on_imprimerBoutton_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected)return;
    ui->textAffichePers->print(&printer);
}
void afficherUnPersonnel::on_rechAffPers_clicked()
{
    QString matricule = ui->matAffPers->text();
    QSqlQuery qry;
    qry.prepare("select * from PERSONNELS where MATRICULE='"+matricule+"'");
    if(qry.exec())
        if(qry.next())
        {
            QString text;
            text += "<br> <img src='E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/test.png' height='42' width='144'/>";
            text += "<h1  style='color:red'>Nom :</h1><h1  style='color:black'>"+qry.value(2).toString()+"</h1>\n";
            text += "<h1  style='color:red'>Prenom :</h1><h1  style='color:black'>" + qry.value(3).toString() + "</h1>\n";
            text += "<h1  style='color:red'>Numero Cin :</h1><h1  style='color:black'>" + qry.value(1).toString() + "</h1>\n";
            text += "<h1  style='color:red'>Numero Telephone :</h1><h1  style='color:black'>" + qry.value(4).toString() + "</h1>\n";
            text += "<h1  style='color:red'>Sexe :</h1><h1  style='color:black'>"+ qry.value(5).toString() +"</h1>\n";
            text += "<h1  style='color:red'>Etat Civile :</h1><h1  style='color:black'>" + qry.value(6).toString() + "</h1>\n";
            text += "<h1  style='color:red'>Date De Naissance </h1><h1  style='color:black'>" + qry.value(7).toString() +"</h1>\n";
            text += "<h1  style='color:red'>Gouvernorat D Origin :</h1><h1  style='color:black'>" + qry.value(8).toString() + "</h1>\n";
            text += "<h1  style='color:red'>Gouvernorat D Habitation :</h1><h1  style='color:black'>" + qry.value(9).toString() + "</h1>\n";
            text += "<h1  style='color:red'>Diplome Etude :</h1><h1  style='color:black'>"+ qry.value(10).toString() +"</h1>\n";
            text += "<h1  style='color:red'>Date Recrutement :</h1><h1  style='color:black'>" + qry.value(12).toString() +"</h1>\n";
            text += "<h1  style='color:red'>Type Contrat :</h1><h1  style='color:black'>" + qry.value(11).toString() +"</h1>\n";
            text += "<h1  style='color:red'>Departement :</h1><h1  style='color:black'>" + qry.value(13).toString() + "</h1>\n";
            text += "<h1  style='color:red'>Unite :</h1><h1  style='color:black'>" + qry.value(14).toString() + "</h1>\n";
            text += "<h1  style='color:red'>Fonction :</h1><h1  style='color:black'>" + qry.value(15).toString() +"</h1>\n";
            text += "<h1  style='color:red'>Salaire : :<br></h1><h1  style='color:black'>" + qry.value(16).toString() +"</h1>\n";
            ui->textAffichePers->setText(text);
        }
}
