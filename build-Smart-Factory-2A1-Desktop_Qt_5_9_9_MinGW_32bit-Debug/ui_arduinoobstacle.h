/********************************************************************************
** Form generated from reading UI file 'arduinoobstacle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINOOBSTACLE_H
#define UI_ARDUINOOBSTACLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_arduinoobstacle
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_off_2;
    QPushButton *pushButton_onrouge;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_on;
    QPushButton *pushButton_2;

    void setupUi(QWidget *arduinoobstacle)
    {
        if (arduinoobstacle->objectName().isEmpty())
            arduinoobstacle->setObjectName(QStringLiteral("arduinoobstacle"));
        arduinoobstacle->resize(425, 331);
        pushButton = new QPushButton(arduinoobstacle);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 300, 112, 28));
        pushButton->setStyleSheet(QLatin1String("QLineEdit {\n"
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
        lineEdit = new QLineEdit(arduinoobstacle);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 90, 113, 22));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {\n"
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
        label = new QLabel(arduinoobstacle);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 80, 161, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Myriad Pro"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(arduinoobstacle);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-230, -10, 671, 341));
        label_2->setStyleSheet(QLatin1String("QLineEdit {\n"
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
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/GalaxyS7-edge-wallpaper-3.jpg")));
        pushButton_off_2 = new QPushButton(arduinoobstacle);
        pushButton_off_2->setObjectName(QStringLiteral("pushButton_off_2"));
        pushButton_off_2->setGeometry(QRect(230, 150, 112, 31));
        pushButton_off_2->setStyleSheet(QLatin1String("QLineEdit {\n"
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
        pushButton_onrouge = new QPushButton(arduinoobstacle);
        pushButton_onrouge->setObjectName(QStringLiteral("pushButton_onrouge"));
        pushButton_onrouge->setGeometry(QRect(100, 220, 112, 31));
        pushButton_onrouge->setStyleSheet(QLatin1String("QLineEdit {\n"
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
        pushButton_3 = new QPushButton(arduinoobstacle);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 220, 112, 31));
        pushButton_3->setStyleSheet(QLatin1String("QLineEdit {\n"
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
        label_3 = new QLabel(arduinoobstacle);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 280, 71, 51));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../Sans titre-.png")));
        label_4 = new QLabel(arduinoobstacle);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 150, 91, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_4->setPalette(palette1);
        label_4->setFont(font);
        label_5 = new QLabel(arduinoobstacle);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 220, 81, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_5->setPalette(palette2);
        label_5->setFont(font);
        pushButton_on = new QPushButton(arduinoobstacle);
        pushButton_on->setObjectName(QStringLiteral("pushButton_on"));
        pushButton_on->setGeometry(QRect(100, 150, 112, 31));
        pushButton_on->setStyleSheet(QLatin1String("QLineEdit {\n"
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
        pushButton_2 = new QPushButton(arduinoobstacle);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 340, 112, 28));
        pushButton_2->setStyleSheet(QLatin1String("QLineEdit {\n"
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
        label_2->raise();
        pushButton->raise();
        lineEdit->raise();
        label->raise();
        pushButton_off_2->raise();
        pushButton_onrouge->raise();
        pushButton_3->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        pushButton_on->raise();
        pushButton_2->raise();

        retranslateUi(arduinoobstacle);

        QMetaObject::connectSlotsByName(arduinoobstacle);
    } // setupUi

    void retranslateUi(QWidget *arduinoobstacle)
    {
        arduinoobstacle->setWindowTitle(QApplication::translate("arduinoobstacle", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("arduinoobstacle", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("arduinoobstacle", "Etat de la place:", Q_NULLPTR));
        label_2->setText(QString());
        pushButton_off_2->setText(QApplication::translate("arduinoobstacle", "Off", Q_NULLPTR));
        pushButton_onrouge->setText(QApplication::translate("arduinoobstacle", "On", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("arduinoobstacle", "Off", Q_NULLPTR));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("arduinoobstacle", "rouge", Q_NULLPTR));
        label_5->setText(QApplication::translate("arduinoobstacle", "vert", Q_NULLPTR));
        pushButton_on->setText(QApplication::translate("arduinoobstacle", "On", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("arduinoobstacle", "2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class arduinoobstacle: public Ui_arduinoobstacle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINOOBSTACLE_H
