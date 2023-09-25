#include "formchangepassword.h"
#include "ui_formchangepassword.h"

FormChangePassword::FormChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormChangePassword)
{
    ui->setupUi(this);
}

FormChangePassword::~FormChangePassword()
{
    delete ui;
}
