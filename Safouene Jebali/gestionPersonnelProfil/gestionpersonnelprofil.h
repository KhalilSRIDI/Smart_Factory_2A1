#ifndef GESTIONPERSONNELPROFIL_H
#define GESTIONPERSONNELPROFIL_H
#include "connexionsql.h"
#include "statistiques.h"
#include "personnels.h"
#include "afficherunpersonnel.h"
#include "profils.h"
#include <QMainWindow>
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
namespace Ui { class GestionPersonnelProfil; }
QT_END_NAMESPACE
class GestionPersonnelProfil : public QMainWindow
{
    Q_OBJECT
public:
    GestionPersonnelProfil(QWidget *parent = nullptr);
    ~GestionPersonnelProfil();

private slots:
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

private:
    Ui::GestionPersonnelProfil *ui;
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


};
#endif // GESTIONPERSONNELPROFIL_H
