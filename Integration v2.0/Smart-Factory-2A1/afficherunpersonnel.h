#ifndef AFFICHERUNPERSONNEL_H
#define AFFICHERUNPERSONNEL_H
#include "connexionsql.h"
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
namespace Ui {
class afficherUnPersonnel;
}
class afficherUnPersonnel : public QDialog
{
    Q_OBJECT
public:
    explicit afficherUnPersonnel(QWidget *parent = nullptr);
    ~afficherUnPersonnel();
private slots:    
    void on_imprimerBoutton_clicked();
    void on_rechAffPers_clicked();
private:
    Ui::afficherUnPersonnel *ui;
};
#endif // AFFICHERUNPERSONNEL_H
