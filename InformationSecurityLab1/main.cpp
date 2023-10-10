#include "passphrase.h"
#include <Utilities.h>
#include <QApplication>
#include <QFile>
#include <QLabel>
#include <UserList.h>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    if (!QFile::exists(SecurityManager().FILE_NAME_WITH_USERS))
    {
        QFile fileWithUsers(SecurityManager().FILE_NAME_WITH_USERS);
        if (fileWithUsers.open(QIODevice::WriteOnly))
        {
            /*QDataStream stream(&fileWithUsers);
            QList<User>* list = new QList<User>();
            list->append(User("ADMIN"));
            UserList* userList = new UserList(*list);
            stream << userList;*/

            fileWithUsers.write("ADMIN");
            fileWithUsers.close();
        }
    }
    else
    {
        QFile fileWithUsers(SecurityManager().FILE_NAME_WITH_USERS);

        if (fileWithUsers.open(QIODevice::ReadWrite))
        {
            /*UserList* userList;
            QDataStream stream(&fileWithUsers);

            stream << userList;

            if (userList->Data.isEmpty())
            {
                QDataStream stream(&fileWithUsers);
                QList<User>* list = new QList<User>();
                list->append(User("ADMIN"));
                UserList* userList = new UserList(*list);
                stream << userList;

                // fileWithUsers.write("ADMIN");
                fileWithUsers.close();
            }*/

            QByteArray block = fileWithUsers.readAll();

            QString stringFromFile = QString::fromUtf8(block.toStdString().c_str());
            if (stringFromFile.isEmpty())
            {
                fileWithUsers.write("ADMIN");
                fileWithUsers.close();
            }
        }
    }

    PassPhrase pp;
    pp.show();

    int exitCode = a.exec();

    QFile* tmpFile = new QFile("C:/University/4Course/IS/tmpFile.txt");
    tmpFile->remove();

    return exitCode;
}
