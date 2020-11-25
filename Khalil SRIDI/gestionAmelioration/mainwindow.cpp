#include "mainwindow.h"

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
    QString DEPARTEMENT=ui->lineEditDepartementP->text();
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
    if(ui->radioButtonIDF->isChecked())
        critere=0;
    else if(ui->radioButtonNomF->isChecked())
        critere=1;
    else if(ui->radioButtonProjetF->isChecked())
        critere=2;
    else if(ui->radioButtonFormateurF->isChecked())
        critere=3;
    else if(ui->radioButtonDateF->isChecked())
        critere=4;
    else if(ui->radioButtonDureeF->isChecked())
        critere=5;
    else if(ui->radioButtonCoutF->isChecked())
        critere=6;

    QString input = ui->lineEditRF->text();

    QSqlQueryModel *test=tmp_formation.chercher(input,critere);


    if(test != nullptr)
    {
        QMessageBox::information(nullptr, QObject::tr("chercher une formation"),
                                 QObject::tr("Formation trouvé.\n"
                                             "Click Cancel to get informations."), QMessageBox::Cancel);
        ui->tableViewF->setModel(test);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher une formation"),
                              QObject::tr("Erreur , formation introuvable !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableViewF->setModel(test);
    }
}

void MainWindow::on_pushButtonRechercheP_clicked()
{
    int critere=0;
    if(ui->radioButtonIDP->isChecked())
        critere=0;
    else if(ui->radioButtonNomP->isChecked())
        critere=1;
    else if(ui->radioButtonDepartementP->isChecked())
        critere=2;
    else if(ui->radioButtonTeamLeaderP->isChecked())
        critere=3;
    else if(ui->radioButtonDateLancementP->isChecked())
        critere=4;
    else if(ui->radioButtonCoutsP->isChecked())
        critere=5;
    else if(ui->radioButtonRevenusP->isChecked())
        critere=6;

    QString input = ui->lineEditRP->text();

    QSqlQueryModel *test=tmp_projet.chercher(input,critere);


    if(test != nullptr)
    {
        QMessageBox::information(nullptr, QObject::tr("chercher un projet"),
                                 QObject::tr("Projet trouvé.\n"
                                             "Click Cancel to get informations."), QMessageBox::Cancel);
        ui->tableViewP->setModel(test);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("chercher une projet"),
                              QObject::tr("Erreur , projet introuvable !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableViewP->setModel(test);
    }
}

void MainWindow::on_pushButtonRefreshP_clicked()
{
    ui->tableViewP->setModel(tmp_projet.afficher());
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

void MainWindow::on_pushButtonExportP_clicked()
{
    tmp_projet.exporterExcel(ui->tableViewP);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);
}
