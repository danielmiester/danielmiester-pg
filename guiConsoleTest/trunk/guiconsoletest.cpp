#include "guiconsoletest.h"
#include "SerialWorkerThread.hpp"


guiConsoleTest::guiConsoleTest(QWidget *parent) :
	QMainWindow(parent),thread("/dev/ttyUSB0",300)
{
	ui.setupUi(this);


}

guiConsoleTest::~guiConsoleTest()
{
	thread.join();
}
void guiConsoleTest::setVisible(bool visible)
{

	QWidget::setVisible(visible);
	thread.start();

}


