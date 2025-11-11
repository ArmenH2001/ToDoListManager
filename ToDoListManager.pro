QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CommandFactory.cpp \
    CommandParser.cpp \
    Commands.cpp \
    TaskItemWidget.cpp \
    TaskListDisplay.cpp \
    ToDoListManagerController.cpp \
    ToDoListManagerModel.cpp \
    ToDoListManagerViewWidget.cpp \
    main.cpp

HEADERS += \
    CommandFactory.h \
    CommandParser.h \
    Commands.h \
    ICommand.hpp \
    Task.hpp \
    TaskItemWidget.h \
    TaskListDisplay.h \
    ToDoListManagerController.h \
    ToDoListManagerModel.h \
    ToDoListManagerViewWidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
