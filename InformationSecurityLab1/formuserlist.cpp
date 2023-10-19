#include "Utilities.h"
#include "formuserlist.h"
#include "ui_formuserlist.h"

#include <FormAddUser.h>
#include <QStringListModel>
#include <User.h>
#include <qmessagebox.h>

void FormUserList::UpdateUserList()
{
    SecurityManager* securityManager = new SecurityManager();
    QList<User> userList = FileService::GetUsersFromFile(securityManager->FILE_NAME_WITH_USERS, "");

    ui->tableWidget->setRowCount(userList.length());
    for (int i = 0; i < userList.length(); i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(userList[i].Login));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(userList[i].EncryptedPassword));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(userList[i].Blocked ? "true" : "false"));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(userList[i].LimitPassword ? "true" : "false"));
    }
}

FormUserList::FormUserList(QWidget* parent)
    : QDialog(parent), ui(new Ui::FormUserList)
{
    ui->setupUi(this);

    UpdateUserList();
}

FormUserList::~FormUserList()
{
    delete ui;
}

void FormUserList::on_pushButton_clicked()
{
    FormAddUser* formAddUser = new FormAddUser(this);
    formAddUser->show();

    UpdateUserList();
}
