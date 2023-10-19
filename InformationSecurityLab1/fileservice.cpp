#include "fileservice.h"
#include "Utilities.h"
#include "QAESEncryption.h"

#include <QFile>
#include <QList>
#include <QMessageBox>
#include <QDataStream>
#include <UserList.h>
#include <QCryptographicHash>

#include <bits/functional_hash.h>

FileService::FileService() {}

void FileService::PrintDebugInformation(QString functionName)
{
    SecurityManager securityManager = SecurityManager();
    QFile fileWithUsers(securityManager.FILE_NAME_WITH_USERS);
    if (fileWithUsers.open(QIODevice::ReadOnly))
    {
        qDebug() << "\n " + functionName;
        QDataStream stream(&fileWithUsers);
        QList<User> list = QList<User>();
        UserList userList = UserList(list);
        stream >> userList;
        fileWithUsers.close();
        qDebug() << "Length" << userList.Data.length();
        for (User& user : userList.Data)
        {
            qDebug() << user;
        }
    }
}

QList<User> FileService::GetUsersFromFile_Internal(QString fileName)
{

    QFile fileWithUsers = QFile(fileName);
    QList<User> outUserList = QList<User>();

    if (!fileWithUsers.exists())
    {
        qDebug() << "\nFile not exist";
        return outUserList;
    }

    if (!fileWithUsers.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error when open file";
        return outUserList;
    }

    UserList userList;
    QDataStream stream(&fileWithUsers);
    stream >> userList;
    outUserList = userList.Data;
    fileWithUsers.close();

    FileService::PrintDebugInformation("FileService::GetUsersFromFile");

    return outUserList;
}

void FileService::SetupUserListFile(QString passPhrase)
{
    SecurityManager securityManager = SecurityManager();

    QFile fileWithUsers(securityManager.FILE_NAME_WITH_USERS);

    if (!fileWithUsers.exists(securityManager.FILE_NAME_WITH_USERS))
    {
        FileService::AddUserToFile(securityManager.FILE_NAME_WITH_USERS, User("ADMIN"), passPhrase);
    }
    else
    {
        User adminUser;
        if (!FileService::FindUserByName("ADMIN", adminUser))
        {
            FileService::AddUserToFile(securityManager.FILE_NAME_WITH_USERS, User("ADMIN"), passPhrase);
        }
    }

    FileService::PrintDebugInformation("FileService::SetupUserListFile");
}

// Getting user list from file
QList<User> FileService::GetUsersFromFile(QString fileName, QString passPhrase)
{
    FileService::DecryptFile(fileName, passPhrase);

    return FileService::GetUsersFromFile_Internal(fileName);
}

bool FileService::FindUserByName(QString name, User& foundUser)
{
    SecurityManager securityManager = SecurityManager();
    QList<User> userList = GetUsersFromFile(securityManager.FILE_NAME_WITH_USERS, securityManager.PASS_PHRASE);

    for (User& user : userList)
    {
        if (user.Login == name)
        {
            foundUser = user;
            return true;
        }
    }
    return false;
}

void FileService::AddUserToFile(QString fileName, User newUser, QString passPhrase)
{
    QList<User> list = QList<User>();
    list.append(newUser);
    FileService::SaveUsersToFile(fileName, list, passPhrase);
}

void FileService::SaveUsersToFile(QString fileName, QList<User> list, QString passPhrase)
{
    QFile fileWithUsers = QFile(fileName);

    if (fileWithUsers.open(QIODevice::WriteOnly))
    {
        QDataStream stream(&fileWithUsers);
        QList<User> ListOfUsers = QList<User>();
        ListOfUsers.append(list);

        stream << ListOfUsers;
        fileWithUsers.close();
    }

    FileService::PrintDebugInformation("FileService::SaveUsersToFile");
    FileService::EncryptFile(fileName, passPhrase);

    fileWithUsers.remove();
}

void FileService::EncryptFile(QString fileName, QString passPhrase)
{
    if (passPhrase.isEmpty())
    {
        return;
    }

    QFile fileWithUsers(fileName);
    QByteArray input;
    if (fileWithUsers.open(QFile::ReadOnly))
    {
        input = fileWithUsers.readAll();
    }

    QByteArray iv;
    quint8 iv_16[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    for (int i = 0; i < 16; i++)
    {
        iv.append(iv_16[i]);
    }

    QByteArray hashKey = QCryptographicHash::hash(passPhrase.toLocal8Bit(), QCryptographicHash::Sha256);
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::CFB);
    QByteArray encodeData = encryption.encode(input, hashKey, iv);

    QFile encryptedFileWithUsers = QFile(SecurityManager().ENCRYPTED_FILE_WITH_USERS);
    if (encryptedFileWithUsers.open(QFile::WriteOnly))
    {
        encryptedFileWithUsers.write(encodeData);
        encryptedFileWithUsers.close();
    }
}

void FileService::DecryptFile(QString fileName, QString passPhrase)
{
    if (passPhrase.isEmpty())
    {
        return;
    }

    QFile encryptedFileWithUsers = QFile(SecurityManager().ENCRYPTED_FILE_WITH_USERS);
    QByteArray input;
    if (encryptedFileWithUsers.open(QFile::ReadOnly))
    {
        input = encryptedFileWithUsers.readAll();
    }

    QByteArray iv;
    quint8 iv_16[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    for (int i = 0; i < 16; i++)
    {
        iv.append(iv_16[i]);
    }

    QByteArray hashKey = QCryptographicHash::hash(passPhrase.toLocal8Bit(), QCryptographicHash::Sha256);
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::CFB);
    QByteArray decodedText = encryption.removePadding(encryption.decode(input, hashKey, iv));

    QFile fileWithUsers(fileName);
    if (fileWithUsers.open(QFile::WriteOnly))
    {
        fileWithUsers.write(decodedText);
        fileWithUsers.close();
    }
}
