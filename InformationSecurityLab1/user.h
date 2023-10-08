#ifndef USER_H
#define USER_H

#include <qstring.h>

struct User
{
    User() {}

    User(QString newLogin)
    {
        Login = newLogin;
    }

    User(QString newLogin, QString newEncryptedPassword, bool newBlocked, bool newLimitPassword)
    {
        Login = newLogin;
        EncryptedPassword = newEncryptedPassword;
        Blocked = newBlocked;
        LimitPassword = newLimitPassword;
    }

    bool operator==(const User& counter) const
    {
        return this->Login == counter.Login;
    }

    QString Login;
    QString EncryptedPassword;
    bool Blocked;
    bool LimitPassword = true;
};

#endif // USER_H
