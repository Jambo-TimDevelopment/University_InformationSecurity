#ifndef FILESERVICE_H
#define FILESERVICE_H
#pragma once

#include <userservice.h>
#include <QFile>
#include <QString>
#include <User.h>

/**
 *  QCryptographicHash Class
 *  https://doc.qt.io/qt-5/qcryptographichash.html
 */

class FileService
{
public:
    FileService();

public:
    static void SetupUserListFile(QString passPhrase);

    static QList<User> GetUsersFromFile(QString fileName, QString passPhrase);

    static bool FindUserByName(QString name, User& foundUser);

    static void AddUserToFile(QString fileName, User newUser, QString passPhrase);

    static void SaveUsersToFile(QString fileName, QList<User> list, QString passPhrase);

    static void EncryptFile(QString fileName, QString passPhrase);

    static void DecryptFile(QString fileName, QString passPhrase);

    static void PrintDebugInformation(QString functionName);

    static QList<User> GetUsersFromFile_Internal(QString fileName);
};

#endif // FILESERVICE_H
