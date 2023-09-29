#ifndef FORMAUTHORISATION_H
#define FORMAUTHORISATION_H
#pragma once
#include <QDialog>

namespace Ui
{
    class FormAuthorisation;
}

class FormAuthorisation : public QDialog
{
    Q_OBJECT

public:
    explicit FormAuthorisation(QWidget* parent = nullptr);
    ~FormAuthorisation();

private slots:
    void on_pushButton_enter_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::FormAuthorisation* ui;

    int CountOfAttempts = 0;
};

#endif // FORMAUTHORISATION_H
