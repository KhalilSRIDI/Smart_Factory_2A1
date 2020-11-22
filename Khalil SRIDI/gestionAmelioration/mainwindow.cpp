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
