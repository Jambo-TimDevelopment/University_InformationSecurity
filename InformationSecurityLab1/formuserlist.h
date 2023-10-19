#ifndef FORMUSERLIST_H
#define FORMUSERLIST_H
#pragma once
#include "Utilities.h"

#include <QDialog>
#include <User.h>

namespace Ui
{
    class FormUserList;
}

class FormUserList : public QDialog
{
    Q_OBJECT

public:
    explicit FormUserList(QWidget* parent = nullptr);
    ~FormUserList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormUserList* ui;

    void UpdateUserList();
};

#endif // FORMUSERLIST_H
