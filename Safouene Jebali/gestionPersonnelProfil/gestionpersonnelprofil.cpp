#include "gestionpersonnelprofil.h"
#include "ui_gestionpersonnelprofil.h"
#include "personnels.h"

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
    ui->salaire->setRange(500,10000);
    ui->dateNaissance->setDate(QDate::currentDate());
    ui->dateRecrutement->setDate(QDate::currentDate());
    email_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");


    // Pie Chart
    /*
    QPieSeries *series = new QPieSeries();

        series->append("C++", 80);
        series->append("Python", 70);
        series->append("Java", 50);
        series->append("C#", 40);
        series->append("PHP", 30);


        QPieSlice *slice = series->slices().at(1);
        slice->setExploded(true);
        slice->setLabelVisible(true);
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Qt5 Pie Chart Example");


        QChartView *chartview = new QChartView(chart);
        chartview->setParent(ui->testPie);
        */
    //Bar
    /*
    QBarSet *set0 = new QBarSet("Bob");
       QBarSet *set1 = new QBarSet("Tom");
       QBarSet *set2 = new QBarSet("John");
       QBarSet *set3 = new QBarSet("Doe");
       QBarSet *set4 = new QBarSet("Ahmad");

       *set0 << 30 << 40 << 10 << 20 << 10 << 60;
       *set1 << 10 << 30 << 42 << 15 << 81 << 75;
       *set2 << 80 << 100 << 70 << 13 << 60 << 20;
       *set3 << 30 << 10 << 80 << 70 << 60 << 45;
       *set4 << 100 << 40 << 70 << 30 << 16 << 42;

       QBarSeries *series = new QBarSeries();
       series->append(set0);
       series->append(set1);
       series->append(set2);
       series->append(set3);
       series->append(set4);

       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("BarChart Example In Qt5 C++ ");
       chart->setAnimationOptions(QChart::SeriesAnimations);


       QStringList categories;
       categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
       QBarCategoryAxis *axis = new QBarCategoryAxis();
       axis->append(categories);
       chart->createDefaultAxes();
       chart->setAxisX(axis, series);


       QChartView *chartView = new QChartView(chart);
       chartView->setParent(ui->testPie);
       */
    //Line
    /*
    QLineSeries *series = new QLineSeries();

       series->append(0, 6);
       series->append(2, 4);
       series->append(3, 8);
       series->append(7, 4);
       series->append(10, 5);


       *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3)
               << QPointF(20, 2);

       QChart *chart = new QChart();
       //chart->legend()->hide();
       chart->addSeries(series);
       chart->createDefaultAxes();
       chart->setTitle("Line Chart Example");


       chart->legend()->setVisible(true);
       chart->legend()->setAlignment(Qt::AlignBottom);



       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->setParent(ui->testPie);
       */

}
GestionPersonnelProfil::~GestionPersonnelProfil()
{
    delete ui;
}
void GestionPersonnelProfil::on_gestionPersonnel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionPersonnelProfil::on_gestionProfil_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void GestionPersonnelProfil::on_vAjouterPers_clicked()
{
    bool email_verif = email_regex.exactMatch(ui->email->text());
    if (!email_verif)
    {
        QMessageBox::critical(this,"Erreur lors de l'ajout","E-mail invalid");
    }
    else
    {
        int cin = ui->cin->text().toInt();
        QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
        int numTel = ui->numTel->text().toInt();
        QString email = ui->email->text();
        /*
    QRegularExpression regex("^[0-9a-zA-Z]+([0-9a-zA-Z][-._+])[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)([0-9a-zA-Z][.])[a-zA-Z]{2,6}$");
    if(!regex.match(email).hasMatch())
    {
        QMessageBox::critical(this, "Message Erreur", "E-mail Invalide ! Veuillez Respecter La Forme : chaine @ chaine . chaine ");
    }
    */
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
    }
}
void GestionPersonnelProfil::on_modifierPers_clicked()
{
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
    exporter(ui->tablePers);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);
}

void GestionPersonnelProfil::on_vAjouterPro_clicked()
{
    int matricule = ui->matriculeP->text().toInt();
    QString nomUP = ui->nomUP->text();
    QString nom = ui->nomP->text();
    QString prenom = ui->prenomP->text();
    int numTel = ui->numTel->text().toInt();
    QString email = ui->emailP->text();
    QString mdp = ui->motDePasseP->text();
    QString sexe ;
    if(ui->masculinP->isChecked())
        sexe =ui->masculinP->text();
    if(ui->femininP->isChecked())
        sexe = ui->femininP->text();
    QDate dateNaissance = ui->dateNaissanceP->date();
    QString departement = ui->departementP->currentText();
    QString unite = ui->uniteP->currentText();
    profils p(matricule,nomUP,nom,prenom,numTel,email,mdp,sexe,dateNaissance,departement,unite);
    if(p.ajouter())
    {
        ui->statusbar->showMessage("DATA INSERTED ",5000);
        ui->tablePro->setModel(tmpProfils.afficher());
    }
}

void GestionPersonnelProfil::on_modifierPro_clicked()
{
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
    if(ui->matT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trierMatricule());
    }
    else if(ui->nomT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trierNom());
    }
    else if(ui->ageT->isChecked())
    {
       ui->tablePers->setModel(tmpPersonnels.trierAge());
    }
    else if(ui->ancienneteT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trierAnciennete());
    }
    else if(ui->salaireT->isChecked())
    {
        ui->tablePers->setModel(tmpPersonnels.trierSalaire());
    }
}
