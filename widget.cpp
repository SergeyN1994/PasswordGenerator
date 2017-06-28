#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle(QString::fromUtf8("Генератор паролей"));
    ui->radioButton->setChecked(true);

    useSpecialCharacters = false;
    useNumber = false;
    UniqueCharacters = false;
    FirstCapitalLetter = false;
    Register = Password::MixedRegister;

    password = new Password;

    connect(ui->checkBoxNamber, SIGNAL(stateChanged(int)), this, SLOT(apdateUserSelection()));
    connect(ui->checkBoxSpChar, SIGNAL(stateChanged(int)), this, SLOT(apdateUserSelection()));
    connect(ui->checkBox_3, SIGNAL(stateChanged(int)), this, SLOT(apdateUserSelection()));
    connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(updateInfoGroupBoxRegister()));
    connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(updateInfoGroupBoxRegister()));
    connect(ui->radioButton_3, SIGNAL(clicked(bool)), this, SLOT(updateInfoGroupBoxRegister()));
}

Widget::~Widget()
{
    delete ui;
    delete password;
}

void Widget::on_pushButton_clicked()
{
    ui->textEdit->clear();
    QString str = "";
    for(int c = 0; c < ui->spinBox_2->value(); ++c){
        str = password->CreateNewPassword(ui->spinBox->value(), useNumber, useSpecialCharacters, FirstCapitalLetter, Register);
        ui->textEdit->append(str);
    }
}

void Widget::updateInfoGroupBoxRegister()
{
    if(ui->radioButton->isChecked()){
        Register = Password::MixedRegister;
    }
    if(ui->radioButton_2->isChecked()){
        Register = Password::HeadingRegister;
    }
    if(ui->radioButton_3->isChecked()){
        Register = Password::CapitalRegister;
    }
}

void Widget::apdateUserSelection()
{
    useSpecialCharacters = ui->checkBoxSpChar->isChecked();
    useNumber = ui->checkBoxNamber->isChecked();
    FirstCapitalLetter = ui->checkBox_3->isChecked();
}
