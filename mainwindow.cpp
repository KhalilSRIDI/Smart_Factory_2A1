#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_materiel->setModel(etmp.afficher());
    ui->tableView_materiel->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_materiel->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_maint->setModel(mtmp.afficher());
    ui->tableView_maint->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_maint->setSelectionMode(QAbstractItemView::SingleSelection);
}

//gestion de materiel

void MainWindow::on_pushButton_valider_clicked()
{
  QString referene = ui->lineEdit_ref->text();
  QString modele = ui->lineEdit_modele->text();
  QDate date_achat = ui->dateEdit_achat->date();
  int nombre_maintenance = ui->lineEdit_nombre_maintenance->text().toInt();
  materiel m(referene,modele,date_achat,nombre_maintenance);
  bool test=m.ajouter();
  click = new QMediaPlayer();
      click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
       click->play();
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

void MainWindow::on_pushButton_supprimer_clicked()
{
    QItemSelectionModel *select = ui->tableView_materiel->selectionModel();
        QString reference =select->selectedRows(0).value(0).data().toString();
    bool test=etmp.supprimer(reference);
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
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

void MainWindow::on_pushButton_modifier_clicked()
{

    if (ui->pushButton_modifier->isChecked())
            {

                ui->pushButton_modifier->setText("Modifiable");
                QSqlTableModel *tableModel= new QSqlTableModel();
                tableModel->setTable("MATERIEL");
                tableModel->select();
                ui->tableView_materiel->setModel(tableModel);
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
            else
            {
                ui->pushButton_modifier->setText("Modifier equipement");
                ui->tableView_materiel->setModel(etmp.afficher());
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }

}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_recherche_clicked()
{
    if (ui->checkBox_search_ref->isChecked())
    {
    QString reference = ui->lineEdit_recherche->text();
        QSqlQueryModel * test=etmp.recherche_materiel(reference);
        if (ui->pushButton_recherche->isChecked()){
            ui->pushButton_recherche->setText("En cours");
            click = new QMediaPlayer();
                click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                 click->play();
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
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
     }
    if (ui->checkBox_search_modele->isChecked())
    {
        QString modele = ui->lineEdit_recherche->text();
            QSqlQueryModel * test=etmp.recherche_materiel_modele(modele);
            if (ui->pushButton_recherche->isChecked()){
                ui->pushButton_recherche->setText("En cours");
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

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
                    click = new QMediaPlayer();
                        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                         click->play();

                }
    }
    if (ui->checkBox_search_nbr_maintenance->isChecked())
    {
        int nombre_maintenance = ui->lineEdit_recherche->text().toInt();
            QSqlQueryModel * test=etmp.recherche_materiel_nbr_maintenance(nombre_maintenance);
            if (ui->pushButton_recherche->isChecked()){
                ui->pushButton_recherche->setText("En cours");
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

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
                    click = new QMediaPlayer();
                        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                         click->play();

                }
    }
}

void MainWindow::on_pushButton_trier_clicked()
{
    if (ui->radioButton_tri_ref->isChecked())
    {
    ui->tableView_materiel->setModel( etmp.trier_materiel());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }
    if (ui->radioButton_tri_modele->isChecked())
    {
    ui->tableView_materiel->setModel( etmp.trier_materielmodele());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }
    if (ui->radioButton_tri_date->isChecked())
    {
    ui->tableView_materiel->setModel( etmp.trier_materiel_dateachat());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }
    if (ui->radioButton_tri_nbrmaint->isChecked())
    {
    ui->tableView_materiel->setModel( etmp.trier_materiel_nbr_maintenance());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }

}






//gestion de maintenance





void MainWindow::on_pushButton_validermaint_clicked()
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
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
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


void MainWindow::on_pushButton_supprimermaint_clicked()
{
        QItemSelectionModel *select = ui->tableView_maint->selectionModel();
            QString ID_maintenance =select->selectedRows(0).value(0).data().toString();
        bool test=mtmp.supprimer(ID_maintenance);
        click = new QMediaPlayer();
            click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
             click->play();
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

void MainWindow::on_pushButton_modifiermaint_clicked()
{
    if (ui->pushButton_modifiermaint->isChecked())
            {

                ui->pushButton_modifiermaint->setText("Modifiable");
                QSqlTableModel *tableModel= new QSqlTableModel();
                tableModel->setTable("MAINTENANCE");
                tableModel->select();
                ui->tableView_maint->setModel(tableModel);
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
            else
            {
                ui->pushButton_modifiermaint->setText("Modifier une maintenance");
                ui->tableView_maint->setModel(mtmp.afficher());
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
}

void MainWindow::on_pushButton_recherche_2_clicked()
{
    if (ui->checkBox_search_IDmaint->isChecked())
    {
    QString ID_maintenance = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance(ID_maintenance);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            click = new QMediaPlayer();
                click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                 click->play();

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
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
    }
    if (ui->checkBox_search_refmaint->isChecked())
    {
    QString reference = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance_reference(reference);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            click = new QMediaPlayer();
                click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                 click->play();

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
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
    }
    if (ui->checkBox_search_modelemaint->isChecked())
    {
    QString modele = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance_modele(modele);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            click = new QMediaPlayer();
                click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                 click->play();

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
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
    }
    if (ui->checkBox_search_matriculemaint->isChecked())
    {
    QString matricule = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance_matricule(matricule);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            click = new QMediaPlayer();
                click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                 click->play();

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
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
    }
    if (ui->checkBox_search_typemaint->isChecked())
    {
    QString type_de_maintenance = ui->lineEdit_recherchemaint->text();
        QSqlQueryModel * test=mtmp.recherche_maintenance_type(type_de_maintenance);
        if (ui->pushButton_recherche_2->isChecked()){
            ui->pushButton_recherche_2->setText("En cours");
            click = new QMediaPlayer();
                click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                 click->play();

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
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
    }

}


void MainWindow::on_pushButton_trier_2_clicked()
{
    if (ui->radioButton_tri_IDmaint->isChecked())
    {
    ui->tableView_maint->setModel( mtmp.trier_maintenance_ID());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }
    if (ui->radioButton_triref2->isChecked())
    {
    ui->tableView_maint->setModel( mtmp.trier_maintenance_reference());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }
    if (ui->radioButton_trimod2->isChecked())
    {
    ui->tableView_maint->setModel( mtmp.trier_maintenance_modele());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }
    if (ui->radioButton_trimatricule->isChecked())
    {
    ui->tableView_maint->setModel( mtmp.trier_maintenance_matricule());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }
    if (ui->radioButton_tridate2->isChecked())
    {
    ui->tableView_maint->setModel( mtmp.trier_maintenance_dateachat());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }
    if (ui->radioButton_tridatemaint->isChecked())
    {
    ui->tableView_maint->setModel( mtmp.trier_maintenance_date_derniere_maintenance());
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    }

}

void MainWindow::on_pushButton_email_clicked()
{
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    email *obj =new email;
    obj->show();
}

void MainWindow::on_pushButton_stat_clicked()
{
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
    statis *obj =new statis;
    obj->show();
}

void MainWindow::on_pushButton_quitter_clicked()
{
    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
         click->play();
         arduinoobstacle *obj =new arduinoobstacle;
         obj->show();


}
