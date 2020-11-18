#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projets.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableViewDB->setModel(tmp_projet.afficher());
    ui->tableViewDB->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewDB->setSelectionMode(QAbstractItemView::SingleSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAjouter_clicked()
{
    QString NOM=ui->lineEditNom->text();
    QString DEPARTEMENT=ui->lineEditDepartement->text();
    QString TEAM_LEADER=ui->lineEditTeamLeader->text();
    QString DATE_LANCEMENT=ui->dateEditLancement->date().toString("dd/MM/yyyy");
    QString COUTS_PREVUS=ui->lineEditCout->text();
    QString REVENUS_PROJETES=ui->lineEditRevenues->text();

    projets projet(NOM, DEPARTEMENT, TEAM_LEADER, DATE_LANCEMENT, COUTS_PREVUS, REVENUS_PROJETES);
    projet.ajouter();
    ui->tableViewDB->setModel(tmp_projet.afficher());
}

void MainWindow::on_pushButtonSupprimer_clicked()
{
    QItemSelectionModel *select = ui->tableViewDB->selectionModel();
    int idprojet =select->selectedRows(0).value(0).data().toInt();
    if(tmp_projet.supprimer(idprojet))
    {
        ui->tableViewDB->setModel(tmp_projet.afficher());
        ui->statusbar->showMessage("SUPPRESSION : SUCCESS");
    }

}
