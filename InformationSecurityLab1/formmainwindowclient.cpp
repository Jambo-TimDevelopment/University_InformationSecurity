#include "formmainwindowclient.h"
#include "formaboutprogram.h"
#include "formchangepassword.h"
#include "ui_formmainwindowclient.h"

FormMainWindowClient::FormMainWindowClient(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::FormMainWindowClient)
{
    ui->setupUi(this);
}

FormMainWindowClient::~FormMainWindowClient()
{
    delete ui;
}

void FormMainWindowClient::on_actionAbout_triggered()
{
    FormAboutProgram* formAboutProgram = new FormAboutProgram(this);
    formAboutProgram->setModal(true);
    formAboutProgram->show();
}

void FormMainWindowClient::on_actionChange_pass_triggered()
{
    FormChangePassword* formChangePass = new FormChangePassword(this);
    formChangePass->setModal(true);
    formChangePass->show();
}
