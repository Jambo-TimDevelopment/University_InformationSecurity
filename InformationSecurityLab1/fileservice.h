#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <QString>

/**
 *  QCryptographicHash Class
 *  https://doc.qt.io/qt-5/qcryptographichash.html
 */

class FileService
{
public:
    FileService();

private: QString userFilename = "users.dat";
/*public List<User> LoadUsersFile(string passPhrase)
    {
        List<User> list = new List<User>();
        if (File.Exists(userFilename))
        {
            byte[] encryptedBytes = File.ReadAllBytes(userFilename);
            byte[] bytes = DecodeData(encryptedBytes, passPhrase);
            list = DeserializeUserList(bytes);
        }
        else
        {
            // При отсутствии файла с пользователями
            User admin = new User
                {
                    Login = "ADMIN"
                };
            list.Add(admin);
        }
        return list;
    }

public void SaveUsersFile(List<User> list, string passPhrase)
    {
        byte[] bytes = SerializeUserList(list);
        byte[] encryptedBytes = EncodeData(bytes, passPhrase);
        File.WriteAllBytes(userFilename, encryptedBytes);
    }

private byte[] SerializeUserList(List<User> list)
    {
        XmlSerializer bf = new XmlSerializer(list.GetType());
        MemoryStream ms = new MemoryStream();
        StreamWriter sw = new StreamWriter(ms, Encoding.UTF8);
        bf.Serialize(sw, list);
        sw.Flush();
        return ms.ToArray();
    }

private List<User> DeserializeUserList(byte[] bytes)
    {
        XmlSerializer bf = new XmlSerializer(new List<User>().GetType());
        MemoryStream ms = new MemoryStream(bytes);
        return (List<User>)bf.Deserialize(ms);
    }
private byte[] EncodeData(byte[] bytes, string passPhrase)
    {
        DES provider = CreateDESProvider(passPhrase);
        ICryptoTransform transform = provider.CreateEncryptor();

        MemoryStream encryptedStream = new MemoryStream();
        CryptoStream cryptoStream = new CryptoStream(encryptedStream, transform, CryptoStreamMode.Write);
        cryptoStream.Write(bytes, 0, bytes.Length);
        cryptoStream.FlushFinalBlock();
        return encryptedStream.ToArray();
    }

private byte[] DecodeData(byte[] encryptedBytes, string passPhrase)
    {
        DES provider = CreateDESProvider(passPhrase);
        ICryptoTransform transform = provider.CreateDecryptor();

        MemoryStream decryptedStream = new MemoryStream();
        CryptoStream cryptoStream = new CryptoStream(decryptedStream, transform, CryptoStreamMode.Write);
        cryptoStream.Write(encryptedBytes, 0, encryptedBytes.Length);
        cryptoStream.FlushFinalBlock();
        return decryptedStream.ToArray();
    }

private DES CreateDESProvider(string passPhrase)
    {
        // Генерируем ключ из пароля при помощи алгоритма PBKDF2
        byte[] salt = new byte[] { 15, 93, 51, 19, 2, 76, 142, 13 };
        Rfc2898DeriveBytes keyGenerator = new Rfc2898DeriveBytes(passPhrase, salt, 1000);
        byte[] key = keyGenerator.GetBytes(8);
        byte[] iv = keyGenerator.GetBytes(8);
        // Устанавливаем параметры алгоритма DES
        DES provider = DES.Create();
        provider.Mode = CipherMode.CFB;
        provider.FeedbackSize = 8;
        provider.Key = key;
        // Случайное значение
        provider.IV = iv;
        return provider;
    }*/
};

#endif // FILESERVICE_H
