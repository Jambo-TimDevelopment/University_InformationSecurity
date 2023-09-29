#ifndef FORMCHANGEPASSWORD_H
#define FORMCHANGEPASSWORD_H
#pragma once
#include <QDialog>

namespace Ui
{
    class FormChangePassword;
}

class FormChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit FormChangePassword(QWidget* parent = nullptr);
    ~FormChangePassword();

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::FormChangePassword* ui;
};

#endif // FORMCHANGEPASSWORD_H
