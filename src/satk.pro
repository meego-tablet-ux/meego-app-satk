#-------------------------------------------------
#
# Project created by QtCreator 2011-02-18T12:03:46
#
#-------------------------------------------------

QT += core gui declarative

CONFIG += qdbus

TARGET = satk
TEMPLATE = app
target.path=/usr/local/bin
INSTALLS=target


SOURCES += main.cpp \
    stkif.cpp \
    stkagentifadaptor.cpp \
    mgrif.cpp \
    stkagentservice.cpp \
    stkdialog.cpp \
    stkmainwindow.cpp \
    stkofonoutils.cpp \
    stkofonoproperties.cpp \
    stkmenumodel.cpp \
    stkmenuitem.cpp \
    simif.cpp \
    simimageprovider.cpp

HEADERS += \
    stkif.h \
    stkagentifadaptor.h \
    mgrif.h \
    ofonodbustypes.h \
    stkagentservice.h \
    stkdialog.h \
    stkdefines.h \
    stkmainwindow.h \
    stkofonoutils.h \
    stkofonoproperties.h \
    stkmenumodel.h \
    stkmenuitem.h \
    simif.h \
    simimageprovider.h

OTHER_FILES += \
    ../interfaces/org.ofono.SimManager.xml \
    ../interfaces/org.ofono.SimToolkit.xml \
    ../interfaces/org.ofono.SimToolkitAgent.xml \
    ../interfaces/org.ofono.Manager.xml \
    qtc_packaging/meego.spec \
    stkyesno.qml \
    stkpopup.qml \
    stkmessage.qml \
    stkmenu.qml \
    stkinputtext.qml \
    stkinputkey.qml \
    sim_32x32.xpm \
    stkuicheck.js \
    satk.desktop

RESOURCES += \
    resources.qrc

TRANSLATIONS += *.qml

desktop.files += *.desktop
desktop.path += $$INSTALL_ROOT/usr/share/applications

qmlfiles.files += *.xpm
qmlfiles.path += $$INSTALL_ROOT/usr/share/$$TARGET


INSTALLS += qmlfiles desktop
