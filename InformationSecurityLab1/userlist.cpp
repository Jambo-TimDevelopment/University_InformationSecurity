#include "userlist.h"

// Export
QDataStream& operator<<(QDataStream& out, const UserList& ul)
{
    out << ul.Data.length();
    for (User entry : ul.Data)
    {
        out << &entry;
    }

    return out;
}

// Import
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
