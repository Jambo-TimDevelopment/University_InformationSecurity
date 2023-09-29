#ifndef USERSERVICE_H
#define USERSERVICE_H
#pragma once
#include <QString>

class UserService
{
public:
    static bool IsAdmin(QString login) { return login == "ADMIN"; }

    static bool SetNewPassword(QString newPassword);

    static bool CheckPassword(QString password, QString oldPassword);

public:
    static bool VerifyPassword(QString password);

private:
    static QString Hash(QString password);
};

#endif // USERSERVICE_H
