#ifndef USERLIST_H
#define USERLIST_H

#include <User.h>
#include <qlist.h>

class UserList
{
public:
    UserList() { Data = QList<User>(); }
    UserList(QList<User> newData) { Data = newData; }
    QList<User> Data;

    friend QDataStream& operator>>(QDataStream& d, User& u);
};

#endif // USERLIST_H
