#include "fileservice.h"

#include <QFile>
#include <QList>
#include <QMessageBox>

FileService::FileService() {}

// Getting user list from file
QList<User> FileService::GetUsersFromFile(QString fileName, QString passPhrase)
{
    QFile* fileWithUsers = new QFile(fileName);

    QList<User> userList = QList<User>();

    if (!fileWithUsers->exists())
    {
        qDebug() << "File not exist";
        return userList;
    }

    if (!fileWithUsers->open(QIODevice::ReadOnly))
    {
        qDebug() << "Error when open file";
    }

    QByteArray block = fileWithUsers->readAll();
    fileWithUsers->close();

    QString stringFromFile = QString::fromUtf8(block.toStdString().c_str());

    QStringList stringsWithUsers = stringFromFile.split("\n");
    for (QString userString : stringsWithUsers)
    {
        if (userString.isEmpty())
        {
            continue;
        }

        User* newUser = nullptr;
        QStringList userProperties = userString.split(" ");
        if (userProperties.length() > 1)
        {
            newUser = new User(userProperties[0], userProperties[1], userProperties[2] == "true", userProperties[3] == "true");
        }
        else if (userProperties.length() == 1)
        {
            newUser = new User(userProperties[0]);
        }

        if (newUser != nullptr)
        {
            userList.append(*newUser);
        }
    }

    return userList;
}

User FileService::GetUserByName(QString name)
{
    QList<User> userList = GetUsersFromFile(SecurityManager::FILE_NAME_WITH_USERS, "");

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
    QFile* fileWithUsers = new QFile(fileName);

    if (!fileWithUsers->exists())
    {
        qDebug() << "File not exist";
        return;
    }

    if (!fileWithUsers->open(QIODevice::WriteOnly))
    {
        qDebug() << "Error when open file";
    }

    // TODO make loading data to file
    QString str = FileService::ConverIserListToString(list);
    QTextStream writeStream(&*fileWithUsers);
    writeStream << str;
    fileWithUsers->close();
}

QString FileService::ConverIserListToString(QList<User> userList)
{
    QString outString = "";
    for (User user : userList)
    {
        outString += user.Login + " ";
        outString += user.EncryptedPassword + " ";
        outString += user.Blocked ? "true " : "flase ";
        outString += user.LimitPassword ? "true " : "flase ";
        outString += "\n";
    }
    return outString;
}
