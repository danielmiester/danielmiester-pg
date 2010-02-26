TEMPLATE = app
TARGET = guiConsoleTest
QT += core \
    gui
HEADERS += SerialWorkerThread.hpp \
    minicom.hpp \
    guiconsoletest.h
SOURCES += SerialWorkerThread.cpp \
    main.cpp \
    guiconsoletest.cpp \
    minicom.cpp
FORMS += guiconsoletest.ui
RESOURCES += 
LIBS += -lboost_system \
    -lboost_thread
