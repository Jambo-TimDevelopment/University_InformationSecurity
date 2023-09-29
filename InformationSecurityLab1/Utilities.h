#ifndef UTILITIES_H
#define UTILITIES_H

#pragma once

#include <qstring.h>
#include <QList>

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

    QString Login;

    QString EncryptedPassword;

    bool Blocked;

    bool LimitPassword = true;
};

namespace SecurityManager
{

    static int MIN_PASS_LENGTH;
    static int MIN_PASS_TIMEOUT;
    const QString FILE_NAME_WITH_USERS = "C:/University/4Course/IS/FileWithUsers.txt";

    static QString USER_NAME;
    static QString USER_PASS;
    static QString PASS_PHRASE;

    static QList<User> USER_LIST;
};     // namespace SecurityManager
#endif // UTILITIES_H
