#ifndef EMAIL_H
#define EMAIL_H
#include <QFile>
#include <QDialog>
#include "smtp.h"
#include "ui_email.h"
#include <QtWidgets/QMessageBox>



namespace Ui {
class email;
}

class email : public QDialog
{
    Q_OBJECT

public:
    explicit email(QWidget *parent = nullptr);
    ~email();


private slots:
    void sendMail();
    void mailSent(QString);
    void on_sendBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::email *ui;

};

#endif // EMAIL_H
