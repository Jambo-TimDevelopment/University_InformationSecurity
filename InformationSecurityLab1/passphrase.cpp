#include "passphrase.h"
#include "ui_passphrase.h"
#include "formauthorisation.h"
#include <QMessageBox>


PassPhrase::PassPhrase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassPhrase)
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

    if(ui->line_pass->text() != "1")
    {
        QMessageBox::critical(this, "Not valid pass phrase", "Not valid pass phrase");
        return;
    }

    hide();

    FormAuthorisation* formAutorisation = new FormAuthorisation(this);
    formAutorisation->show();
}


void PassPhrase::on_pushButton_cancel_clicked()
{
    hide();
}

