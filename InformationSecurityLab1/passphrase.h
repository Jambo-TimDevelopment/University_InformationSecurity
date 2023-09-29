#ifndef PASSPHRASE_H
#define PASSPHRASE_H
#pragma once
#include <QDialog>

class MainWindowAdmin;

namespace Ui
{
    class PassPhrase;
}

class PassPhrase : public QDialog
{
    Q_OBJECT

public:
    explicit PassPhrase(QWidget* parent = nullptr);
    ~PassPhrase();

private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::PassPhrase* ui;
};

#endif // PASSPHRASE_H
