#ifndef FORMUSERLIST_H
#define FORMUSERLIST_H

#include <QDialog>

namespace Ui {
class FormUserList;
}

class FormUserList : public QDialog
{
    Q_OBJECT

public:
    explicit FormUserList(QWidget *parent = nullptr);
    ~FormUserList();

private:
    Ui::FormUserList *ui;
};

#endif // FORMUSERLIST_H
