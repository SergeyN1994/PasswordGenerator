#include "password.h"
#include <QDebug>
#include <QTime>

Password::Password()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

QString Password::CreateNewPassword(int sizePassword, bool useNumber, bool useSpecialCharacters, bool firstCapitalLetter, Password::_register Register)
{

    QString str = "";

    int RandomCharacterType = 0;
    for(int c = 0; c < sizePassword; ++c){
        while (1) {
            RandomCharacterType = qrand() % 3;

            if(RandomCharacterType == 0) {
                str += GenerateRandomLetter();
                break;
            }
            if(RandomCharacterType == 1 && useNumber == true) {
                str += GenerateRandomNumber();
                break;
            }
            if(RandomCharacterType == 2 && useSpecialCharacters == true) {
                str += GenerateSpecialRandomSymbol();
                break;
            }
        }
    }

    if(Register!= Password::MixedRegister){
        str = setRegister(str, Register);
    }
    if(firstCapitalLetter == true){
        str = FirstCapitalLetter(str);
    }
    return str;
}



QString Password::FirstCapitalLetter(QString str)
{
    QString Str = str;
    if(!Str.isEmpty()){
        Str[0] = Str[0].toUpper();
    }
    return Str;
}

QString Password::GenerateRandomLetter()
{
    QString str = "";
    QChar randomSymbol = qrand() % ('Z'-'A'+1)+'A';
    int Choice_of_register = qrand() % 2;
    if(Choice_of_register == 0){
        randomSymbol = randomSymbol.toLower();
    }
    str.append(randomSymbol);
    return str;
}

QString Password::GenerateSpecialRandomSymbol()
{
    QString str = "";
    int number = qrand() % 9;
    str.append(ArraySpecialChar[number]);

    return str;
}

QString Password::GenerateRandomNumber()
{
    QString str = "";
    int randomNumber = qrand() % 10;
    str = QString::number(randomNumber);
    return str;
}

QString Password::setRegister(QString str, Password::_register Register)
{
    QString Str = str;
    if(Register == Password::HeadingRegister) {
        Str = str.toUpper();
    }
    if(Register == Password::CapitalRegister){
        Str = str.toLower();
    }
    return Str;
}
