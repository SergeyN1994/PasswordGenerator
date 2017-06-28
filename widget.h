#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include "password.h"
#include <QDebug>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void updateInfoGroupBoxRegister();

public slots:
    void apdateUserSelection();

private:
    Ui::Widget *ui;

    Password::_register Register;
    bool useNumber;
    bool useSpecialCharacters;
    bool UniqueCharacters;
    bool FirstCapitalLetter;

    Password *password;

};

#endif // WIDGET_H
