#include "userservice.h"
#include "Utilities.h"
#include "fileservice.h"

#include <QCryptographicHash>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

bool UserService::SetNewPassword(QString newPassword)
{
    for (User user : SecurityManager::USER_LIST)
    {
        if (user.Login == SecurityManager::USER_NAME)
        {
            user.EncryptedPassword = UserService::Hash(newPassword);
            // TODO Save changed user list to file
            FileService::SaveUsersToFile(SecurityManager::FILE_NAME_WITH_USERS, SecurityManager::USER_LIST, SecurityManager::PASS_PHRASE);
            return true;
        }
    }

    return false;
}

bool UserService::CheckPassword(QString password, QString oldPassword)
{
    return UserService::Hash(password) == oldPassword;
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
