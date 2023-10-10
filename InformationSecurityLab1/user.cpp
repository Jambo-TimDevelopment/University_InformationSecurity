#include "user.h"

User::User() {}

User::User(QString newLogin)
{
    Login = newLogin;
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

QDataStream& operator<<(QDataStream& d, const User& u)
{
    QString strBlocked = u.Blocked ? "true" : "false";
    QString strLimitPassword = u.LimitPassword ? "true" : "false";
    d << u.Login << u.EncryptedPassword << strBlocked << strLimitPassword;
    return d;
}

QDataStream& operator>>(QDataStream& d, User& u)
{
    QString strBlocked = u.Blocked ? "true" : "false";
    QString strLimitPassword = u.LimitPassword ? "true" : "false";

    d >> u.Login >> u.EncryptedPassword >> strBlocked >> strLimitPassword;
    return d;
}
