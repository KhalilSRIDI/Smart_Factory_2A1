#ifndef STATISTIQUE2_H
#define STATISTIQUE2_H

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
class statistique2;
}

class statistique2 : public QWidget
{
    Q_OBJECT

public:
    explicit statistique2(QWidget *parent = nullptr);
    ~statistique2();

private:
    Ui::statistique2 *ui;
    projets tmp_projet;
};

#endif // STATISTIQUE2_H
