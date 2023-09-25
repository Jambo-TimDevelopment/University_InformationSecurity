#include "formaboutprogram.h"
#include "ui_formaboutprogram.h"

FormAboutProgram::FormAboutProgram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormAboutProgram)
{
    ui->setupUi(this);
}

FormAboutProgram::~FormAboutProgram()
{
    delete ui;
}
