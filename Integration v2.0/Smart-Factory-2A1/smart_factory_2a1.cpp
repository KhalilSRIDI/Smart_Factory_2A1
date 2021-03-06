#include "smart_factory_2a1.h"
#include "ui_smart_factory_2a1.h"

Smart_Factory_2A1::Smart_Factory_2A1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Smart_Factory_2A1)
{

    ui->setupUi(this);



    ui->smartFactory->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);


    ui->comboBoxTeamLeader->setModel(tmp_projet.loadTL());
    ui->comboBoxPC->setModel(tmp_formation.loadPC());


    chaine=QRegExp("[a-zA-Z]{3,15}$");
    numeroCin=QRegExp("[0-9]{8}$");
    numeroTelephone=QRegExp("[1-9]{8}$");
    nomUtilisateur = QRegExp("[a-zA-Z]+[_]+[a-zA-Z]$");
    email = QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");

    ui->tableViewF->setModel(tmp_formation.afficher());
    ui->tableViewF->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewF->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewP->setModel(tmp_projet.afficher());
    ui->tableViewP->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewP->setSelectionMode(QAbstractItemView::SingleSelection);

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

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
        break;
    }

    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


}

Smart_Factory_2A1::~Smart_Factory_2A1()
{
    delete ui;
}


void Smart_Factory_2A1::on_login_clicked()
{
    if(authentification.connecter(ui->nomUC->text(),ui->mdpC->text())!=0)
    {
        //ui->matMP.setText(authentification.connecter(ui->nomUC->text(),ui->mdpC->text()));
        ui->stackedWidget->setCurrentIndex(1);
        ui->nomProfil->setText(authentification.infoSession(authentification.connecter(ui->nomUC->text(),ui->mdpC->text())));

        QPixmap outPixmap = QPixmap();
        outPixmap.loadFromData(authentification.recupererImage(authentification.connecter(ui->nomUC->text(),ui->mdpC->text())),"JPG");
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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    ui->stackedWidget_2->setCurrentIndex(0);
    ui->statusbar->showMessage("Gestion Personnel",5000);
}

void Smart_Factory_2A1::on_gestionProfil_clicked()
{
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->statusbar->showMessage("Gestion Profil",5000);
}
void Smart_Factory_2A1::on_vAjouterPers_clicked()
{
    bool verifCin = numeroCin.exactMatch(ui->cin->text());
    bool verifTel = numeroCin.exactMatch(ui->numTel->text());
    bool verifNom = chaine.exactMatch(ui->nom->text());
    bool verifPrenom = chaine.exactMatch(ui->prenom->text());

    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QString filename = QFileDialog::getOpenFileName(this,"Choisir Une Image","","Images(*.jpg)");
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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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


    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    int matricule = ui->matriculeP->text().toInt();
    QString nomUP = ui->nomUP->text();
    QString email = ui->email->text();;
    QString mdp = ui->motDePasseP->text();
    int verif=tmpProfils.verifUsername(matricule,nomUP);
    profils p(matricule,nomUP,email,mdp);
    if(verifEmail && verif==1/*and verifNU*/)
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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    exporter(ui->tablePers);
    ui->statusbar->showMessage("Export De Tableau Personnel ",5000);
}
void Smart_Factory_2A1::on_exportExcelP_clicked()
{
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    exporter(ui->tablePro);
    ui->statusbar->showMessage("Export De Tableau Profil ",5000);
}
void Smart_Factory_2A1::on_trier_clicked()
{
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

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
    ui->smartFactory->setCurrentIndex(6);
}

void Smart_Factory_2A1::on_gestionAchats_clicked()
{
    ui->smartFactory->setCurrentIndex(6);
}

void Smart_Factory_2A1::on_gestionVentes_clicked()
{
    ui->smartFactory->setCurrentIndex(6);
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



void Smart_Factory_2A1::on_pushButtonRechercheP_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    int critere=0;
    if(ui->checkBoxIDP->isChecked())
        critere=0;
    else if(ui->checkBoxNomP->isChecked())
        critere=1;
    else if(ui->checkBoxDepartementP->isChecked())
        critere=2;
    else if(ui->checkBoxTeamLeaderP->isChecked())
        critere=3;
    else if(ui->checkBoxDateLancementP->isChecked())
        critere=4;
    else if(ui->checkBoxCoutsP->isChecked())
        critere=5;
    else if(ui->checkBoxRevenusP->isChecked())
        critere=6;

    QString input = ui->lineEditRP->text();

    QSqlQueryModel *test=tmp_projet.chercher(input,critere);


    if(test != nullptr)
    {
        ui->tableViewP->setModel(test);
    }
    else
    {
        ui->tableViewP->setModel(test);
    }
}

void Smart_Factory_2A1::on_pushButtonStat_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    statistique2 *a= new statistique2() ;
    a->show();
}

void Smart_Factory_2A1::on_pushButtonExportP_clicked()
{
    tmp_projet.exporterExcel(ui->tableViewP);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);
}

void Smart_Factory_2A1::on_pushButtonExportPDFP_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM Projets ");
    q.exec();
    QString pdf="<br><h1  style='color:pink'>tableau projets  <br></h1>\n <br> <table>  <tr>  <th>IDPROJET </th> <th>NOM </th>  <th>DEPARTEMENT </th> <th>TEAM_LEADER </th>  <th>DATE_LANCEMENT </th> <th>COUTS_PREVUS </th> <th>REVENUS_PROJETES </th> </tr> " ;


    while ( q.next()) {
        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td> " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" </td>   <td>"+q.value(3).toString()+"</td> <td>"+q.value(4).toString()+"<td> <td>"+q.value(5).toString()+" </td> <td> "+q.value(6).toString()+" </td> </td>";

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);

}

void Smart_Factory_2A1::on_pushTrierP_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    ui->tableViewP->setModel(tmp_projet.afficher());
    QString critere;

    if(ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="IDPROJET";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM";
    }
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="DEPARTEMENT";
    }
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="TEAM_LEADER";
    }
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="DATE_LANCEMENT";
    }
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="COUTS_PREVUS";
    }

    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && ui->checkBoxRevenusP->isChecked())
    {
        critere="REVENUS_PROJETES";
    }
    //TRI MULTICRITERE
    //nom fixé 2 var
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,DEPARTEMENT";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,TEAM_LEADER";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,DATE_LANCEMENT";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,COUTS_PREVUS";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,REVENUS_PROJETES";
    }
    //departement fixé
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="DEPARTEMENT,TEAM_LEADER";
    }
    else if(!ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="DEPARTEMENT,DATE_LANCEMENT";
    }
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="DEPARTEMENT,COUTS_PREVUS";
    }
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && ui->checkBoxRevenusP->isChecked())
    {
        critere="DEPARTEMENT,REVENUS_PROJETES";
    }
    //team leader fixé
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="TEAM_LEADER,DATE_LANCEMENT";
    }else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="TEAM_LEADER,COUTS_PREVUS";
    }else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="TEAM_LEADER,REVENUS_PROJETES";
    }
    //date lancement fixé
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && ui->checkBoxDateLancementP->isChecked() && ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="DATE_LANCEMENT,COUTS_PREVUS";
    }
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && ui->checkBoxRevenusP->isChecked())
    {
        critere="DATE_LANCEMENT,REVENUS_PROJETES";
    }
    //couts fixé
    else if(!ui->checkBoxIDP->isChecked() && !ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && ui->checkBoxCoutsP->isChecked() && ui->checkBoxRevenusP->isChecked())
    {
        critere="COUTS_PREVUS,REVENUS_PROJETES";
    }
    //nom+departement fixés 3 var
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,DEPARTEMENT,TEAM_LEADER";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,DEPARTEMENT,DATE_LANCEMENT";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,DEPARTEMENT,COUTS_PREVUS";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,DEPARTEMENT,REVENUS_PROJETES";
    }
    //nom+team_leader fixés 3 var
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,TEAM_LEADER,DATE_LANCEMENT";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,TEAM_LEADER,COUTS_PREVUS";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,TEAM_LEADER,REVENUS_PROJETES";
    }
    //nom+date_lancement fixés 3 var
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && ui->checkBoxCoutsP->isChecked() && !ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,DATE_LANCEMENT,COUTS_PREVUS";
    }
    else if(!ui->checkBoxIDP->isChecked() && ui->checkBoxNomP->isChecked() && !ui->checkBoxDepartementP->isChecked() && !ui->checkBoxTeamLeaderP->isChecked() && !ui->checkBoxDateLancementP->isChecked() && !ui->checkBoxCoutsP->isChecked() && ui->checkBoxRevenusP->isChecked())
    {
        critere="NOM,DATE_LANCEMENT,REVENUS_PROJETES";
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Aucun critere"),
                              QObject::tr("Veuillez choisir un critere.\n"), QMessageBox::Cancel);

    }

    QString order = ui->comboBoxP->currentText();
    ui->tableViewP->setModel(tmp_projet.trier(critere,order));

}

void Smart_Factory_2A1::on_pushButtonAjouter_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");



    QString NOM=ui->lineEditNomP->text();
    QString DEPARTEMENT=ui->comboBoxDepartementP->currentText();
    QString TEAM_LEADER=ui->comboBoxTeamLeader->currentText();
    QString DATE_LANCEMENT=ui->dateEditLancementP->date().toString("dd/MM/yyyy");
    QString COUTS_PREVUS=ui->lineEditCoutP->text();
    QString REVENUS_PROJETES=ui->lineEditRevenuesP->text();

    projets projet(NOM, DEPARTEMENT, TEAM_LEADER, DATE_LANCEMENT, COUTS_PREVUS, REVENUS_PROJETES);
    if(projet.ajouter())
    {
        ui->tableViewP->setModel(tmp_projet.afficher());
        ui->statusbar->showMessage("AJOUT : SUCCESS");
        ui->lineEditNomP->setText("");
        ui->lineEditCoutP->setText("");
        ui->lineEditRevenuesP->setText("");
    }
    else
        ui->statusbar->showMessage("AJOUT : UNSUCCESS");
    ui->comboBoxTeamLeader->setModel(tmp_projet.loadTL());
    ui->comboBoxPC->setModel(tmp_formation.loadPC());
}

void Smart_Factory_2A1::on_pushButtonModifier_clicked()
{
    ui->pushButtonModifier->setText("Modifier");
    if(ui->pushButtonModifier->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("PROJETS");
        tableModel->select();
        ui->tableViewP->setModel(tableModel);
        ui->pushButtonModifier->setText("Tableau Modifiable");
    }
}

void Smart_Factory_2A1::on_pushButtonSupprimer_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");


    QItemSelectionModel *select = ui->tableViewP->selectionModel();
    int idprojet =select->selectedRows(0).value(0).data().toInt();
    if(tmp_projet.supprimer(idprojet))
    {
        ui->tableViewP->setModel(tmp_projet.afficher());
        ui->statusbar->showMessage("SUPPRESSION : SUCCESS");
    }
}

void Smart_Factory_2A1::on_pushButtonAjouterF_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    QString NOM=ui->lineEditNomF->text();
    QString PROJET=ui->comboBoxPC->currentText();
    QString FORMATEUR=ui->lineEditFormateur->text();
    QString DATEDEBUT=ui->dateEditDateF->date().toString("dd/MM/yyyy");
    QString DUREE=ui->lineEditDureeF->text();
    QString COUT=ui->lineEditCoutF->text();

    formation formation(NOM, PROJET, FORMATEUR, DATEDEBUT, DUREE, COUT);
    if(formation.ajouter())
    {
        ui->tableViewF->setModel(tmp_formation.afficher());
        ui->statusbar->showMessage("AJOUT : SUCCESS");
    }
    else
        ui->statusbar->showMessage("AJOUT : UNSUCCESS");
    ui->comboBoxTeamLeader->setModel(tmp_projet.loadTL());
    ui->comboBoxPC->setModel(tmp_formation.loadPC());
}

void Smart_Factory_2A1::on_pushButtonRechercheF_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    int critere=0;
    if(ui->checkBoxIDF->isChecked())
        critere=0;
    else if(ui->checkBoxNomF->isChecked())
        critere=1;
    else if(ui->checkBoxProjetF->isChecked())
        critere=2;
    else if(ui->checkBoxFormateurF->isChecked())
        critere=3;
    else if(ui->checkBoxDateF->isChecked())
        critere=4;
    else if(ui->checkBoxDureeF->isChecked())
        critere=5;
    else if(ui->checkBoxCoutF->isChecked())
        critere=6;

    QString input = ui->lineEditRF->text();

    QSqlQueryModel *test=tmp_formation.chercher(input,critere);


    if(test != nullptr)
    {
        ui->tableViewF->setModel(test);
    }
    else
    {
        ui->tableViewF->setModel(test);
    }
}

void Smart_Factory_2A1::on_envoyerMailFormations_clicked()
{
    QItemSelectionModel *select = ui->tablePers->selectionModel();
    QString email =select->selectedRows(4).value(0).data().toString();

    QDialog *d=new Dialog(email,"","",this);
    d->show();
    d->exec();
}

void Smart_Factory_2A1::on_pushButtonExportF_clicked()
{
    tmp_formation.exporterExcel(ui->tableViewF);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);

}

void Smart_Factory_2A1::on_pushButtonExportPDFF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM formations ");
    q.exec();
    QString pdf="<br><h1  style='color:pink'>tableau formations  <br></h1>\n <br> <table>  <tr>  <th>IDFORMATION </th> <th>NOM </th>  <th>PROJET </th> <th>FORMATEUR </th>  <th>DATEDEBUT </th> <th>DUREE </th> <th>COUT </th> </tr> " ;


    while ( q.next()) {
        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td> " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" </td>   <td>"+q.value(3).toString()+"</td> <td>"+q.value(4).toString()+"<td> <td>"+q.value(5).toString()+" </td> <td> "+q.value(6).toString()+" </td> </td>";

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

void Smart_Factory_2A1::on_pushTrierF_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    ui->tableViewF->setModel(tmp_formation.afficher());
    QString critere;

    if(ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="IDFORMATION";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="PROJET";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="FORMATEUR";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="DATEDEBUT";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="DUREE";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="COUT";
    }
    //TRI MULTICRITERE
    //nom fixé 2 var
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,PROJET";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,FORMATEUR";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,DATEDEBUT";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,DUREE";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,COUT";
    }
    //PROJET fixé
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="PROJET,FORMATEUR";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="PROJET,DATEDEBUT";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="PROJET,DUREE";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="PROJET,COUT";
    }
    //team leader fixé
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="FORMATEUR,DATEDEBUT";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="FORMATEUR,DUREE";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="FORMATEUR,COUT";
    }
    //date lancement fixé
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="DATEDEBUT,DUREE";
    }
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="DATEDEBUT,COUT";
    }
    //couts fixé
    else if(!ui->checkBoxIDF->isChecked() && !ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="DUREE,COUT";
    }
    //nom+PROJET fixés 3 var
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,PROJET,FORMATEUR";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,PROJET,DATEDEBUT";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,PROJET,DUREE";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,PROJET,COUT";
    }
    //nom+FORMATEUR fixés 3 var
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,FORMATEUR,DATEDEBUT";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,FORMATEUR,DUREE";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && !ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,FORMATEUR,COUT";
    }
    //nom+DATEDEBUT fixés 3 var
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && ui->checkBoxDureeF->isChecked() && !ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,DATEDEBUT,DUREE";
    }
    else if(!ui->checkBoxIDF->isChecked() && ui->checkBoxNomF->isChecked() && !ui->checkBoxProjetF->isChecked() && !ui->checkBoxFormateurF->isChecked() && ui->checkBoxDateF->isChecked() && !ui->checkBoxDureeF->isChecked() && ui->checkBoxCoutF->isChecked())
    {
        critere="NOM,DATEDEBUT,COUT";
    }
    else
    {
        ui->statusbar->showMessage("ERROR : AUCUN CRITERE CHOISI");

    }

    QString order = ui->comboBoxF->currentText();
    ui->tableViewF->setModel(tmp_formation.trier(critere,order));

}

void Smart_Factory_2A1::on_pushButtonModifierF_clicked()
{
    ui->pushButtonModifierF->setText("Modifier");

    if(ui->pushButtonModifierF->isChecked())
    {
        QSqlTableModel *tableModelF= new QSqlTableModel();
        tableModelF->setTable("FORMATIONS");
        tableModelF->select();
        ui->tableViewF->setModel(tableModelF);
        ui->pushButtonModifierF->setText("Tableau Modifiable");
    }
}

void Smart_Factory_2A1::on_pushButtonSupprimerF_clicked()
{
        QSound::play("E:/User/Khalil/ESPRIT/2ème année/Git/Smart_Factory_2A1/Integration v2.0/Smart-Factory-2A1/clickSound.wav");

    QItemSelectionModel *select = ui->tableViewF->selectionModel();
    int idformation =select->selectedRows(0).value(0).data().toInt();
    if(tmp_formation.supprimer(idformation))
    {
        ui->tableViewF->setModel(tmp_formation.afficher());
        ui->statusbar->showMessage("SUPPRESSION : SUCCESS");
    }
}

void Smart_Factory_2A1::on_afficherToutP_clicked()
{
    ui->tableViewP->setModel(tmp_formation.afficher());

}

void Smart_Factory_2A1::on_afficherToutF_clicked()
{
    ui->tableViewF->setModel(tmp_formation.afficher());

}

//gestion de materiel

void Smart_Factory_2A1::on_pushButton_valider_clicked()
{
    QString referene = ui->lineEdit_ref->text();
    QString modele = ui->lineEdit_modele->text();
    QDate date_achat = ui->dateEdit_achat->date();
    int nombre_maintenance = ui->lineEdit_nombre_maintenance->text().toInt();
    materiel m(referene,modele,date_achat,nombre_maintenance);
    bool test=m.ajouter();
    /* click = new QMediaPlayer();
       click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
        click->play();*/
    if (test)
    {

        ui->tableView_materiel->setModel(etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajouter un materiel"),
                                 QObject::tr("materiel ajouté.\n"
                                 "click ok to continue."), QMessageBox::Ok);
    }
    else QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                               QObject::tr("ajout non effectué.\n"
                                 "click cancel to exit."),QMessageBox::Cancel);
}

void Smart_Factory_2A1::on_pushButton_supprimer_clicked()
{
    QItemSelectionModel *select = ui->tableView_materiel->selectionModel();
    QString reference =select->selectedRows(0).value(0).data().toString();
    bool test=etmp.supprimer(reference);
    /* click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();*/
    if (test)
    {
        ui->tableView_materiel->setModel(etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("suppression effectuée\n"
                                             "click ok to continue."),QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectuée.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);


}

void Smart_Factory_2A1::on_pushButton_modifier_clicked()
{

    if (ui->pushButton_modifier->isChecked())
    {

        ui->pushButton_modifier->setText("Modifiable");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("MATERIEL");
        tableModel->select();
        ui->tableView_materiel->setModel(tableModel);
        /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

    }
    else
    {
        ui->pushButton_modifier->setText("Modifier equipement");
        ui->tableView_materiel->setModel(etmp.afficher());
        /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

    }

}

void Smart_Factory_2A1::on_pushButton_recherche_clicked()
{
    if (ui->checkBox_search_ref->isChecked())
    {
        QString reference = ui->lineEdit_recherche->text();
        QSqlQueryModel * test=etmp.recherche_materiel(reference);
        if (ui->pushButton_recherche->isChecked()){
            ui->pushButton_recherche->setText("En cours");
            /* click = new QMediaPlayer();
                 click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                  click->play();*/
            if(test != nullptr)
            {
                QMessageBox::information(nullptr, QObject::tr("chercher un materiel"),
                                         QObject::tr("materiel trouvé.\n"
                                    "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView_materiel->setModel(test);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher un materiel"),
                                      QObject::tr("Erreur , materiel introuvable !.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
                ui->tableView_materiel->setModel(test);

            }}
        else
        {
            ui->pushButton_recherche->setText("Recherche");
            ui->tableView_materiel->setModel(etmp.afficher());
            /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

        }
    }
    if (ui->checkBox_search_modele->isChecked())
    {
        QString modele = ui->lineEdit_recherche->text();
        QSqlQueryModel * test=etmp.recherche_materiel_modele(modele);
        if (ui->pushButton_recherche->isChecked()){
            ui->pushButton_recherche->setText("En cours");
            /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

            if(test != nullptr)
            {
                QMessageBox::information(nullptr, QObject::tr("chercher un materiel"),
                                         QObject::tr("materiel trouvé.\n"
                                        "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView_materiel->setModel(test);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher un materiel"),
                                      QObject::tr("Erreur , materiel introuvable !.\n"
                                        "Click cancel to exit."), QMessageBox::Cancel);
                ui->tableView_materiel->setModel(test);

            }}
        else
        {
            ui->pushButton_recherche->setText("Recherche");
            ui->tableView_materiel->setModel(etmp.afficher());
            /* click = new QMediaPlayer();
                         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                          click->play();*/

        }
    }
    if (ui->checkBox_search_nbr_maintenance->isChecked())
    {
        int nombre_maintenance = ui->lineEdit_recherche->text().toInt();
        QSqlQueryModel * test=etmp.recherche_materiel_nbr_maintenance(nombre_maintenance);
        if (ui->pushButton_recherche->isChecked()){
            ui->pushButton_recherche->setText("En cours");
            /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/
            if(test != nullptr)
            {
                QMessageBox::information(nullptr, QObject::tr("chercher un materiel"),
                                         QObject::tr("materiel trouvé.\n"
                                        "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView_materiel->setModel(test);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher un materiel"),
                                      QObject::tr("Erreur , materiel introuvable !.\n"
                                        "Click cancel to exit."), QMessageBox::Cancel);
                ui->tableView_materiel->setModel(test);
            }}
        else
        {
            ui->pushButton_recherche->setText("Recherche");
            ui->tableView_materiel->setModel(etmp.afficher());
            /* click = new QMediaPlayer();
                         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                          click->play();*/

        }
    }
}

void Smart_Factory_2A1::on_pushButton_trier_clicked()
{
    if (ui->radioButton_tri_ref->isChecked())
    {
        ui->tableView_materiel->setModel( etmp.trier_materiel());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }
    if (ui->radioButton_tri_modele->isChecked())
    {
        ui->tableView_materiel->setModel( etmp.trier_materielmodele());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }
    if (ui->radioButton_tri_date->isChecked())
    {
        ui->tableView_materiel->setModel( etmp.trier_materiel_dateachat());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }
    if (ui->radioButton_tri_nbrmaint->isChecked())
    {
        ui->tableView_materiel->setModel( etmp.trier_materiel_nbr_maintenance());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }

}






//gestion de maintenance





void Smart_Factory_2A1::on_pushButton_validermaint_clicked()
{
    QString ID_maintenance = ui->lineEdit_ID->text();
    QString referene = ui->lineEdit_ref->text();
    QString modele = ui->lineEdit_modele->text();
    QString matricule = ui->lineEdit_matriculemaint->text();
    QDate date_achat = ui->dateEdit_achat->date();
    QDate date_de_maintenance = ui->dateEdit_maint->date();
    QString dernier_probleme = ui->lineEdit_problememaint->text();
    QString type_de_maintenance = ui->radioButton_corr->text();
    maintenance ma(ID_maintenance,referene,modele,matricule,date_achat,date_de_maintenance,dernier_probleme,type_de_maintenance);
    bool test=ma.ajouter();
    /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    if (test)
    {
        ui->tableView_maint->setModel(mtmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajouter une maintenance"),
                                 QObject::tr("maintenance ajouté.\n"
                                   "click ok to continue."), QMessageBox::Ok);
    }
    else QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                               QObject::tr("ajout non effectué.\n"
                                   "click cancel to exit."),QMessageBox::Cancel);
}


void Smart_Factory_2A1::on_pushButton_supprimermaint_clicked()
{
    QItemSelectionModel *select = ui->tableView_maint->selectionModel();
    QString ID_maintenance =select->selectedRows(0).value(0).data().toString();
    bool test=mtmp.supprimer(ID_maintenance);
    /* click = new QMediaPlayer();
             click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
              click->play();*/
    if (test)
    {
        ui->tableView_maint->setModel(mtmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("suppression effectuée\n"
                                                 "click ok to continue."),QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectuée.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);

}

void Smart_Factory_2A1::on_pushButton_modifiermaint_clicked()
{
    if (ui->pushButton_modifiermaint->isChecked())
    {

        ui->pushButton_modifiermaint->setText("Modifiable");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("MAINTENANCE");
        tableModel->select();
        ui->tableView_maint->setModel(tableModel);
        /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

    }
    else
    {
        ui->pushButton_modifiermaint->setText("Modifier une maintenance");
        ui->tableView_maint->setModel(mtmp.afficher());
        /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

    }
}

void Smart_Factory_2A1::on_pushButton_recherche_2_clicked()
{
    if (ui->checkBox_search_IDmaint->isChecked())
    {
        QString ID_maintenance = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance(ID_maintenance);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            /* click = new QMediaPlayer();
                 click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                  click->play();*/

            if(test != nullptr)
            {
                QMessageBox::information(nullptr, QObject::tr("chercher une maintenance"),
                                         QObject::tr("maintenance trouvé.\n"
                                    "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView_maint->setModel(test);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher une maintenance"),
                                      QObject::tr("Erreur , maintenance introuvable !.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
                ui->tableView_maint->setModel(test);
            }}
        else
        {
            ui->pushButton_recherche_2->setText("Recherche");
            ui->tableView_maint->setModel(mtmp.afficher());
            /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

        }
    }
    if (ui->checkBox_search_refmaint->isChecked())
    {
        QString reference = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance_reference(reference);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            /* click = new QMediaPlayer();
                 click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                  click->play();*/

            if(test != nullptr)
            {
                QMessageBox::information(nullptr, QObject::tr("chercher une maintenance"),
                                         QObject::tr("maintenance trouvé.\n"
                                    "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView_maint->setModel(test);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher une maintenance"),
                                      QObject::tr("Erreur , maintenance introuvable !.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
                ui->tableView_maint->setModel(test);
            }}
        else
        {
            ui->pushButton_recherche_2->setText("Recherche");
            ui->tableView_maint->setModel(mtmp.afficher());
            /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

        }
    }
    if (ui->checkBox_search_modelemaint->isChecked())
    {
        QString modele = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance_modele(modele);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            /* click = new QMediaPlayer();
                 click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                  click->play();*/

            if(test != nullptr)
            {
                QMessageBox::information(nullptr, QObject::tr("chercher une maintenance"),
                                         QObject::tr("maintenance trouvé.\n"
                                    "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView_maint->setModel(test);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher une maintenance"),
                                      QObject::tr("Erreur , maintenance introuvable !.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
                ui->tableView_maint->setModel(test);
            }}
        else
        {
            ui->pushButton_recherche_2->setText("Recherche");
            ui->tableView_maint->setModel(mtmp.afficher());
            /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

        }
    }
    if (ui->checkBox_search_matriculemaint->isChecked())
    {
        QString matricule = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance_matricule(matricule);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            /* click = new QMediaPlayer();
                 click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                  click->play();*/

            if(test != nullptr)
            {
                QMessageBox::information(nullptr, QObject::tr("chercher une maintenance"),
                                         QObject::tr("maintenance trouvé.\n"
                                    "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView_maint->setModel(test);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher une maintenance"),
                                      QObject::tr("Erreur , maintenance introuvable !.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
                ui->tableView_maint->setModel(test);
            }}
        else
        {
            ui->pushButton_recherche_2->setText("Recherche");
            ui->tableView_maint->setModel(mtmp.afficher());
            /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

        }
    }
    if (ui->checkBox_search_typemaint->isChecked())
    {
        QString type_de_maintenance = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance_type(type_de_maintenance);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            /* click = new QMediaPlayer();
                 click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                  click->play();*/

            if(test != nullptr)
            {
                QMessageBox::information(nullptr, QObject::tr("chercher une maintenance"),
                                         QObject::tr("maintenance trouvé.\n"
                                    "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView_maint->setModel(test);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("chercher une maintenance"),
                                      QObject::tr("Erreur , maintenance introuvable !.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
                ui->tableView_maint->setModel(test);
            }}
        else
        {
            ui->pushButton_recherche_2->setText("Recherche");
            ui->tableView_maint->setModel(mtmp.afficher());
            /* click = new QMediaPlayer();
                     click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                      click->play();*/

        }
    }

}


void Smart_Factory_2A1::on_pushButton_trier_2_clicked()
{
    if (ui->radioButton_tri_IDmaint->isChecked())
    {
        ui->tableView_maint->setModel( mtmp.trier_maintenance_ID());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }
    if (ui->radioButton_triref2->isChecked())
    {
        ui->tableView_maint->setModel( mtmp.trier_maintenance_reference());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }
    if (ui->radioButton_trimod2->isChecked())
    {
        ui->tableView_maint->setModel( mtmp.trier_maintenance_modele());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }
    if (ui->radioButton_trimatricule->isChecked())
    {
        ui->tableView_maint->setModel( mtmp.trier_maintenance_matricule());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }
    if (ui->radioButton_tridate2->isChecked())
    {
        ui->tableView_maint->setModel( mtmp.trier_maintenance_dateachat());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }
    if (ui->radioButton_tridatemaint->isChecked())
    {
        ui->tableView_maint->setModel( mtmp.trier_maintenance_date_derniere_maintenance());
        /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    }

}

void Smart_Factory_2A1::on_pushButton_email_clicked()
{
    QItemSelectionModel *select = ui->tablePers->selectionModel();
    QString email =select->selectedRows(4).value(0).data().toString();

    QDialog *d=new Dialog(email,"","",this);
    d->show();
    d->exec();
}

void Smart_Factory_2A1::on_pushButton_stat_clicked()
{
    statis *obj =new statis;
    obj->show();
}

void Smart_Factory_2A1::on_pushButton_arduinoobstacle_clicked()
{
    /* click = new QMediaPlayer();
         click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
          click->play();*/
    arduinoobstacle *obj =new arduinoobstacle;
    obj->show();


}

void Smart_Factory_2A1::on_pushButtonExporterEquip_clicked()
{
    /* click = new QMediaPlayer();
             click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
              click->play();*/
    exporter(ui->tableView_materiel);
    ui->statusbar->showMessage("Export De Tableau Materiel ",5000);
}

void Smart_Factory_2A1::on_pushButtonExporterMain_clicked()
{
    /* click = new QMediaPlayer();
            click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
             click->play();*/
    exporter(ui->tableView_maint);
    ui->statusbar->showMessage("Export De Tableau maintenance ",5000);
}

void Smart_Factory_2A1::on_pushButtonExporterEquip_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM MATERIEL ");
    q.exec();
    QString pdf="<br><h1  style='color:pink'>tableau materiel  <br></h1>\n <br> <table>  <tr>  <th>REFERENCE </th> <th>MODELE </th> <th>DATE_ACHAT </th>  <th>NOMBRE_MAINTENANCE </th> </tr> " ;


    while ( q.next()) {
        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td> " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" </td>   <td>"+q.value(3).toString()+"</td> </td>";

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);

}

void Smart_Factory_2A1::on_pushButtonExporterMain_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM MAINTENANCE ");
    q.exec();
    QString pdf="<br><h1  style='color:pink'>tableau maintenance  <br></h1>\n <br> <table>  <tr>  <th>ID_MAINTENANCE </th> <th>REFERENCE </th>  <th>MODELE </th> <th>MATRICULE </th>  <th>DATE_ACHAT </th> <th>DATE_DE_MAINTENANCE </th> <th>DERNIER_PROBLEME </th> <th>TYPE_DE_MAINTENANCE </th> </tr> " ;


    while ( q.next()) {
        pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>   <td> " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" </td>   <td>"+q.value(3).toString()+"</td> <td>"+q.value(4).toString()+"</td> <td>"+q.value(5).toString()+" </td> <td> "+q.value(6).toString()+" </td> <td>"+ q.value(7).toString()+"</td> </td>" ;

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

void Smart_Factory_2A1::on_pushButtonOptions_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void Smart_Factory_2A1::on_pushButtonModifieProfil_clicked()
{
    modifierProfil modifierProfil;
    modifierProfil.setModal(true);
    modifierProfil.exec();

}

void Smart_Factory_2A1::on_radioButtonNuit_toggled(bool checked)
{
    this->setStyleSheet("font: 8pt \"Pacifico\";"
                           "background-color: rgb(43, 40, 38);"
                           "color: rgb(255, 255, 255);");



    QList<QPushButton *> butts = this->findChildren<QPushButton *>();

    for (int i=0; i<butts.size();i++)
    {
        butts.at(i)->setStyleSheet("QPushButton { background-color: #444444; }");
    }


    QList<QTabWidget *> tabs = this->findChildren<QTabWidget *>();

    for (int i=0; i<tabs.size();i++)
    {
        tabs.at(i)->setStyleSheet("QTabBar::tab { background-color: rgb(68, 68, 68);}");
    }

}

void Smart_Factory_2A1::on_radioButtonJour_toggled(bool checked)
{
    this->setStyleSheet("font: 8pt \"Pacifico\";");


    QList<QPushButton *> butts = this->findChildren<QPushButton *>();

    for (int i=0; i<butts.size();i++)
    {
        butts.at(i)->setStyleSheet("QPushButton { background-color: grey; }");
    }
    QList<QTabWidget *> tabs = this->findChildren<QTabWidget *>();

    for (int i=0; i<tabs.size();i++)
    {
        tabs.at(i)->setStyleSheet("QTabBar::tab { background-color: grey;}");
    }

}

void Smart_Factory_2A1::on_pushButton_2_clicked()
{
    if(ui->radioButtonEN->isChecked())
    {
        translator->load(QDir::currentPath().append("/smart_factory_2a1_en"));
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    }
    else if(ui->radioButtonFR->isChecked())
    {
        translator->load(QDir::currentPath().append("/smart_factory_2a1_fr"));
        qApp->installTranslator(translator);
        ui->retranslateUi(this);
    }

    ui->stackedWidget->setCurrentIndex(1);
}

void Smart_Factory_2A1::update_label()
{
    qDebug() <<"a=" << data;
    data =A.read_from_arduino();

    if (data!="#")
    {

        uid+=data;

        //qDebug() << uid;

    }
    else {
        int pos = uid.lastIndexOf(QChar('/'));
        qDebug() << "uid="<< uid.left(pos);
        //qDebug()  << uid;

        ui->tablePointagePers->setModel(tmpPersonnels.rechercher_rfid(uid));
        uid="";
        //qDebug() << uid;

    }
}

void Smart_Factory_2A1::on_pushButtonAccepter_clicked()
{
    QItemSelectionModel *select=ui->tablePointagePers->selectionModel();
    QString nom= select->selectedRows(2).value(0).data().toString();
    QString prenom= select->selectedRows(3).value(0).data().toString();
    QString msg="";
    msg= tr("Bonjour,")+nom+" "+prenom;

    const char * p= msg.toStdString().c_str();

    A.write_to_arduino(p);
}

void Smart_Factory_2A1::on_avertir_clicked()
{
    QItemSelectionModel *select=ui->tablePointagePers->selectionModel();
    QString nbAver= select->selectedRows(19).value(0).data().toString();
    QString msg="";
    msg= tr("Vous etes en retard,")+tr("ceci est votre ")+nbAver+tr("avertissement");

    const char * p= msg.toStdString().c_str();

    A.write_to_arduino(p);
}

void Smart_Factory_2A1::on_convoquer_clicked()
{
    QItemSelectionModel *select=ui->tablePointagePers->selectionModel();
    QString nom= select->selectedRows(2).value(0).data().toString();
    QString prenom= select->selectedRows(3).value(0).data().toString();
    QString msg="";
    msg= tr("Bonjour,")+nom+" "+prenom+tr("veuillez vous diriger vers la direction des ressources humaines");

    const char * p= msg.toStdString().c_str();

    A.write_to_arduino(p);
}

void Smart_Factory_2A1::on_envoyerMail_clicked()
{
    QItemSelectionModel *select = ui->tablePers->selectionModel();
    QString email =select->selectedRows(4).value(0).data().toString();
    QDialog *d=new Dialog(email,"","",this);
    d->show();
    d->exec();
}
