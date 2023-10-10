#include "fileservice.h"
#include "Utilities.h"

#include <QFile>
#include <QList>
#include <QMessageBox>
#include <QDataStream>
#include <UserList.h>

FileService::FileService() {}

void FileService::SetupUserListFile()
{
    SecurityManager securityManager = SecurityManager();

    QFile* tmpFile = new QFile(securityManager.TMP_FILE);
    tmpFile->remove();

    QFile fileWithUsers(securityManager.FILE_NAME_WITH_USERS);

    if (!fileWithUsers.exists(securityManager.FILE_NAME_WITH_USERS))
    {
        fileWithUsers.open(QIODevice::WriteOnly);
        fileWithUsers.close();

        if (fileWithUsers.open(QIODevice::WriteOnly))
        {
            QDataStream stream(&fileWithUsers);
            QList<User> list = QList<User>();
            list.append(User("ADMIN"));
            UserList userList = UserList(list);
            stream << userList;
            fileWithUsers.close();
        }
    }
    else
    {
        if (fileWithUsers.open(QIODevice::ReadOnly))
        {
            UserList userList;
            QDataStream stream(&fileWithUsers);

            stream >> userList;
            fileWithUsers.close();

            if ((userList.Data.isEmpty() || userList.Data[0] != User("ADMIN")) && fileWithUsers.open(QIODevice::WriteOnly))
            {
                QDataStream stream(&fileWithUsers);
                QList<User> ListOfUsers = QList<User>();
                ListOfUsers.append(User("ADMIN"));

                stream << ListOfUsers;
                fileWithUsers.close();
            }
        }
    }
}

// Getting user list from file
QList<User> FileService::GetUsersFromFile(QString fileName, QString passPhrase)
{
    QFile fileWithUsers = QFile(fileName);

    QList<User> outUserList = QList<User>();

    if (!fileWithUsers.exists())
    {
        qDebug() << "File not exist";
        return outUserList;
    }

    if (!fileWithUsers.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error when open file";
    }

    UserList userList;
    QDataStream stream(&fileWithUsers);

    stream >> userList;

    outUserList = userList.Data;
    fileWithUsers.close();

    // Test
    {
        if (fileWithUsers.open(QIODevice::ReadOnly))
        {
            qDebug() << "FileService::GetUsersFromFile";
            QDataStream stream(&fileWithUsers);
            UserList TestUserList = UserList();
            stream >> TestUserList;
            fileWithUsers.close();
            qDebug() << "Length" << TestUserList.Data.length();
            for (User user : TestUserList.Data)
            {
                qDebug() << user;
            }
        }
    }

    return outUserList;
}

User FileService::GetUserByName(QString name)
{
    QList<User> userList = GetUsersFromFile(SecurityManager().FILE_NAME_WITH_USERS, "");

    for (User user : userList)
    {
        if (user.Login == name)
        {
            return user;
        }
    }
    return User();
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

    // Test
    if (fileWithUsers.open(QIODevice::ReadOnly))
    {
        qDebug() << "FileService::SaveUsersToFile:";
        QDataStream stream(&fileWithUsers);
        QList<User> list = QList<User>();
        UserList userList = UserList(list);
        stream >> userList;
        fileWithUsers.close();
        qDebug() << "Length" << userList.Data.length();
        for (User user : userList.Data)
        {
            qDebug() << user;
        }
    }
}
