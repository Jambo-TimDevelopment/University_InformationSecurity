#include "Utilities.h"

SecurityManager::SecurityManager()
{
    QFile* tmpFile = new QFile(TMP_FILE);

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
}

void SecurityManager::setUSER_NAME(const QString& newUSER_NAME)
{
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

void SecurityManager::setUSER_PASS(const QString& newUSER_PASS)
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

void SecurityManager::setPASS_PHRASE(const QString& newPASS_PHRASE)
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
