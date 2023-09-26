#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <QString>



class UserService
{
public:
    UserService();

    bool IsAdmin(QString login) { return login == "ADMIN"; }

    QString SetNewPassword(QString plainPassword)
        {
        return "";
            //return Hash(plainPassword);
        }

    bool CheckPassword(QString password, QString oldPassword)
        {
            return false;
            //return Hash(oldPassword) == password;
        }

    public:
        bool VerifyPassword(QString password)
        {
            return false;
            //Regex regex = new Regex(@".*([A-zА-я]+).*|.*([-.?!,:()]+).*");
            //return regex.IsMatch(password);
        }

    private:
        QString Hash(QString password)
        {
            return "";
            //byte[] bytes = Encoding.ASCII.GetBytes(password);
            //byte[] hashBytes = DigestUtilities.CalculateDigest("MD5", bytes);
            //return Hex.ToHexString(hashBytes);
        }
};

#endif // USERSERVICE_H
