#ifndef FORMADDUSER_H
#define FORMADDUSER_H

#include <QDialog>

namespace Ui
{
    class FormAddUser;
}

class FormAddUser : public QDialog
{
    Q_OBJECT

public:
    explicit FormAddUser(QWidget* parent = nullptr);
    ~FormAddUser();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::FormAddUser* ui;
};

#endif // FORMADDUSER_H
