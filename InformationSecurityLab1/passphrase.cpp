#include "passphrase.h"
#include "Utilities.h"
#include "fileservice.h"
#include "formauthorisation.h"
#include "ui_passphrase.h"

#include <User.h>
#include <QMessageBox>
#include <qfile.h>
#include <UserList.h>
#include <QAESEncryption.h>

PassPhrase::PassPhrase(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::PassPhrase)
{
    ui->setupUi(this);
    setWindowTitle("Enter pass phrase");
}

PassPhrase::~PassPhrase()
{
    delete ui;
}

void PassPhrase::on_pushButton_submit_clicked()
{
    SecurityManager securityManager = SecurityManager();
    securityManager.setPASS_PHRASE(ui->line_pass_phrase->text());

    FileService::DecryptFile(securityManager.FILE_NAME_WITH_USERS, ui->line_pass_phrase->text());

    FileService::SetupUserListFile(ui->line_pass_phrase->text());

    User adminUser;
    if (!FileService::FindUserByName("ADMIN", adminUser))
    {
        QMessageBox::critical(this, "Not valid pass phrase or user file is empty", "Not valid pass phrase or user file is empty");
        return;
    }

    hide();

    FormAuthorisation* formAutorisation = new FormAuthorisation(this);
    formAutorisation->show();

    /*QList<User> listOfUsers;
    listOfUsers.append(User("ADMIN"));
    listOfUsers.append(User("User1"));
    listOfUsers.append(User("User2"));
    listOfUsers.append(User("User3"));
    FileService::SaveUsersToFile(securityManager.FILE_NAME_WITH_USERS, listOfUsers, ui->line_pass_phrase->text());*/
}

void PassPhrase::on_pushButton_cancel_clicked()
{
    hide();
}
