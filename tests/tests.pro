#-------------------------------------------------
#
# Project created by QtCreator 2017-08-03T14:35:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tests
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = ../../qt_custom_set/bin

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lqt_custom_set
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lqt_custom_set
else:unix: LIBS += -L$$PWD/../lib/ -lqt_custom_set

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/release/libqt_custom_set.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/debug/libqt_custom_set.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/release/qt_custom_set.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/debug/qt_custom_set.lib
else:unix: PRE_TARGETDEPS += $$PWD/../lib/libqt_custom_set.a

HEADERS += \
    xswitch/xswitch.hpp
