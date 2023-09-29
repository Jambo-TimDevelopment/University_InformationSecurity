#ifndef FORMABOUTPROGRAM_H
#define FORMABOUTPROGRAM_H
#pragma once
#include <QDialog>

namespace Ui
{
    class FormAboutProgram;
}

class FormAboutProgram : public QDialog
{
    Q_OBJECT

public:
    explicit FormAboutProgram(QWidget* parent = nullptr);
    ~FormAboutProgram();

private:
    Ui::FormAboutProgram* ui;
};

#endif // FORMABOUTPROGRAM_H
