/********************************************************************************
** Form generated from reading ui file 'guiconsoletest.ui'
**
** Created: Wed Feb 24 21:05:43 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GUICONSOLETEST_H
#define UI_GUICONSOLETEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiConsoleTestClass
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *guiConsoleTestClass)
    {
        if (guiConsoleTestClass->objectName().isEmpty())
            guiConsoleTestClass->setObjectName(QString::fromUtf8("guiConsoleTestClass"));
        guiConsoleTestClass->resize(800, 600);
        centralwidget = new QWidget(guiConsoleTestClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(23, 32, 611, 301));
        guiConsoleTestClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(guiConsoleTestClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        guiConsoleTestClass->setMenuBar(menubar);
        statusbar = new QStatusBar(guiConsoleTestClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        guiConsoleTestClass->setStatusBar(statusbar);

        retranslateUi(guiConsoleTestClass);

        QMetaObject::connectSlotsByName(guiConsoleTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *guiConsoleTestClass)
    {
        guiConsoleTestClass->setWindowTitle(QApplication::translate("guiConsoleTestClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("guiConsoleTestClass", "HelloWorld", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(guiConsoleTestClass);
    } // retranslateUi

};

namespace Ui {
    class guiConsoleTestClass: public Ui_guiConsoleTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUICONSOLETEST_H
