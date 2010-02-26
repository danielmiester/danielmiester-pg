#ifndef GUICONSOLETEST_H
#define GUICONSOLETEST_H

#include <QtGui/QMainWindow>
#include "ui_guiconsoletest.h"
#include "SerialWorkerThread.hpp"

class guiConsoleTest : public QMainWindow
{
    Q_OBJECT

public:
    guiConsoleTest(QWidget *parent = 0);
    ~guiConsoleTest();
public Q_SLOTS:
    void setVisible(bool visible);

private:
    Ui::guiConsoleTestClass ui;
    SerialWorkerThread thread;
};

#endif // GUICONSOLETEST_H
