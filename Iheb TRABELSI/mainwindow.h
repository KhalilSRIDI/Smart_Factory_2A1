#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "commande.h"
#include "ui_mainwindow.h"
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include<QSqlTableModel>



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
    void on_valider_clicked();
    void on_pushButtonAjouter_clicked();
    void on_pushButtonSupprimer_clicked();
    void on_pushButtonModifier_clicked();


    void on_pushButtonRechercher_clicked();

    void on_pushButtonAjouter_2_clicked();

    void on_pushButtonModifier_2_clicked();

    void on_pushButtonSupprimer_2_clicked();

    void on_pushButtonRechercher_2_clicked();

private:
    Ui::MainWindow *ui;
    client temp_client;

};
#endif // MAINWINDOW_H
