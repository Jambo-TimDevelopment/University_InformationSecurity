#ifndef USER_H
#define USER_H

#include <qstring.h>
#include <QDataStream>
#include <QList>

class User
{
public:
    User();

    User(QString newLogin);

    User(QString newLogin, QString newEncryptedPassword, bool newBlocked, bool newLimitPassword);

    bool operator==(const User& counter) const;

    QString Login;
    QString EncryptedPassword;
    bool Blocked;
    bool LimitPassword = true;

    friend QDataStream& operator>>(QDataStream& d, User& u);
};

#endif // USER_H
