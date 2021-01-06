#include "smart_factory_2a1.h"
#include "ui_smart_factory_2a1.h"

Smart_Factory_2A1::Smart_Factory_2A1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Smart_Factory_2A1)
{
    ui->setupUi(this);
    ui->smartFactory->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);

    chaine=QRegExp("[a-zA-Z]{3,15}$");
    numeroCin=QRegExp("[0-9]{8}$");
    numeroTelephone=QRegExp("[1-9]{8}$");
    nomUtilisateur = QRegExp("[a-zA-Z]+[_]+[a-zA-Z]$");
    email = QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");


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
    ui->salaire->setRange(0,10000);
    ui->dateRecrutement->setDate(QDate::currentDate());
    ui->dateRecrutement->setMaximumDate(QDate::currentDate());
    ui->dateNaissance->setMaximumDate(QDate::currentDate().addYears(-18));
    ui->dateCh1->setDate(QDate::currentDate().addYears(-10));
    ui->dateCh2->setDate(QDate::currentDate());
    ui->dateCh2->setMaximumDate(QDate::currentDate());

    reduireAnimation = new QPropertyAnimation(ui->groupProfil,"maximumWidth");
    reduireAnimation->setDuration(400);
    reduireAnimation->setStartValue(500);
    reduireAnimation->setEndValue(110);
    etendreAnimation = new QPropertyAnimation(ui->groupProfil,"maximumWidth");
    etendreAnimation->setDuration(400);
    etendreAnimation->setStartValue(100);
    etendreAnimation->setEndValue(500);
    ui->reduire->setText("Reduire");
    etendreAnimation->start();
    ui->gestionPersonnelProfil->setDisabled(1);
    ui->gestionStock->setDisabled(1);
    ui->gestionAchats->setDisabled(1);
    ui->gestionVentes->setDisabled(1);
    ui->gestionEquipements->setDisabled(1);
    ui->gestionAmeliorations->setDisabled(1);
}

Smart_Factory_2A1::~Smart_Factory_2A1()
{
    delete ui;
}


void Smart_Factory_2A1::on_login_clicked()
{
    if(authentification.connecter(ui->nomUC->text(),ui->mdpC->text())!=0)
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->nomProfil->setText(authentification.infoSession(authentification.connecter(ui->nomUC->text(),ui->mdpC->text())));

        QPixmap outPixmap = QPixmap();
        outPixmap.loadFromData(authentification.recupererImage(authentification.connecter(ui->nomUC->text(),ui->mdpC->text())),"PNG");
        outPixmap = outPixmap.scaledToWidth(ui->imageProfil->width(),Qt::SmoothTransformation);
        ui->imageProfil->setPixmap(outPixmap);

        switch(authentification.recupererDepartement(authentification.connecter(ui->nomUC->text(),ui->mdpC->text())))
        {
        case 1:
            ui->gestionPersonnelProfil->setEnabled(1);
            break;
        case 2:
            ui->gestionStock->setEnabled(1);
            break;
        case 3:
            ui->gestionAchats->setEnabled(1);
            break;
        case 4:
            ui->gestionVentes->setEnabled(1);
            break;
        case 5:
            ui->gestionAmeliorations->setEnabled(1);
            break;
        case 6:
            ui->gestionEquipements->setEnabled(1);
            break;
        case 7:
            ui->gestionPersonnelProfil->setEnabled(1);
            ui->gestionStock->setEnabled(1);
            ui->gestionAchats->setEnabled(1);
            ui->gestionVentes->setEnabled(1);
            ui->gestionEquipements->setEnabled(1);
            ui->gestionAmeliorations->setEnabled(1);
            break;
        }
    }
    else
        ui->statusbar->showMessage("Failed To Connect",5000);

}

void Smart_Factory_2A1::on_gestionPersonnelProfil_clicked()
{
    ui->smartFactory->setCurrentIndex(0);
}
void Smart_Factory_2A1::on_gestionPersonnel_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->statusbar->showMessage("Gestion Personnel",5000);
}

void Smart_Factory_2A1::on_gestionProfil_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->statusbar->showMessage("Gestion Profil",5000);
}
void Smart_Factory_2A1::on_vAjouterPers_clicked()
{
    bool verifCin = numeroCin.exactMatch(ui->cin->text());
    bool verifTel = numeroCin.exactMatch(ui->numTel->text());
    bool verifNom = chaine.exactMatch(ui->nom->text());
    bool verifPrenom = chaine.exactMatch(ui->prenom->text());

    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QString cin = ui->cin->text();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString numTel = ui->numTel->text();
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
    QString filename = QFileDialog::getOpenFileName(this,"Choisir Une Image","","Images(*.png)");
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            QDir path = QFileInfo(filename).absoluteDir();
            QString filePath=path.absolutePath();
            image = image.scaledToWidth(ui->imagePers->width(),Qt::SmoothTransformation);
            ui->imagePers->setPixmap(QPixmap::fromImage(image));
            ui->statusbar->showMessage(filename);
        }
    }
    QByteArray byte;
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        byte = file.readAll();
        file.close();
    }
    personnels p(cin,nom,prenom,numTel,sexe,etatcivile,dateNaissance,gouvernoratOrigin,gouvernoratHabitation,diplomeEtude,dateRecrutement,typeContrat,departement,unite,fonction,salaire,byte);
    if(verifCin and verifTel and verifNom and verifPrenom and byte != nullptr)
    {
        p.ajouter();
        ui->statusbar->showMessage("Personnel Ajouté ",5000);
        ui->tablePers->setModel(tmpPersonnels.afficher());
    }
    else
    {
        QMessageBox::critical(this,"Ajouter Personnel !","Erreur lors de l'Ajout de ce Personnel\nVeuillez réssayer de Nouveau");
    }
}
void Smart_Factory_2A1::on_modifierPers_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    if(ui->modifierPers->isChecked())
    {

        ui->tablePers->setModel(tmpPersonnels.modifier());
        ui->modifierPers->setText("Tableau Modifiable");
        ui->statusbar->showMessage("Tableau Modifiable ",5000);
    }
    else
    {
        ui->tablePers->setModel(tmpPersonnels.afficher());
        ui->modifierPers->setText("Tableau Non Modifiable");
        ui->statusbar->showMessage("Tableau Non Modifiable ",5000);
    }
}
void Smart_Factory_2A1::on_supprimerPers_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QItemSelectionModel *select = ui->tablePers->selectionModel();
    int matricule =select->selectedRows(0).value(0).data().toInt();
    if(tmpPersonnels.supprimer(matricule))
    {
        ui->tablePers->setModel(tmpPersonnels.afficher());
        ui->statusbar->showMessage("Personnel Supprimé ",5000);
    }
}
void Smart_Factory_2A1::on_vAjouterPro_clicked()
{
    bool verifEmail = email.exactMatch(ui->email->text());
    bool verifNU = nomUtilisateur.exactMatch(ui->nomUP->text());

    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    int matricule = ui->matriculeP->text().toInt();
    QString nomUP = ui->nomUP->text();
    QString email = ui->email->text();;
    QString mdp = ui->motDePasseP->text();
    profils p(matricule,nomUP,email,mdp);
    if(verifEmail /*and verifNU*/)
    {
        p.ajouter();
        ui->tablePro->setModel(tmpProfils.afficher());
        ui->statusbar->showMessage("Profil Ajouté ",5000);
    }
    else
        QMessageBox::critical(this,"Ajouter Profil !","Erreur lors de l'Ajout de ce Profil\nVeuillez réssayer de Nouveau");

}
void Smart_Factory_2A1::on_modifierPro_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    if(ui->modifierPro->isChecked())
    {
        ui->tablePro->setModel(tmpProfils.modifier());
        ui->modifierPro->setText("Tableau Modifiable");
        ui->statusbar->showMessage("Tableau Modifiable ",5000);
    }
    else
    {
        ui->tablePro->setModel(tmpProfils.afficher());
        ui->modifierPro->setText("Tableau Non Modifiable");
        ui->statusbar->showMessage("Tableau Non Modifiable ",5000);
    }
}
void Smart_Factory_2A1::on_supprimerPro_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QItemSelectionModel *select = ui->tablePro->selectionModel();
    int id =select->selectedRows(0).value(0).data().toInt();
    if(tmpProfils.supprimer(id))
    {
        ui->tablePro->setModel(tmpProfils.afficher());
        ui->statusbar->showMessage("Profil Supprimé ",5000);
    }
}
void Smart_Factory_2A1::on_afficherTablePro_clicked()
{
    ui->tablePro->setModel(tmpProfils.afficher());
    ui->statusbar->showMessage("Tableau Des Profils");
}
void Smart_Factory_2A1::on_afficherTablePers_clicked()
{
    ui->tablePers->setModel(tmpPersonnels.afficher());
    ui->statusbar->showMessage("Tableau Des Personnels");
}
void Smart_Factory_2A1::exporter(QTableView *table)
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
void Smart_Factory_2A1::on_exportExcel_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    exporter(ui->tablePers);
    ui->statusbar->showMessage("Export De Tableau Personnel ",5000);
}
void Smart_Factory_2A1::on_exportExcelP_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    exporter(ui->tablePro);
    ui->statusbar->showMessage("Export De Tableau Profil ",5000);
}
void Smart_Factory_2A1::on_trier_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    if(ui->matT->isChecked())
    {
        ui->tablePro->setModel(tmpProfils.trier("matricule",ui->AD->currentText()));
        ui->statusbar->showMessage("Tableau Profils Trié Selon Matricule");
    }
    else if(ui->nomUT->isChecked())
    {
        ui->tablePro->setModel(tmpProfils.trier("nom_utilisateur",ui->AD->currentText()));
        ui->statusbar->showMessage("Tableau Profils Trié Selon Nom Utilisateur");
    }
    else if(ui->idT->isChecked())
    {
        ui->tablePro->setModel(tmpProfils.trier("id",ui->AD->currentText()));
        ui->statusbar->showMessage("Tableau Profils Trié Selon Id");
    }
}
void Smart_Factory_2A1::on_trierM_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    int check=0;
    QString cD="";
    QString cU="";
    QString cF="";
    QString cS="";
    if(ui->departementT->isChecked())
    {
        check++;
        if(check==1)
        {
            cD=ui->departementT->text();
        }
    }
    if(ui->UniteT->isChecked())
    {
        check++;
        if(check==1)
        {
            cU="unite";
        }
        else if(check==1)
        {
            cU=",unite";
        }
    }
    if(ui->FonctionT->isChecked())
    {
        check++;
        if(check==1)
        {
            cF="fonction";
        }
        else
            cF=",fonction";
    }
    if(ui->salaireTM->isChecked())
    {
        check++;
        if(check==1)
        {
            cS=ui->salaireTM->text();
        }
        else
            cS=","+ui->salaireTM->text();
    }

    ui->tablePers->setModel(tmpPersonnels.trier(cD,cU,cF,cS,ui->AD_2->currentText()));
}
void Smart_Factory_2A1::on_nomCh_textChanged(const QString &arg1)
{
    ui->tablePers->setModel(tmpPersonnels.chercherNom(arg1));
}

void Smart_Factory_2A1::on_matCh_returnPressed()
{
    int matricule = ui->matCh->text().toInt();
    if(tmpPersonnels.chercher(matricule)!= nullptr)
    {
        ui->tablePers->setModel(tmpPersonnels.chercher(matricule));
        ui->statusbar->showMessage("Personnel Trouvé",5000);
    }
    else
        QMessageBox::critical(this,"Recherche Personnel !","Erreur lors de Recherche:\nPersonnel Non Trouvé");
}
void Smart_Factory_2A1::on_fonctionCh_currentIndexChanged(int index)
{
    if(tmpPersonnels.chercherFonction(ui->fonctionCh->currentText()) != nullptr)
    {
        ui->tablePers->setModel(tmpPersonnels.chercherFonction(ui->fonctionCh->currentText()));
        ui->statusbar->showMessage("Personnel Trouvé",5000);
    }
    else
        QMessageBox::critical(this,"Recherche Fonctionnaire !","Erreur lors de Recherche:\nFonctionnaire Non Trouvé");
}
void Smart_Factory_2A1::on_chercherDate_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    QDate date1 = ui->dateCh1->date();
    QDate date2 = ui->dateCh2->date();
    if(tmpPersonnels.chercher(date1,date2) != nullptr)
    {
        ui->tablePers->setModel(tmpPersonnels.chercher(date1,date2));
        ui->statusbar->showMessage("Personnel Trouvé",5000);
    }
    else
        QMessageBox::critical(this,"Recherche Personnel !","Erreur lors de Recherche:\nPersonnel Non Trouvé");
}
void Smart_Factory_2A1::on_chercherTripleC_clicked()
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
    if(tmpPersonnels.chercher(sexe,etatcivile,age) != nullptr)
    {
        ui->tablePers->setModel(tmpPersonnels.chercher(sexe,etatcivile,age));
        ui->statusbar->showMessage("Personnel Trouvé",5000);
    }
    else
        QMessageBox::critical(this,"Recherche Personnel !","Erreur lors de Recherche:\nPersonnel Non Trouvé");
}
void Smart_Factory_2A1::on_trierS_clicked()
{
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    if(ui->matTP->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("matricule",ui->AD_3->currentText()));
    }
    else if(ui->nomT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("nom",ui->AD_3->currentText()));
    }
    else if(ui->ageT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("date_naissance",ui->AD_3->currentText()));
    }
    else if(ui->ancienneteT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("date_recrutement",ui->AD_3->currentText()));
    }
    else if(ui->salaireT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trier("salaire",ui->AD_3->currentText()));
    }

}





void Smart_Factory_2A1::on_reduire_clicked()
{
    static int turn=1;
    QSound::play("C:/Users/DELL/Documents/GitHub/Smart_Factory_2A1/Safouene Jebali/gestionPersonnelProfil/clickSound.wav");
    if (turn==1)
    {
        reduireAnimation->start();
        ui->reduire->setText("Etendre");
    }
    else
    {
        etendreAnimation->start();
        ui->reduire->setText("Reduire");
    }
    turn*=-1;
}

void Smart_Factory_2A1::on_statistiques_clicked()
{
    statistiques s;
    s.setModal(true);
    s.exec();
}

void Smart_Factory_2A1::on_Afficher1Pers_clicked()
{
    afficherUnPersonnel afficherUnPersonnel;
    afficherUnPersonnel.setModal(true);
    afficherUnPersonnel.exec();
}






void Smart_Factory_2A1::on_gestionAmeliorations_clicked()
{
    ui->smartFactory->setCurrentIndex(1);
}


void Smart_Factory_2A1::on_gestionStock_clicked()
{
    ui->smartFactory->setCurrentIndex(5);
}

void Smart_Factory_2A1::on_gestionAchats_clicked()
{
    ui->smartFactory->setCurrentIndex(6);
}

void Smart_Factory_2A1::on_gestionVentes_clicked()
{
    ui->smartFactory->setCurrentIndex(4);
}

void Smart_Factory_2A1::on_gestionEquipements_clicked()
{
    ui->smartFactory->setCurrentIndex(2);
}

void Smart_Factory_2A1::on_deconnecter_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->gestionPersonnelProfil->setDisabled(1);
    ui->gestionStock->setDisabled(1);
    ui->gestionAchats->setDisabled(1);
    ui->gestionVentes->setDisabled(1);
    ui->gestionEquipements->setDisabled(1);
    ui->gestionAmeliorations->setDisabled(1);
    ui->nomUC->setText("");
    ui->mdpC->setText("");
}

void Smart_Factory_2A1::on_envoyerMail_2_clicked()
{
    QItemSelectionModel *select = ui->tablePers->selectionModel();
    QString email =select->selectedRows(4).value(0).data().toString();

    QDialog *d=new Dialog(email,"","",this);
    d->show();
    d->exec();

}

QByteArray Smart_Factory_2A1::on_ajouterImgPers_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Choisir Une Image","","Images(*.png)");
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            QDir path = QFileInfo(filename).absoluteDir();
            QString filePath=path.absolutePath();
            image = image.scaledToWidth(ui->imagePers->width(),Qt::SmoothTransformation);
            ui->imagePers->setPixmap(QPixmap::fromImage(image));
            ui->statusbar->showMessage(filename);
        }
    }
    QByteArray byte;
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        byte = file.readAll();
        file.close();
    }
    else
        QMessageBox :: critical(this,"Error",filename);
    return byte;

}

void Smart_Factory_2A1::on_gestionProjet_clicked()
{
 ui->stackedWidgetAmelioration->setCurrentIndex(1);
}

void Smart_Factory_2A1::on_gestionFormation_clicked()
{
    ui->stackedWidgetAmelioration->setCurrentIndex(0);

}

void Smart_Factory_2A1::on_gestionEquipement_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void Smart_Factory_2A1::on_gestionMaintenances_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}


