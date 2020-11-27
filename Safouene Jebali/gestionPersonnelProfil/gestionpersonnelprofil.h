#ifndef GESTIONPERSONNELPROFIL_H
#define GESTIONPERSONNELPROFIL_H
#include "personnels.h"
#include "profils.h"
#include "connexionsql.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QTableView>
#include <QSqlTableModel>
#include <QStatusBar>
#include <QTextStream>
#include <QMessageBox>
#include <QRegularExpression>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QSoundEffect>
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
    void on_vAjouterPers_clicked();
    void on_gestionPersonnel_clicked();
    void on_gestionProfil_clicked();
    void on_modifierPers_clicked();
    void exporter(QTableView *table);
    void on_exportExcel_clicked();
    void on_supprimerPers_clicked();
    void on_vAjouterPro_clicked();
    void on_modifierPro_clicked();
    void on_supprimerPro_clicked();
    void on_exportExcelP_clicked();
    void on_matCh_returnPressed();
    void on_fonctionCh_currentIndexChanged(int index);
    void on_chercherDate_clicked();
    void on_chercherTripleC_clicked();
    void on_trier_clicked();
private:
    Ui::GestionPersonnelProfil *ui;
    personnels tmpPersonnels;
    profils tmpProfils;
    QRegExp email_regex;
};
#endif // GESTIONPERSONNELPROFIL_H
