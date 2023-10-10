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
    SecurityManager()
    {
        QFile* tmpFile = new QFile(TMP_FILE);

        // QList<User> userList = QList<User>();

        if (!tmpFile->exists())
        {
            tmpFile->open(QIODevice::WriteOnly);
            tmpFile->close();

            qDebug() << "File tmp not exist";
            return;
        }

        if (!tmpFile->open(QIODevice::ReadOnly))
        {
            qDebug() << "Error when open tmp file";
            return;
        }

        QByteArray block = tmpFile->readAll();
        tmpFile->close();

        QString stringFromFile = QString::fromUtf8(block.toStdString().c_str());

        QStringList stringsWithTmpData = stringFromFile.split(" ");

        if (!stringsWithTmpData[0].isEmpty())
        {
            PASS_PHRASE = stringsWithTmpData[0];
        }

        if (stringsWithTmpData.length() > 1 && !stringsWithTmpData[1].isEmpty())
        {
            USER_NAME = stringsWithTmpData[1];
        }

        if (stringsWithTmpData.length() > 2 && !stringsWithTmpData[2].isEmpty())
        {
            USER_PASS = stringsWithTmpData[2];
        }

        if (stringsWithTmpData.length() > 3 && !stringsWithTmpData[3].isEmpty())
        {
            MIN_PASS_LENGTH = stringsWithTmpData[3].toInt();
        }

        if (stringsWithTmpData.length() > 4 && !stringsWithTmpData[4].isEmpty())
        {
            MIN_PASS_TIMEOUT = stringsWithTmpData[4].toInt();
        }

        USER_LIST = FileService::GetUsersFromFile(FILE_NAME_WITH_USERS, "");
    }

    const QString FILE_NAME_WITH_USERS = "C:/University/4Course/IS/FileWithUsers.dat";
    const QString TMP_FILE = "C:/University/4Course/IS/tmpFile.txt";

    QString PASS_PHRASE; // 0
    QString USER_NAME;   // 1
    QString USER_PASS;   // 2

    int MIN_PASS_LENGTH;  // 3
    int MIN_PASS_TIMEOUT; // 4

    QList</*&*/ User> USER_LIST; // 5

    void setPASS_PHRASE(const QString& newPASS_PHRASE);
    void setUSER_NAME(const QString& newUSER_NAME);
    void setUSER_PASS(const QString& newUSER_PASS);
};

inline void SecurityManager::setUSER_NAME(const QString& newUSER_NAME)
{
    // TODO Open tmp file
    // read data

    QFile* tmpFile = new QFile("C:/University/4Course/IS/tmpFile.txt");

    // QList<User> userList = QList<User>();

    if (!tmpFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "Error when open tmp file";
        return;
    }

    QByteArray block = tmpFile->readAll();
    tmpFile->close();

    tmpFile->remove();

    tmpFile->open(QIODevice::WriteOnly);
    QString stringFromFile = QString::fromUtf8(block.toStdString().c_str());

    QStringList stringsWithTmpData = stringFromFile.split(" ");

    // change data
    if (stringsWithTmpData.length() < 2)
    {
        stringsWithTmpData.append(newUSER_NAME);
    }

    // write data to file
    QTextStream writeStream(&*tmpFile);
    int index = 0;
    for (QString data : stringsWithTmpData)
    {
        if (index == 1)
        {
            writeStream << newUSER_NAME + " ";
        }
        else
        {
            writeStream << data + " ";
        }
        index++;
    }
    tmpFile->close();
}

inline void SecurityManager::setUSER_PASS(const QString& newUSER_PASS)
{
    USER_PASS = newUSER_PASS;

    // TODO Open tmp file
    // read data

    QFile* tmpFile = new QFile("C:/University/4Course/IS/tmpFile.txt");

    if (!tmpFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "Error when open tmp file";
        return;
    }

    QByteArray block = tmpFile->readAll();
    tmpFile->close();

    tmpFile->remove();

    tmpFile->open(QIODevice::WriteOnly);
    QString stringFromFile = QString::fromUtf8(block.toStdString().c_str());

    QStringList stringsWithTmpData = stringFromFile.split(" ");

    // change data
    if (stringsWithTmpData.length() < 3)
    {
        stringsWithTmpData.append(newUSER_PASS);
    }

    // write data to file
    QTextStream writeStream(&*tmpFile);
    int index = 0;
    for (QString data : stringsWithTmpData)
    {
        if (index == 2)
        {
            writeStream << newUSER_PASS + " ";
        }
        else
        {
            writeStream << data + " ";
        }
        index++;
    }
    tmpFile->close();
}

inline void SecurityManager::setPASS_PHRASE(const QString& newPASS_PHRASE)
{
    // TODO Open tmp file
    // read data

    QFile* tmpFile = new QFile("C:/University/4Course/IS/tmpFile.txt");

    // QList<User> userList = QList<User>();

    if (!tmpFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "Error when open tmp file";
        return;
    }

    QByteArray block = tmpFile->readAll();
    tmpFile->close();

    tmpFile->remove();

    tmpFile->open(QIODevice::WriteOnly);
    QString stringFromFile = QString::fromUtf8(block.toStdString().c_str());

    QStringList stringsWithTmpData = stringFromFile.split(" ");

    // change data

    // write data to file
    QTextStream writeStream(&*tmpFile);
    int index = 0;
    for (QString data : stringsWithTmpData)
    {
        if (index == 0)
        {
            writeStream << newPASS_PHRASE + " ";
        }
        else
        {
            writeStream << data + " ";
        }
        index++;
    }
    tmpFile->close();
}
#endif // UTILITIES_H
