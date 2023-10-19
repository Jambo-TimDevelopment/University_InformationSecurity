#include "Utilities.h"
#include "formadduser.h"
#include "ui_formadduser.h"

#include <FileService.h>
#include <User.h>
#include <QMessageBox>

FormAddUser::FormAddUser(QWidget* parent)
    : QDialog(parent), ui(new Ui::FormAddUser)
{
    ui->setupUi(this);
}

FormAddUser::~FormAddUser()
{
    delete ui;
}

void FormAddUser::on_buttonBox_accepted()
{
    if (ui->checkBox_requirePass->isDown() && !UserService::VerifyPassword(ui->lineEdit_pass->text()))
    {
        QMessageBox::critical(this, "Unsuitable password", "Unsuitable password");
    }

    User newUser = User(ui->lineEdit_login->text(), UserService::Hash(ui->lineEdit_pass->text()), ui->checkBox_userIsBlocked->isDown(), ui->checkBox_requirePass->isDown());
    SecurityManager* securityManager = new SecurityManager();
    QList<User> userList = FileService::GetUsersFromFile_Internal(securityManager->FILE_NAME_WITH_USERS);
    if (userList.contains(newUser))
    {
        QMessageBox::critical(this, "Not unique name", "Not unique name");
        return;
    }
    userList.push_back(newUser);
    FileService::SaveUsersToFile(securityManager->FILE_NAME_WITH_USERS, userList, securityManager->PASS_PHRASE);
    hide();
}

void FormAddUser::on_buttonBox_rejected()
{
    hide();
}
