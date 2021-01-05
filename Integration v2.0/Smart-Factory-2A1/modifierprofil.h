#ifndef MODIFIERPROFIL_H
#define MODIFIERPROFIL_H

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

private:
    Ui::modifierProfil *ui;
};

#endif // MODIFIERPROFIL_H
