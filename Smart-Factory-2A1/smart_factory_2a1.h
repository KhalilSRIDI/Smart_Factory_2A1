#ifndef SMART_FACTORY_2A1_H
#define SMART_FACTORY_2A1_H
#include "connexionsql.h"
#include "login.h"
#include "personnels.h"
#include "profils.h"
#include "projets.h"
#include "formation.h"
#include "gestionmateriel.h"
#include "gestionmaintenance.h"
#include "email.h"
#include "statis.h"
#include "arduino.h"
#include "arduinoobstacle.h"
#include <QMainWindow>
#include <QStatusBar>
#include <QSound>
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
#include <QMediaPlayer>
#include <QPrinter>
#include <QTextDocument>
#include "statistiques.h"

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

//    void traduire(QString );

//    void on_langueBox_currentTextChanged(const QString &arg1);

//    void on_langueBox_currentIndexChanged(const QString &arg1);



    void on_langueBox_currentTextChanged(const QString &arg1);

    void on_ajouterImgPers_3_clicked();


    void on_ajouterImgPers_clicked();

    void on_resetImgPers_clicked();
    void on_pushButtonAjouter_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonAjouterF_clicked();

    void on_pushButtonSupprimerF_clicked();

    void on_pushButtonModifierF_clicked();

    void on_pushButtonRechercheF_clicked();

    void on_pushButtonRechercheP_clicked();

    void on_pushButtonRefreshP_clicked();

    void on_pushButtonRefreshF_clicked();

    void on_pushButtonExportF_clicked();

    void on_pushButtonExportP_clicked();

    void on_pushTrierP_clicked();

    void on_pushTrierF_clicked();

    void on_pushButtonStat_clicked();



    void on_gestionAmeliorations_clicked();

    void on_pushButton_gestion_materiel_clicked();

    void on_pushButton_valider_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_recherche_clicked();
    void on_pushButton_trier_clicked();

    void on_pushButton_validermaint_clicked();
    void on_pushButton_supprimermaint_clicked();
    void on_pushButton_modifiermaint_clicked();
    void on_pushButton_recherche_2_clicked();
    void on_pushButton_trier_2_clicked();

    void on_pushButton_email_clicked();
    void on_pushButton_stat_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButtonExportPDFP_clicked();

    void on_pushButtonExportPDFF_clicked();

    void on_pushButtonExporterEquip_clicked();

    void on_pushButtonExporterMain_clicked();

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
    materiel etmp;
    maintenance mtmp;
// QMediaPlayer *click;

};
#endif // SMART_FACTORY_2A1_H
