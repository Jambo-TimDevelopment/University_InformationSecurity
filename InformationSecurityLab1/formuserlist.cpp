#include "Utilities.h"
#include "formuserlist.h"
#include "ui_formuserlist.h"

#include <qmessagebox.h>

FormUserList::FormUserList(QWidget* parent)
    : QDialog(parent), ui(new Ui::FormUserList)
{
    ui->setupUi(this);
}

FormUserList::~FormUserList()
{
    delete ui;
}

void FormUserList::on_pushButton_clicked()
{
    QList<User> userList = FileService::GetUsersFromFile(SecurityManager().FILE_NAME_WITH_USERS, "");
    User newUser = User(ui->lineEdit->text());
    if (userList.contains(newUser))
    {
        QMessageBox::critical(this, "Not unique name", "Not unique name");
        return;
    }
    userList.push_back(newUser);
    FileService::SaveUsersToFile(SecurityManager().FILE_NAME_WITH_USERS, userList, "");
}
