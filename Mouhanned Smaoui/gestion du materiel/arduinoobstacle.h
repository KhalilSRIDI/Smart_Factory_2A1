#ifndef ARDUINOOBSTACLE_H
#define ARDUINOOBSTACLE_H
#include"arduino.h"
#include <QWidget>

namespace Ui {
class arduinoobstacle;
}

class arduinoobstacle : public QWidget
{
    Q_OBJECT

public:
    explicit arduinoobstacle(QWidget *parent = nullptr);
    ~arduinoobstacle();

private slots:
    void on_pushButton_clicked();

    void update_label();

  //  void on_pushButton_2_clicked();

    void on_pushButton_on_clicked();

    void on_pushButton_off_2_clicked();

    void on_pushButton_onrouge_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::arduinoobstacle *ui;

    Arduino A;
          QByteArray data; // variable contenant les données reçues
          QString serialBuffer;
};

#endif // ARDUINOOBSTACLE_H
