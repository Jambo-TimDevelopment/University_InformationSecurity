#include "formuserlist.h"
#include "ui_formuserlist.h"

FormUserList::FormUserList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormUserList)
{
    ui->setupUi(this);
}

FormUserList::~FormUserList()
{
    delete ui;
}

void FormUserList::on_pushButton_AddNewUser_clicked()
{

}

