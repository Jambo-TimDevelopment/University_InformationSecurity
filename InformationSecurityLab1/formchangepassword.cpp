#include "formchangepassword.h"
#include "ui_formchangepassword.h"
#include "userservice.h"

#include <FileService.h>
#include <User.h>
#include <qmessagebox.h>

FormChangePassword::FormChangePassword(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FormChangePassword)
{
    ui->setupUi(this);
}

FormChangePassword::~FormChangePassword()
{
    delete ui;
}

void FormChangePassword::on_pushButton_save_clicked()
{
    User foundUser;

    if (!FileService::FindUserByName(ui->lineEdit_user->text(), foundUser))
    {
        QMessageBox::critical(this, "Invalid user name", "Invalid user name");
        return;
    }

    if (!UserService::CheckPassword(ui->lineEdit_oldPass->text(), foundUser.EncryptedPassword)
        && !foundUser.EncryptedPassword.isEmpty())
    {
        QMessageBox::critical(this, "Not valid pass", "Not valid pass");
        return;
    }

    if (!UserService::VerifyPassword(ui->lineEdit_newPass->text()))
    {
        QMessageBox::warning(this, "Not valid pass", "Use only alphabet and digint");
        return;
    }

    if (UserService::SetNewPassword(ui->lineEdit_newPass->text()))
    {
        QMessageBox::information(this, "Pass changed", "Pass changed");
    }
}
