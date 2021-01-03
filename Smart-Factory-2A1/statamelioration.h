#ifndef STATAMELIORATION_H
#define STATAMELIORATION_H

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
class statamelioration;
}

class statamelioration: public QWidget
{
    Q_OBJECT

public:
    explicit statamelioration(QWidget *parent = nullptr);
    ~statamelioration();

private:
    Ui::statamelioration *ui;
    projets tmp_projet;
};

#endif // STATAMELIORATION_H
