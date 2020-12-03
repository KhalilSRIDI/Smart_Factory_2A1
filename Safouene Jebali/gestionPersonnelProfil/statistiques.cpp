#include "statistiques.h"
#include "ui_statistiques.h"


statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
    statistiquesSE();
    statistiquesSF();
    statistiquesTC();





}

statistiques::~statistiques()
{
    delete ui;
}

void statistiques::statistiquesSE()
{
    QBarSet *set0 = new QBarSet("Homme");
    QBarSet *set1 = new QBarSet("Femme");
    *set0 << tmpPersonnels.calculerSE("masculin","marie") << tmpPersonnels.calculerSE("masculin","celebataire") << tmpPersonnels.calculerSE("masculin","divorce");
    *set1 << tmpPersonnels.calculerSE("feminin","marie") << tmpPersonnels.calculerSE("feminin","celebataire") << tmpPersonnels.calculerSE("feminin","divorce");
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques Selon Sexe et Etat Civile");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories << "Marie" << "Celebataire" << "Divorce" ;
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->statsFrame1);
}
void statistiques::statistiquesTC()
{
    QPieSeries *series = new QPieSeries();
    series->append("SIVP",tmpPersonnels.calculerTC("SIVP"));
    series->append("CDD",tmpPersonnels.calculerTC("CDD"));
    series->append("CDI",tmpPersonnels.calculerTC("CDI"));
    QPieSlice *sliceSIVP = series->slices().at(0);
    sliceSIVP->setExploded(true);
    sliceSIVP->setLabelVisible(true);
    sliceSIVP->setPen(QPen(Qt::darkRed, 0));
    sliceSIVP->setBrush(Qt::red);
    QPieSlice *sliceCDD = series->slices().at(1);
    sliceCDD->setExploded(true);
    sliceCDD->setLabelVisible(true);
    sliceCDD->setPen(QPen(Qt::darkBlue, 1));
    sliceCDD->setBrush(Qt::blue);
    QPieSlice *sliceCDI = series->slices().at(2);
    sliceCDI->setExploded(true);
    sliceCDI->setLabelVisible(true);
    sliceCDI->setPen(QPen(Qt::darkGreen, 2));
    sliceCDI->setBrush(Qt::green);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques Selon Type Contrat");
    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->statsFrame2);
}
void statistiques::statistiquesSF()
{
    QBarSet *set0 = new QBarSet("Homme");
    QBarSet *set1 = new QBarSet("Femme");
    *set0 << tmpPersonnels.calculerSF("masculin","chef de departement") << tmpPersonnels.calculerSF("masculin","chef d unite") << tmpPersonnels.calculerSF("masculin","ingenieur")<< tmpPersonnels.calculerSF("masculin","technicien")<< tmpPersonnels.calculerSF("masculin","ouvrier") << tmpPersonnels.calculerSF("masculin","chercheur") << tmpPersonnels.calculerSF("masculin","commercial");
    *set1 << tmpPersonnels.calculerSF("feminin","chef de departement") << tmpPersonnels.calculerSF("feminin","chef d unite") << tmpPersonnels.calculerSF("feminin","ingenieur")<< tmpPersonnels.calculerSF("feminin","technicien")<< tmpPersonnels.calculerSF("feminin","ouvrier") << tmpPersonnels.calculerSF("feminin","chercheur") << tmpPersonnels.calculerSF("feminin","commercial");
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques Selon Sexe et Fonction");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories << "Chef Departement" << "Chef Unite" << "Ingenieur"<< "Technicien" << "Ouvrier" << "Chercheur"<< "Commercial" ;
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->statsFrame3);
}

