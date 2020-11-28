#include "gestionpersonnelprofil.h"
#include "ui_gestionpersonnelprofil.h"
#include "personnels.h"
#include "profile.h"

GestionPersonnelProfil::GestionPersonnelProfil(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionPersonnelProfil)
{
    ui->setupUi(this);
    ui->tablePers->setModel(tmpPersonnels.afficher());
    ui->tablePers->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablePers->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablePro->setModel(tmpProfils.afficher());
    ui->tablePro->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablePro->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->cin->setMaxLength(8);
    ui->numTel->setMaxLength(8);
    ui->nom->setMaxLength(15);
    ui->prenom->setMaxLength(15);
    ui->email->setMaxLength(35);
    ui->salaire->setRange(0,10000);
    ui->dateRecrutement->setDate(QDate::currentDate());
    ui->dateRecrutement->setMaximumDate(QDate::currentDate());
    ui->dateNaissance->setMaximumDate(QDate::currentDate().addYears(-18));

}
GestionPersonnelProfil::~GestionPersonnelProfil()
{
    delete ui;
}
void GestionPersonnelProfil::on_gestionPersonnel_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionPersonnelProfil::on_gestionProfil_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    ui->stackedWidget->setCurrentIndex(1);
}
void GestionPersonnelProfil::on_vAjouterPers_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    int cin = ui->cin->text().toInt();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    int numTel = ui->numTel->text().toInt();
    QString email = ui->email->text();
    QString sexe ;
    if(ui->masculin->isChecked())
        sexe =ui->masculin->text();
    if(ui->feminin->isChecked())
        sexe = ui->feminin->text();
    QString etatcivile = "";
    if(ui->marie->isChecked())
        etatcivile = ui->marie->text();
    if(ui->divorce->isChecked())
        etatcivile = ui->divorce->text();
    if(ui->celeb->isChecked())
        etatcivile = ui->celeb->text();
    QDate dateNaissance = ui->dateNaissance->date();
    QString gouvernoratOrigin = ui->gouvernoratOrigin->currentText();
    QString gouvernoratHabitation = ui->gouvernoratHabitation->currentText();
    QString diplomeEtude;
    if(ui->bac->isChecked())
        diplomeEtude = ui->bac->text();
    if(ui->ingenieur->isChecked())
        diplomeEtude = ui->ingenieur->text();
    if(ui->technicien->isChecked())
        diplomeEtude = ui->technicien->text();
    if(ui->doctorant->isChecked())
        diplomeEtude = ui->doctorant->text();
    QDate dateRecrutement = ui->dateRecrutement->date();
    QString typeContrat ;
    if(ui->sivp->isChecked())
        typeContrat = ui->sivp->text();
    if(ui->cdd->isChecked())
        typeContrat = ui->cdd->text();
    if(ui->cdi->isChecked())
        typeContrat =ui->cdi->text();
    QString departement = ui->departement->currentText();
    QString unite = ui->unite->currentText();
    QString fonction = ui->fonction->currentText();
    int salaire = ui->salaire->value();
    personnels p(cin,nom,prenom,numTel,email,sexe,etatcivile,dateNaissance,gouvernoratOrigin,gouvernoratHabitation,diplomeEtude,dateRecrutement,typeContrat,departement,unite,fonction,salaire);
    if(p.ajouter())
    {
        ui->statusbar->showMessage("DATA INSERTED ",5000);
        ui->tablePers->setModel(tmpPersonnels.afficher());
    }
    else
    {
        QMessageBox::critical(this,"Ajouter Personnel !","Erreur lors de l'Ajout de ce Personnel\nVeuillez réssayer de Nouveau");
    }

}
void GestionPersonnelProfil::on_modifierPers_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    if(ui->modifierPers->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("PERSONNELS");
        tableModel->select();
        ui->tablePers->setModel(tableModel);
        ui->modifierPers->setText("Tableau Modifiable");
        ui->statusbar->showMessage("MODIFY ON ",5000);
    }
    else
    {
        ui->tablePers->setModel(tmpPersonnels.afficher());
        ui->modifierPers->setText("Tableau Non Modifiable");
        ui->statusbar->showMessage("MODIFY OFF ",5000);
    }
}
void GestionPersonnelProfil::on_supprimerPers_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QItemSelectionModel *select = ui->tablePers->selectionModel();
    int matricule =select->selectedRows(0).value(0).data().toInt();
    if(tmpPersonnels.supprimer(matricule))
    {
        ui->tablePers->setModel(tmpPersonnels.afficher());
        ui->statusbar->showMessage("SUPPRESSION ",5000);
    }
}
void GestionPersonnelProfil::exporter(QTableView *table)
{
    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                    filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }
}
void GestionPersonnelProfil::on_exportExcel_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    exporter(ui->tablePers);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);
}
void GestionPersonnelProfil::on_vAjouterPro_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    int matricule = ui->matriculeP->text().toInt();
    QString nomUP = ui->nomUP->text();
    QString mdp = ui->motDePasseP->text();
    profils p(matricule,nomUP,mdp);
    if(p.ajouter())
    {
        ui->statusbar->showMessage("DATA INSERTED ",5000);
        ui->tablePro->setModel(tmpProfils.afficher());
    }
}
void GestionPersonnelProfil::on_modifierPro_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    if(ui->modifierPro->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("PROFILS");
        tableModel->select();
        ui->tablePro->setModel(tableModel);
        ui->modifierPro->setText("Tableau Modifiable");
        ui->statusbar->showMessage("MODIFY ON ",5000);
    }
    else
    {
        ui->tablePro->setModel(tmpProfils.afficher());
        ui->modifierPro->setText("Tableau Non Modifiable");
        ui->statusbar->showMessage("MODIFY OFF ",5000);
    }

}
void GestionPersonnelProfil::on_supprimerPro_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QItemSelectionModel *select = ui->tablePro->selectionModel();
    int id =select->selectedRows(0).value(0).data().toInt();
    if(tmpProfils.supprimer(id))
    {
        ui->tablePro->setModel(tmpProfils.afficher());
        ui->statusbar->showMessage("SUPPRESSION ",5000);
    }

}
void GestionPersonnelProfil::on_exportExcelP_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    exporter(ui->tablePro);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);

}
void GestionPersonnelProfil::on_matCh_returnPressed()
{
    int matricule = ui->matCh->text().toInt();
    QSqlQueryModel * verifCh=tmpPersonnels.chercherPersonnel(matricule);
    if(verifCh != nullptr)
    {
        ui->tablePers->setModel(verifCh);
    }
    else
    {
        ui->statusbar->showMessage("Matricule Non Trouvée");
    }
}
void GestionPersonnelProfil::on_fonctionCh_currentIndexChanged(int index)
{
    QString fonction = ui->fonctionCh->currentText();
    QSqlQueryModel * verifCh=tmpPersonnels.chercherPersonnelFonction(fonction);
    if(verifCh != nullptr)
    {
        ui->tablePers->setModel(verifCh);
    }
    else
    {
        ui->statusbar->showMessage("Fonction Non Trouvée",5000);
    }
}
void GestionPersonnelProfil::on_chercherDate_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QDate date1 = ui->dateCh1->date();
    QDate date2 = ui->dateCh2->date();
    QSqlQueryModel * verifCh=tmpPersonnels.chercherPersonnelPeriodeRec(date1,date2);
    if(verifCh != nullptr)
    {
        ui->tablePers->setModel(verifCh);
    }
}
void GestionPersonnelProfil::on_chercherTripleC_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QString sexe;
    if(ui->masculinCh->isChecked())
        sexe =ui->masculinCh->text();
    if(ui->femininCh->isChecked())
        sexe = ui->femininCh->text();
    QString etatcivile ;
    if(ui->marieCh->isChecked())
        etatcivile = ui->marieCh->text();
    if(ui->divorceCh->isChecked())
        etatcivile = ui->divorceCh->text();
    if(ui->celebCh->isChecked())
        etatcivile = ui->celebCh->text();
    int age = ui->ageCh->currentText().toInt();
    QSqlQueryModel * verifCh=tmpPersonnels.chercherPersonnel3C(sexe,etatcivile,age);
    if(verifCh != nullptr)
    {
        ui->tablePers->setModel(verifCh);
    }
}
void GestionPersonnelProfil::on_trier_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    if(ui->matT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("matricule",ui->AD->currentText()));
    }
    else if(ui->nomT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("nom",ui->AD->currentText()));
    }
    else if(ui->ageT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("date_naissance",ui->AD->currentText()));
    }
    else if(ui->ancienneteT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("date_recrutement",ui->AD->currentText()));
    }
    else if(ui->salaireT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("salaire",ui->AD->currentText()));
    }
}
void GestionPersonnelProfil::on_trierM_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QString cN="";
    QString cAg="";
    QString cAn="";
    QString cS="";
    if(ui->nomT_2->isChecked())
        cN=ui->nomT_2->text();
    if(ui->ageT_2->isChecked())
        cAg="date_naissance";
    if(ui->ancienneteT_2->isChecked())
        cAn="date_recrutement";
    if(ui->salaireT_2->isChecked())
        cS=ui->salaireT_2->text();
    ui->tablePers->setModel(tmpPersonnels.trier(cN,cAg,cAn,cS,ui->AD_2->currentText()));
}
void GestionPersonnelProfil::on_nomCh_textChanged(const QString &arg1)
{
    QSqlQueryModel * verifCh=tmpPersonnels.chercherPersonnel(arg1);
    ui->tablePers->setModel(verifCh);
}
