#include "user.h"
#include "qdebug.h"

User::User() {}

User::User(QString newLogin)
{
    Login = newLogin;
    EncryptedPassword = "";
    Blocked = true;
    LimitPassword = true;
}

User::User(QString newLogin, QString newEncryptedPassword, bool newBlocked, bool newLimitPassword)
{
    Login = newLogin;
    EncryptedPassword = newEncryptedPassword;
    Blocked = newBlocked;
    LimitPassword = newLimitPassword;
}

bool User::operator==(const User& counter) const
{
    return this->Login == counter.Login;
}

bool User::operator!=(const User& counter) const
{
    return this->Login != counter.Login;
}

QDataStream& operator<<(QDataStream& d, const User& u)
{
    d << u.Login << u.EncryptedPassword << u.Blocked << u.LimitPassword;
    return d;
}

QDataStream& operator>>(QDataStream& d, User& u)
{
    d >> u.Login >> u.EncryptedPassword >> u.Blocked >> u.LimitPassword;
    return d;
}

QDebug operator<<(QDebug d, const User& u)
{
    d << QString("User( %1, %2, %3, %4 )").arg(u.Login).arg(u.EncryptedPassword).arg(u.Blocked).arg(u.LimitPassword);
    return d;
}
