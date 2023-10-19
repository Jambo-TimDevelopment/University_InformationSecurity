#include "passphrase.h"
#include <Utilities.h>
#include <QApplication>
#include <QFile>
#include <QLabel>
#include <UserList.h>
#include <User.h>
#include <qbytearray.h>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    SecurityManager securityManager = SecurityManager();
    QFile* tmpFile = new QFile(securityManager.TMP_FILE);
    QFile* fileWithUsers = new QFile(securityManager.FILE_NAME_WITH_USERS);
    fileWithUsers->remove();
    tmpFile->remove();

    PassPhrase pp;
    pp.show();

    int exitCode = a.exec();

    // TODO Decrypt file with users by pass phrase
    fileWithUsers->remove();
    tmpFile->remove();
    return exitCode;
}
