#ifndef FORMMAINWINDOWADMIN_H
#define FORMMAINWINDOWADMIN_H

#include <QMainWindow>

namespace Ui
{
    class FormMainWindowAdmin;
}

class FormMainWindowAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormMainWindowAdmin(QWidget* parent = nullptr);
    ~FormMainWindowAdmin();

private slots:
    void on_actionAbout_triggered();

    void on_actionLisst_of_users_triggered();

    void on_actionChange_pass_triggered();

private:
    Ui::FormMainWindowAdmin* ui;
};

#endif // FORMMAINWINDOWADMIN_H
