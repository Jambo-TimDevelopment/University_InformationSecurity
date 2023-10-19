#ifndef UTILITIES_H
#define UTILITIES_H

#include "qdebug.h"

#include <qstring.h>
#include <QList>
#include <qfile.h>
#include <FileService.h>

class User;

class SecurityManager
{
public:
    SecurityManager();

    const QString FILE_NAME_WITH_USERS = "C:/University/4Course/IS/FileWithUsers.dat";
    const QString ENCRYPTED_FILE_WITH_USERS = "C:/University/4Course/IS/EncryptedFileWithUsers.dat";
    const QString TMP_FILE = "C:/University/4Course/IS/tmpFile.txt";

    QString PASS_PHRASE; // 0
    QString USER_NAME;   // 1
    QString USER_PASS;   // 2

    int MIN_PASS_LENGTH;  // 3
    int MIN_PASS_TIMEOUT; // 4

    void setPASS_PHRASE(const QString& newPASS_PHRASE);
    void setUSER_NAME(const QString& newUSER_NAME);
    void setUSER_PASS(const QString& newUSER_PASS);
};

#endif // UTILITIES_H
