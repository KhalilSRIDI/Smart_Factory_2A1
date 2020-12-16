#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <QApplication>
#include <QtDebug>
#include "gestionmateriel.h"
#include "ui_mainwindow.h"
#include "gestionmaintenance.h"
#include "email.h"
#include "statis.h"
#include "arduino.h"
#include "arduinoobstacle.h"
#include <QMediaPlayer>
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

private:
    Ui::MainWindow *ui;
    materiel etmp;
    maintenance mtmp;
    QMediaPlayer *click;
};
#endif // MAINWINDOW_H
