#include "dialog.h"
#include "ui_dialog.h"
#include "smtp.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    QPixmap bkgnd("D:/Users/dhiaa/Desktop/gestion_invités/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}
Dialog::Dialog(QString e,QString n,QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QString contenu="Contenu";
    ui->setupUi(this);

    ui->recipient->setText(e);
    ui->uname->setText("smartfactory2a1@gmail.com");
    ui->passwd->setText("Smartfactory&2!1");
    ui->passwd->setEchoMode(QLineEdit::Password);


}
Dialog::~Dialog()
{
    delete ui;

}

void Dialog::on_envoyer_dialog_clicked()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->passwd->text(), "smtp.gmail.com", 465);

    smtp->sendMail(ui->uname->text(), ui->recipient->text() , ui->subjectLineEdit->text() ,ui->message->toPlainText());


}
