#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "projets.h"
#include "formation.h"
#include "ui_mainwindow.h"
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtDebug>
#include <QRegularExpression>
#include <QDate>
#include <QDateTimeEdit>
#include <QSound>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
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

private:
    Ui::MainWindow *ui;
    projets tmp_projet;
    formation tmp_formation;

};
#endif // MAINWINDOW_H
