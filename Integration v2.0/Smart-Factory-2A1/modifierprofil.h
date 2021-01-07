#ifndef MODIFIERPROFIL_H
#define MODIFIERPROFIL_H
#include "login.h"
#include "smart_factory_2a1.h"
#include <QDialog>

namespace Ui {
class modifierProfil;
}

class modifierProfil : public QDialog
{
    Q_OBJECT

public:
    explicit modifierProfil(QWidget *parent = nullptr);
    ~modifierProfil();


private slots:
    void on_buttonBox_2_accepted();

private:
    Ui::modifierProfil *ui;
};

#endif // MODIFIERPROFIL_H
