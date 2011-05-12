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

!exists(mgrif.h) {
    system(qdbusxml2cpp -v -c MgrIf -p mgrif.h:mgrif.cpp -i ofonodbustypes.h ../interfaces/org.ofono.Manager.xml)
}

!exists(simif.h) {
    system(qdbusxml2cpp -v -c SimIf -p simif.h:simif.cpp ../interfaces/org.ofono.SimManager.xml)
}

!exists(stkif.h) {
    system(qdbusxml2cpp -v -c StkIf -p stkif.h:stkif.cpp ../interfaces/org.ofono.SimToolkit.xml)
}

!exists(stkagentifadaptor.h) {
    system(qdbusxml2cpp -v -c StkAgentIfAdaptor -a stkagentifadaptor.h:stkagentifadaptor.cpp -i ofonodbustypes.h ../interfaces/org.ofono.SimToolkitAgent.xml)
}


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
    StkYesNo.qml \
    StkPopup.qml \
    StkMessage.qml \
    StkMenu.qml \
    StkInputText.qml \
    StkInputKey.qml \
    sim_32x32.xpm \
    StkUiCheck.js \
    satk.desktop \
    StkPlaySound.qml \
    StkPanel.qml \
    StkWebView.qml \
    StkPassword.qml

RESOURCES += \
    resources.qrc

# ---- Installation

desktop.files += *.desktop
desktop.path += $$INSTALL_ROOT/usr/share/applications

pixmaps.files += *.xpm *.png
pixmaps.path += $$INSTALL_ROOT/usr/share/pixmaps

INSTALLS += pixmaps desktop

# ---- Distribution

TRANSLATIONS += *.qml

PROJECT_NAME = $$TARGET
VERSION = 0.0.1

dist.commands += rm -fR $${PROJECT_NAME}-$${VERSION} &&
dist.commands += git clone .. $${PROJECT_NAME}-$${VERSION} &&
dist.commands += rm -fR $${PROJECT_NAME}-$${VERSION}/.git &&
dist.commands += rm -f $${PROJECT_NAME}-$${VERSION}/.gitignore &&
dist.commands += mkdir -p $${PROJECT_NAME}-$${VERSION}/ts &&
dist.commands += lupdate $${TRANSLATIONS} -ts $${PROJECT_NAME}-$${VERSION}/ts/$${PROJECT_NAME}.ts &&
dist.commands += tar jcpvf $${PROJECT_NAME}-$${VERSION}.tar.bz2 $${PROJECT_NAME}-$${VERSION} &&
dist.commands += rm -fR $${PROJECT_NAME}-$${VERSION}
QMAKE_EXTRA_TARGETS += dist
