#ifndef STATISTIQUES_H
#define STATISTIQUES_H
#include "personnels.h"
#include <QDialog>
#include <QFrame>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>

namespace Ui {
class statistiques;
}

class statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();
    int type;
    void statistiquesSE();
    void statistiquesTC();
    void statistiquesSF();

private:
    Ui::statistiques *ui;
    personnels tmpPersonnels;
};

#endif // STATISTIQUES_H
