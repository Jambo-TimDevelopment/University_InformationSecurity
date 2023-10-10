#include "passphrase.h"
#include "Utilities.h"
#include "fileservice.h"
#include "formauthorisation.h"
#include "ui_passphrase.h"

#include <User.h>
#include <QMessageBox>
#include <qfile.h>

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

    if (!securityManager.USER_LIST.empty() && securityManager.USER_LIST[0].Login != "ADMIN")
    {
        QMessageBox::critical(this, "Not valid pass phrase or user file is empty", "Not valid pass phrase or user file is empty");
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
