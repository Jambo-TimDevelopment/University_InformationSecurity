#include "formauthorisation.h"
#include "Utilities.h"
#include "formmainwindowclient.h"
#include "formmainwindowadmin.h"
#include "ui_formauthorisation.h"
#include "userservice.h"

#include <User.h>
#include <FileService.h>
#include <QMessageBox>

FormAuthorisation::FormAuthorisation(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FormAuthorisation)
{
    ui->setupUi(this);
}

FormAuthorisation::~FormAuthorisation()
{
    delete ui;
}

void FormAuthorisation::on_pushButton_enter_clicked()
{
    // TODO load users from file and get user pass by user name, chek pass
    SecurityManager* securityManager = new SecurityManager();
    User foundUser;

    if (!FileService::FindUserByName(ui->lineEdit_login->text(), foundUser))
    {
        QMessageBox::critical(this, "User is blocked", "User" + ui->lineEdit_login->text() + "is blocked");
        return;
    }

    if (!UserService::CheckPassword(ui->lineEdit_pass->text(), foundUser.EncryptedPassword)
        && !foundUser.EncryptedPassword.isEmpty())
    {
        QMessageBox::critical(this, "Not valid pass", "Not valid pass");
        return;
    }

    securityManager->setUSER_NAME(ui->lineEdit_login->text());
    securityManager->setUSER_PASS(ui->lineEdit_pass->text());

    hide();

    if (UserService::IsAdmin(ui->lineEdit_login->text()))
    {
        FormMainWindowAdmin* formMainWindowAdmin = new FormMainWindowAdmin(this);
        formMainWindowAdmin->show();
        return;
    }

    FormMainWindowClient* mainWindowClient = new FormMainWindowClient(this);
    mainWindowClient->show();
    return;
}

void FormAuthorisation::on_pushButton_cancel_clicked()
{
    hide();
}
