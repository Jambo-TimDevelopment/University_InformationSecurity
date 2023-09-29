#include "mainwindowadmin.h"
#include "ui_mainwindow.h"
#include "formaboutprogram.h"
#include "formchangepassword.h"
#include "formuserlist.h"
#include <QDebug>

MainWindowAdmin::MainWindowAdmin(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("IS Lab1");
    // setStyleSheet("background-color: green");
}

MainWindowAdmin::~MainWindowAdmin()
{
    delete ui;
}

void MainWindowAdmin::on_pushButton_submit_clicked()
{
    qDebug() << "Submiting data..";
    // qDebug() << "Pass phrase is: " << ui->line_pass->text();
}

void MainWindowAdmin::on_actionAbout_triggered()
{
    FormAboutProgram* formAboutProgram = new FormAboutProgram(this);
    formAboutProgram->setModal(true);
    formAboutProgram->show();
}

void MainWindowAdmin::on_actionList_of_users_triggered()
{
    FormUserList* formUserList = new FormUserList(this);
    formUserList->setModal(true);
    formUserList->show();
}

void MainWindowAdmin::on_actionChange_pass_triggered()
{
    FormChangePassword* formChangePass = new FormChangePassword(this);
    formChangePass->setModal(true);
    formChangePass->show();
}
