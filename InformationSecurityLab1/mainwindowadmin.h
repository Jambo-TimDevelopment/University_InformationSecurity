#ifndef MAINWINDOWADMIN_H
#define MAINWINDOWADMIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindowAdmin : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowAdmin(QWidget *parent = nullptr);
    ~MainWindowAdmin();

private slots:
    void on_pushButton_submit_clicked();

    void on_actionAbout_triggered();

    void on_actionList_of_users_triggered();

    void on_actionChange_pass_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOWADMIN_H
