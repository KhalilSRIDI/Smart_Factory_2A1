#include "mainwindow.h"
#include "statistiques.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //projets TableView
    ui->tableViewP->setModel(tmp_projet.afficher());
    ui->tableViewP->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewP->setSelectionMode(QAbstractItemView::SingleSelection);

    //formations TableView
    ui->tableViewF->setModel(tmp_formation.afficher());
    ui->tableViewF->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewF->setSelectionMode(QAbstractItemView::SingleSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//projets UI
void MainWindow::on_pushButtonAjouter_clicked()
{
    QString NOM=ui->lineEditNomP->text();
    QString DEPARTEMENT=ui->comboBoxDepartementP->currentText();
    QString TEAM_LEADER=ui->lineEditTeamLeaderP->text();
    QString DATE_LANCEMENT=ui->dateEditLancementP->date().toString("dd/MM/yyyy");
    QString COUTS_PREVUS=ui->lineEditCoutP->text();
    QString REVENUS_PROJETES=ui->lineEditRevenuesP->text();

    projets projet(NOM, DEPARTEMENT, TEAM_LEADER, DATE_LANCEMENT, COUTS_PREVUS, REVENUS_PROJETES);
    projet.ajouter();
    ui->tableViewP->setModel(tmp_projet.afficher());
}

void MainWindow::on_pushButtonSupprimer_clicked()
{
    QItemSelectionModel *select = ui->tableViewP->selectionModel();
    int idprojet =select->selectedRows(0).value(0).data().toInt();
    if(tmp_projet.supprimer(idprojet))
    {
        ui->tableViewP->setModel(tmp_projet.afficher());
        ui->statusbar->showMessage("SUPPRESSION : SUCCESS");
    }

}

void MainWindow::on_pushButtonModifier_clicked()
{

    if(ui->pushButtonModifier->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("PROJETS");
        tableModel->select();
        ui->tableViewP->setModel(tableModel);
        ui->pushButtonModifier->setText("Tableau Modifiable");
    }

}


void MainWindow::on_pushButtonRechercheP_clicked()
{
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

void MainWindow::on_pushButtonRefreshP_clicked()
{
    ui->tableViewP->setModel(tmp_projet.afficher());
}

void MainWindow::on_pushButtonExportP_clicked()
{
    tmp_projet.exporterExcel(ui->tableViewP);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);
}


void MainWindow::on_pushTrierP_clicked()
{
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

void MainWindow::on_pushButtonStat_clicked()
{
    statistiques *a= new statistiques() ;

    a->show();
}

//formations UI
void MainWindow::on_pushButtonAjouterF_clicked()
{
    QString NOM=ui->lineEditNomF->text();
    int PROJET=ui->lineEditProjet->text().toInt();
    QString FORMATEUR=ui->lineEditFormateur->text();
    QString DATEDEBUT=ui->dateEditDateF->date().toString("dd/MM/yyyy");
    QString DUREE=ui->lineEditDureeF->text();
    QString COUT=ui->lineEditCoutF->text();

    formation formation(NOM, PROJET, FORMATEUR, DATEDEBUT, DUREE, COUT);
    formation.ajouter();
    ui->tableViewF->setModel(tmp_formation.afficher());

}

void MainWindow::on_pushButtonSupprimerF_clicked()
{
    QItemSelectionModel *select = ui->tableViewF->selectionModel();
    int idformation =select->selectedRows(0).value(0).data().toInt();
    if(tmp_formation.supprimer(idformation))
    {
        ui->tableViewF->setModel(tmp_formation.afficher());
        ui->statusbar->showMessage("SUPPRESSION : SUCCESS");
    }
}

void MainWindow::on_pushButtonModifierF_clicked()
{
    if(ui->pushButtonModifierF->isChecked())
    {
        QSqlTableModel *tableModelF= new QSqlTableModel();
        tableModelF->setTable("FORMATIONS");
        tableModelF->select();
        ui->tableViewF->setModel(tableModelF);
        ui->pushButtonModifierF->setText("Tableau Modifiable");
    }

}

void MainWindow::on_pushButtonRechercheF_clicked()
{
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


void MainWindow::on_pushButtonRefreshF_clicked()
{
    ui->tableViewF->setModel(tmp_formation.afficher());
}

void MainWindow::on_pushButtonExportF_clicked()
{
    tmp_formation.exporterExcel(ui->tableViewF);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);
}


void MainWindow::on_pushTrierF_clicked()
{
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
        QMessageBox::critical(nullptr, QObject::tr("Aucun critere"),
                              QObject::tr("Veuillez choisir un critere.\n"), QMessageBox::Cancel);

    }

    QString order = ui->comboBoxF->currentText();
    ui->tableViewF->setModel(tmp_formation.trier(critere,order));

}
