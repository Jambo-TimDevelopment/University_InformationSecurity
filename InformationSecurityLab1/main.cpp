#include "passphrase.h"
#include <Utilities.h>
#include <QApplication>
#include <QFile>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    if (!QFile::exists(SecurityManager::FILE_NAME_WITH_USERS))
    {
        QFile fileWithUsers(SecurityManager::FILE_NAME_WITH_USERS);
        if (fileWithUsers.open(QIODevice::WriteOnly))
        {
            fileWithUsers.write("ADMIN");
            fileWithUsers.close();
        }
    }

    PassPhrase pp;
    pp.show();
    return a.exec();
}
