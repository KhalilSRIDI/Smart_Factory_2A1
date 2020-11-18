#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"projets.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    QString DATE_LANCEMENT=ui->dateEditLancement->text();
    QString COUTS_PREVUS=ui->lineEditCout->text();
    QString REVENUES_PROJETES=ui->lineEditRevenues->text();

    projets projet(NOM,DEPARTEMENT,TEAM_LEADER,DATE_LANCEMENT,COUTS_PREVUS,REVENUES_PROJETES);

    bool test=projet.ajouter();
    if(test)
    {
        ui->tableViewDB->setModel(tmp_projet.afficher());
    }

}
