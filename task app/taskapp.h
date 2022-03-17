#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_taskapp.h"

class taskapp : public QMainWindow
{
    Q_OBJECT

public:
    taskapp(QWidget *parent = Q_NULLPTR);

private:
    Ui::taskappClass ui;
};
