#include "formauthorisation.h"
#include "mainwindowadmin.h"
#include "formmainwindowclient.h"
#include "ui_formauthorisation.h"

FormAuthorisation::FormAuthorisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormAuthorisation)
{
    ui->setupUi(this);
}

FormAuthorisation::~FormAuthorisation()
{
    delete ui;
}

void FormAuthorisation::on_pushButton_enter_clicked()
{
    hide();

    if(ui->lineEdit_login->text() == "ADMIN")
    {
        MainWindowAdmin* mainWindowAdmin = new MainWindowAdmin(this);
        mainWindowAdmin->show();
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

