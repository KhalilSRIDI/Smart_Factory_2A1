#ifndef SMART_FACTORY_2A1_H
#define SMART_FACTORY_2A1_H
#include "connexionsql.h"
#include "smtp.h"
#include "login.h"
#include "personnels.h"
#include "profils.h"
#include "statistiques.h"
#include "afficherunpersonnel.h"
#include "projets.h"
#include "formation.h"
#include "dialog.h"
#include <QMainWindow>
#include <QStatusBar>
#include<QSound>
#include <QFileDialog>
#include <QTableView>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QStatusBar>
#include <QTextStream>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QRegularExpression>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class Smart_Factory_2A1; }
QT_END_NAMESPACE

class Smart_Factory_2A1 : public QMainWindow
{
    Q_OBJECT

public:
    Smart_Factory_2A1(QWidget *parent = nullptr);
    ~Smart_Factory_2A1();

private slots:
    void on_login_clicked();

    void on_gestionPersonnelProfil_clicked();
    void on_gestionPersonnel_clicked();
    void on_gestionProfil_clicked();

    void on_vAjouterPers_clicked();
    void on_modifierPers_clicked();
    void on_supprimerPers_clicked();
    void on_afficherTablePers_clicked();

    void on_vAjouterPro_clicked();
    void on_modifierPro_clicked();
    void on_supprimerPro_clicked();
    void on_afficherTablePro_clicked();

    void exporter(QTableView *table);
    void on_exportExcel_clicked();
    void on_exportExcelP_clicked();

    void on_trier_clicked();
    void on_trierS_clicked();
    void on_trierM_clicked();

    void on_matCh_returnPressed();
    void on_nomCh_textChanged(const QString &arg1);
    void on_chercherDate_clicked();
    void on_fonctionCh_currentIndexChanged(int index);
    void on_chercherTripleC_clicked();



    void on_reduire_clicked();

    void on_statistiques_clicked();

    void on_Afficher1Pers_clicked();










    void on_gestionAmeliorations_clicked();





    void on_gestionStock_clicked();

    void on_gestionAchats_clicked();

    void on_gestionVentes_clicked();

    void on_gestionEquipements_clicked();

    void on_deconnecter_3_clicked();

    void on_envoyerMail_2_clicked();

    QByteArray on_ajouterImgPers_clicked();

    void on_gestionProjet_clicked();

    void on_gestionFormation_clicked();

    void on_gestionEquipement_clicked();

    void on_gestionMaintenances_clicked();



private:
    Ui::Smart_Factory_2A1 *ui;
    login authentification;
    personnels tmpPersonnels;
    profils tmpProfils;
    QPropertyAnimation *reduireAnimation;
    QPropertyAnimation *etendreAnimation;
    QRegExp chaine;
    QRegExp numeroCin;
    QRegExp numeroTelephone;
    QRegExp nomUtilisateur;
    QRegExp email;
    QRegExp mdp;
    projets tmp_projet;
    formation tmp_formation;

};
#endif // SMART_FACTORY_2A1_H
