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
            text += "CIN : " + qry.value(0).toString() + "\n";
            text += "NOM : " + qry.value(1).toString() + "\n";
            text += "PRENOM : " + qry.value(2).toString() + "\n";
            text += "NUMERO TEL : " + qry.value(3).toString() + "\n";
            text += "EMAIL : " + qry.value(4).toString() + "\n";
            text += "SEXE : " + qry.value(5).toString() + "\n";
            text += "ETAT CIVILE : " + qry.value(6).toString() + "\n";
            text += "DATE DE NAISSANCE : " + qry.value(7).toString() + "\n";
            text += "GOUVERNORAT D ORIGIN : " + qry.value(8).toString() + "\n";
            text += "GOUVERNORAT D HABITATION : " + qry.value(9).toString() + "\n";
            text += "DIPLOME ETUDE : " + qry.value(10).toString() + "\n";
            text += "DATE RECRUTEMENT : " + qry.value(11).toString() + "\n";
            text += "TYPE CONTRAT : " + qry.value(12).toString() + "\n";
            text += "QUALIFICATION : " + qry.value(13).toString() + "\n";
            text += "FONCTION : " + qry.value(14).toString() + "\n";
            text += "SALAIRE : " + qry.value(15).toString() + "\n";
            text += "DEPARTEMENT : " + qry.value(16).toString() + "\n";
            text += "SUPERIEUR : " + qry.value(20).toString() + "\n";
            text += "STATUT : " + qry.value(21).toString() + "\n";
            /*   text += "CIN : " + qry.value(0).toString() + "\n";
           text += "CIN : " + qry.value(0).toString() + "\n";
           text += "CIN : " + qry.value(0).toString() + "\n";
           */
            ui->textAffichePers->setText(text);
        }
}
