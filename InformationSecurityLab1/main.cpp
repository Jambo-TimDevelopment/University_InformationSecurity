#include "passphrase.h"
#include <Utilities.h>
#include <QApplication>
#include <QFile>
#include <QLabel>
#include <UserList.h>
#include <User.h>
#include <qbytearray.h>
#include "qaesencryption.h"

const QString FILE_NAME_WITH_USERS = "C:/University/4Course/IS/FileWithUsers.dat";
const QString TMP_FILE = "C:/University/4Course/IS/tmpFile.txt";

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    SecurityManager securityManager = SecurityManager();

    QFile* tmpFile = new QFile(TMP_FILE);
    tmpFile->remove();

    QFile fileWithUsers(FILE_NAME_WITH_USERS);

    if (!fileWithUsers.exists(FILE_NAME_WITH_USERS))
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

    // Test
    {
        if (fileWithUsers.open(QIODevice::ReadOnly))
        {
            qDebug() << "\nmain test:";
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

        QByteArray block = fileWithUsers.readAll();
        QString passPhrase = "abc";
        QByteArray key;
        QString::fromUtf8(key);
        QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::CFB);
        QByteArray encodedText = encryption.encode(block, key);

        QByteArray decodedText = encryption.decode(encodedText, key);
    }

    PassPhrase pp;
    pp.show();

    int exitCode = a.exec();

    tmpFile->remove();
    return exitCode;
}
