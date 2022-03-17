/********************************************************************************
** Form generated from reading UI file 'taskapp.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKAPP_H
#define UI_TASKAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taskappClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *taskappClass)
    {
        if (taskappClass->objectName().isEmpty())
            taskappClass->setObjectName(QString::fromUtf8("taskappClass"));
        taskappClass->resize(600, 400);
        menuBar = new QMenuBar(taskappClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        taskappClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(taskappClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        taskappClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(taskappClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        taskappClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(taskappClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        taskappClass->setStatusBar(statusBar);

        retranslateUi(taskappClass);

        QMetaObject::connectSlotsByName(taskappClass);
    } // setupUi

    void retranslateUi(QMainWindow *taskappClass)
    {
        taskappClass->setWindowTitle(QCoreApplication::translate("taskappClass", "taskapp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taskappClass: public Ui_taskappClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKAPP_H
