QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fileservice.cpp \
    formaboutprogram.cpp \
    formauthorisation.cpp \
    formchangepassword.cpp \
    formmainwindowclient.cpp \
    formuserlist.cpp \
    main.cpp \
    mainwindowadmin.cpp \
    passphrase.cpp \
    userservice.cpp

HEADERS += \
    fileservice.h \
    formaboutprogram.h \
    formauthorisation.h \
    formchangepassword.h \
    formmainwindowclient.h \
    formuserlist.h \
    mainwindowadmin.h \
    passphrase.h \
    userservice.h

FORMS += \
    formaboutprogram.ui \
    formauthorisation.ui \
    formchangepassword.ui \
    formmainwindowclient.ui \
    formuserlist.ui \
    mainwindowadmin.ui \
    passphrase.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
