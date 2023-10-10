#include "userlist.h"

QDataStream& operator>>(QDataStream& in, UserList& ul)
{
    int nrEntries;
    in >> nrEntries;
    for (int entry = 0; entry < nrEntries; ++entry)
    {
        User newEntry = User();
        in >> newEntry;
        ul.Data.append(newEntry);
    }
    return in;
}

QDataStream& operator<<(QDataStream& out, const UserList& ul)
{
    out << ul.Data.length() + 1;
    for (User entry : ul.Data)
    {
        out << &entry;
    }

    return out;
}
