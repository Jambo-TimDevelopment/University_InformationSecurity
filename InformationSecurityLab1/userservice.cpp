#include "userservice.h"
#include "Utilities.h"
#include "fileservice.h"

#include <QCryptographicHash>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

bool UserService::SetNewPassword(QString newPassword)
{
    bool flag;
    SecurityManager* securityManager = new SecurityManager();
    QList<User> newUserList = QList<User>(securityManager->USER_LIST.length());
    int k = 0;
    for (User user : securityManager->USER_LIST)
    {
        newUserList[k].Login = user.Login;
        newUserList[k].EncryptedPassword = user.EncryptedPassword;
        newUserList[k].Blocked = user.Blocked;
        newUserList[k].LimitPassword = user.LimitPassword;

        if (user.Login == securityManager->USER_NAME)
        {
            newUserList[k].EncryptedPassword = UserService::Hash(newPassword);
            flag = true;
        }
        k++;
    }

    FileService::SaveUsersToFile(SecurityManager().FILE_NAME_WITH_USERS, newUserList, securityManager->PASS_PHRASE);

    return flag;
}

bool UserService::CheckPassword(QString password, QString oldPassword)
{
    QString hashOfEnterdPass = UserService::Hash(password);
    return hashOfEnterdPass == oldPassword;
}

bool UserService::VerifyPassword(QString password)
{
    // Regex(@".*([A-zА-я]+).*|.*([0-9]+).*");
    QRegularExpression re(R".*(^[A-Za-z0-9]+$).*");
    QRegularExpressionMatch match = re.match(password);
    return match.hasMatch(); // true
}

QString UserService::Hash(QString password)
{
    const QByteArray byteArray = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Algorithm::Md4);
    return QString::fromUtf8(byteArray);
}
