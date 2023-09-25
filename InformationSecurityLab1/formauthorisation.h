#ifndef FORMAUTHORISATION_H
#define FORMAUTHORISATION_H

#include <QDialog>

namespace Ui {
class FormAuthorisation;
}

class FormAuthorisation : public QDialog
{
    Q_OBJECT

public:
    explicit FormAuthorisation(QWidget *parent = nullptr);
    ~FormAuthorisation();

private slots:
    void on_pushButton_enter_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::FormAuthorisation *ui;
};

#endif // FORMAUTHORISATION_H
