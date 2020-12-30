/********************************************************************************
** Form generated from reading UI file 'email.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAIL_H
#define UI_EMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_email
{
public:
    QLineEdit *server;
    QLineEdit *port;
    QLineEdit *uname;
    QLineEdit *paswd;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QPlainTextEdit *msg;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *sendBtn;
    QPushButton *exitBtn;
    QLabel *label_8;

    void setupUi(QDialog *email)
    {
        if (email->objectName().isEmpty())
            email->setObjectName(QStringLiteral("email"));
        email->resize(731, 468);
        email->setStyleSheet(QLatin1String("QLineEdit {\n"
"\n"
"padding: 1px;\n"
"\n"
"border-style: solid;\n"
"\n"
"border: 3px solid darkblue;\n"
"\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"QComboBox {\n"
"    border: 3px solid darkblue;\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"}\n"
"QPushButton {\n"
"\n"
"color:white;\n"
"\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0#91BACF, stop: 0.1#371F57, stop: 0.49#371F57 , stop: 0.5#371F57, stop: 1#91BACF);\n"
"\n"
"border-width: 1px;\n"
"\n"
"border-color: #500;\n"
"\n"
"border-style: solid;\n"
"\n"
"border-radius: 7;\n"
"\n"
"padding: 3px;\n"
"\n"
"font-size: 20px;\n"
"\n"
"padding-left: 5px;\n"
"\n"
"padding-right: 5px;\n"
"\n"
"min-width: 100px;\n"
"\n"
"max-width: 1000px;\n"
"\n"
"min-height: 20px;\n"
"\n"
"max-height: 200px;\n"
"\n"
"}"));
        server = new QLineEdit(email);
        server->setObjectName(QStringLiteral("server"));
        server->setGeometry(QRect(90, 20, 631, 20));
        port = new QLineEdit(email);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(90, 50, 631, 20));
        uname = new QLineEdit(email);
        uname->setObjectName(QStringLiteral("uname"));
        uname->setGeometry(QRect(90, 80, 631, 20));
        paswd = new QLineEdit(email);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setGeometry(QRect(90, 110, 631, 20));
        paswd->setEchoMode(QLineEdit::Password);
        rcpt = new QLineEdit(email);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(90, 140, 631, 20));
        subject = new QLineEdit(email);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(90, 170, 631, 20));
        msg = new QPlainTextEdit(email);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(90, 200, 631, 211));
        label = new QLabel(email);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 81, 16));
        label_2 = new QLabel(email);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 71, 16));
        label_3 = new QLabel(email);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 61, 16));
        label_4 = new QLabel(email);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 110, 61, 16));
        label_5 = new QLabel(email);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 140, 71, 16));
        label_6 = new QLabel(email);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 51, 16));
        label_7 = new QLabel(email);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 200, 61, 16));
        sendBtn = new QPushButton(email);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(450, 430, 112, 28));
        exitBtn = new QPushButton(email);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(580, 430, 112, 28));
        label_8 = new QLabel(email);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(-10, -10, 771, 481));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/GalaxyS7-edge-wallpaper-3.jpg")));
        label_8->raise();
        server->raise();
        port->raise();
        uname->raise();
        paswd->raise();
        rcpt->raise();
        subject->raise();
        msg->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        sendBtn->raise();
        exitBtn->raise();

        retranslateUi(email);

        QMetaObject::connectSlotsByName(email);
    } // setupUi

    void retranslateUi(QDialog *email)
    {
        email->setWindowTitle(QApplication::translate("email", "Dialog", Q_NULLPTR));
        server->setText(QApplication::translate("email", "smtp.gmail.com", Q_NULLPTR));
        port->setText(QApplication::translate("email", "465", Q_NULLPTR));
        label->setText(QApplication::translate("email", "Smtp-server:", Q_NULLPTR));
        label_2->setText(QApplication::translate("email", "Server port:", Q_NULLPTR));
        label_3->setText(QApplication::translate("email", "Username:", Q_NULLPTR));
        label_4->setText(QApplication::translate("email", "Password:", Q_NULLPTR));
        label_5->setText(QApplication::translate("email", "Recipant to:", Q_NULLPTR));
        label_6->setText(QApplication::translate("email", "Subject:", Q_NULLPTR));
        label_7->setText(QApplication::translate("email", "Message:", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("email", "Send", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("email", "Exit", Q_NULLPTR));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class email: public Ui_email {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAIL_H
