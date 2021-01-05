#include "modifierprofil.h"
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
