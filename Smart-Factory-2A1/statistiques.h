#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include<QWidget>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QGridLayout>
#include"projets.h"
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class statistiques;
}

class statistiques : public QWidget
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();

private:
    Ui::statistiques *ui;
    projets tmp_projet;
};

#endif // STATISTIQUES_H
