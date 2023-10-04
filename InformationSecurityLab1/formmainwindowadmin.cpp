#include "formmainwindowadmin.h"
#include "ui_formmainwindowadmin.h"

#include <FormAboutProgram.h>
#include <FormChangePassword.h>
#include <FormUserList.h>

FormMainWindowAdmin::FormMainWindowAdmin(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::FormMainWindowAdmin)
{
    ui->setupUi(this);
}

FormMainWindowAdmin::~FormMainWindowAdmin()
{
    delete ui;
}

void FormMainWindowAdmin::on_actionAbout_triggered()
{
    FormAboutProgram* formAboutProgram = new FormAboutProgram(this);
    formAboutProgram->setModal(true);
    formAboutProgram->show();
}

void FormMainWindowAdmin::on_actionLisst_of_users_triggered()
{
    FormUserList* formUserList = new FormUserList(this);
    formUserList->setModal(true);
    formUserList->show();
}

void FormMainWindowAdmin::on_actionChange_pass_triggered()
{
    FormChangePassword* formChangePass = new FormChangePassword(this);
    formChangePass->setModal(true);
    formChangePass->show();
}
