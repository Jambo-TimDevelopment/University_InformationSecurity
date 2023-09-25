#ifndef FORMCHANGEPASSWORD_H
#define FORMCHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class FormChangePassword;
}

class FormChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit FormChangePassword(QWidget *parent = nullptr);
    ~FormChangePassword();

private:
    Ui::FormChangePassword *ui;
};

#endif // FORMCHANGEPASSWORD_H
