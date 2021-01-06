#include "statistique2.h"
#include "ui_statistique2.h"

statistique2::statistique2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statistique2)
{
    ui->setupUi(this);

    QBarSet *set1=new QBarSet("Couts");
    QBarSet *set2=new QBarSet("Revenus");

    *set1 << tmp_projet.calculCout("Ressources Humaines") << tmp_projet.calculCout("Stock") << tmp_projet.calculCout("Achats") << tmp_projet.calculCout("Ventes") << tmp_projet.calculCout("Ameliorations")<< tmp_projet.calculCout("Materiel");
    *set2 << tmp_projet.calculRevenus("Ressources Humaines") << tmp_projet.calculRevenus("Stock") << tmp_projet.calculRevenus("Achats") << tmp_projet.calculRevenus("Ventes") << tmp_projet.calculRevenus("Ameliorations")<< tmp_projet.calculRevenus("Materiel");

    QBarSeries *series=new QBarSeries();
    series->append(set1);
    series->append(set2);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("Les projets");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories <<"Ressources Humaines"<<"Stock"<<"Achats"<<"Ventes"<<"Ameliorations"<<"Materiel";
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    axis->setMax("10000");
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(chartview, 1, 1);
    setLayout(mainLayout);
}

statistique2::~statistique2()
{
    delete ui;
}
