#include "modifierprofil.h"
#include "login.h"
#include "smart_factory_2a1.h"
#include "ui_modifierprofil.h"

modifierProfil::modifierProfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierProfil)
{
    ui->setupUi(this);
}

modifierProfil::~modifierProfil()
{
    delete ui;
}

void modifierProfil::on_buttonBox_2_accepted()
{
    if (ui->CNMDP->text()==ui->NMDP->text())
    {
        if (ui->AMDP->text()!="" && ui->CNMDP->text()!="")
        {
            login l;
            bool test=l.modifierMotDePasse(289,ui->AMDP->text(),ui->NMDP->text());

            if (!test)
                QMessageBox::warning(this,tr("Changement du MDP"),tr("Erreur lors du changement du MDP"));
            else
            {
                ui->AMDP->clear();
                ui->NMDP->clear();
                ui->CNMDP->clear();
            }
        }
        else
            QMessageBox::warning(this,tr("Changement du MDP"),tr("Veuillez remplir tous les champs"));
    }
    else
        QMessageBox::warning(this,tr("Changement du MDP"),tr("Les deux mots de passe ne sont pas identiques"));
}
