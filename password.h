#ifndef PASSWORD_H
#define PASSWORD_H

#include <QString>
#include <QList>


class Password
{
public:
    Password();
    enum _register{
        MixedRegister = 0,
        HeadingRegister = 1,
        CapitalRegister = 2
    };

    QString CreateNewPassword(int sizePassword = 1, bool useNumber = false, bool useSpecialCharacters = false, bool firstCapitalLetter = false, Password::_register Register = Password::MixedRegister);

private:
    QChar ArraySpecialChar[9] = {'%', '*', '(', ')', '?', '@', '#', '$', '~'};
    QString FirstCapitalLetter(QString str);
    QString GenerateRandomLetter();
    QString GenerateSpecialRandomSymbol();
    QString GenerateRandomNumber();
    QString setRegister(QString str,Password::_register Register);

};

#endif // PASSWORD_H
