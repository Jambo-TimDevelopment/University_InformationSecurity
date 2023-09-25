#ifndef FORMMAINWINDOWCLIENT_H
#define FORMMAINWINDOWCLIENT_H

#include <QMainWindow>

namespace Ui {
class FormMainWindowClient;
}

class FormMainWindowClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormMainWindowClient(QWidget *parent = nullptr);
    ~FormMainWindowClient();

private slots:
    void on_actionAbout_triggered();

    void on_actionChange_pass_triggered();

private:
    Ui::FormMainWindowClient *ui;
};

#endif // FORMMAINWINDOWCLIENT_H
