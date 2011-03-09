#-------------------------------------------------
#
# Project created by QtCreator 2011-02-18T12:03:46
#
#-------------------------------------------------

QT += core gui

CONFIG += qdbus

TARGET = satk
TEMPLATE = app
target.path=/usr/local/bin
INSTALLS=target


SOURCES += main.cpp \
    stkmessage.cpp \
    stkyesno.cpp \
    stkpopup.cpp \
    stkinputkey.cpp \
    stkinputtext.cpp \
    stkmenu.cpp \
    stkif.cpp \
    stkagentifadaptor.cpp \
    mgrif.cpp \
    stkagentservice.cpp \
    stkwidget.cpp \
    stkdialog.cpp \
    stkmainwindow.cpp \
    stkofonoutils.cpp \
    stkofonoproperties.cpp

HEADERS += \
    stkmessage.h \
    stkyesno.h \
    stkpopup.h \
    stkinputkey.h \
    stkinputtext.h \
    stkmenu.h \
    stkif.h \
    stkagentifadaptor.h \
    mgrif.h \
    ofonodbustypes.h \
    stkagentservice.h \
    stkwidget.h \
    stkdialog.h \
    stkdefines.h \
    stkmainwindow.h \
    stkofonoutils.h \
    stkofonoproperties.h

OTHER_FILES += \
    ../interfaces/org.ofono.SimToolkit.xml \
    ../interfaces/org.ofono.SimToolkitAgent.xml \
    ../interfaces/org.ofono.Manager.xml \
    qtc_packaging/meego.spec
