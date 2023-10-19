#include "userservice.h"
#include "Utilities.h"

#include <QCryptographicHash>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <User.h>

bool UserService::SetNewPassword(QString newPassword)
{
    bool flag = false;
    SecurityManager securityManager = SecurityManager();
    QList<User> newUserList = FileService::GetUsersFromFile(securityManager.FILE_NAME_WITH_USERS, securityManager.PASS_PHRASE);
    for (User& user : newUserList)
    {
        if (user.Login == securityManager.USER_NAME)
        {
            user.EncryptedPassword = UserService::Hash(newPassword);
            flag = true;
        }
    }

    FileService::SaveUsersToFile(securityManager.FILE_NAME_WITH_USERS, newUserList, securityManager.PASS_PHRASE);

    return flag;
}

bool UserService::CheckPassword(QString password, QString oldPassword)
{
    QString hashOfEnterdPass = UserService::Hash(password);
    return hashOfEnterdPass == oldPassword;
}

bool UserService::VerifyPassword(QString password)
{
    static QRegularExpression re(R".*(^[A-Za-z0-9]+$).*");
    QRegularExpressionMatch match = re.match(password);
    return match.hasMatch();
}

QString UserService::Hash(QString password)
{
    const QByteArray byteArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Algorithm::Md4);
    return QString::fromUtf8(byteArray);
}
