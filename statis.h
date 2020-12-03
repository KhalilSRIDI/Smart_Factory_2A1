#ifndef STATIS_H
#define STATIS_H

#include <QDialog>
#include "gestionmateriel.h"
namespace Ui {
class statis;
}

class statis : public QDialog
{
    Q_OBJECT

public:
    explicit statis(QWidget *parent = 0);
    ~statis();

private slots:
    void on_pushButton_clicked();

private:
    Ui::statis *ui;
};

#endif // STATIS_H
