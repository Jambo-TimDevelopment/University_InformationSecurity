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
    formmainwindowadmin.cpp \
    formmainwindowclient.cpp \
    formuserlist.cpp \
    main.cpp \
    passphrase.cpp \
    qaesencryption.cpp \
    user.cpp \
    userlist.cpp \
    userservice.cpp

HEADERS += \
    Utilities.h \
    aesni/aesni-enc-cbc.h \
    aesni/aesni-enc-ecb.h \
    aesni/aesni-key-exp.h \
    aesni/aesni-key-init.h \
    fileservice.h \
    formaboutprogram.h \
    formauthorisation.h \
    formchangepassword.h \
    formmainwindowadmin.h \
    formmainwindowclient.h \
    formuserlist.h \
    passphrase.h \
    qaesencryption.h \
    user.h \
    userlist.h \
    userservice.h

FORMS += \
    formaboutprogram.ui \
    formauthorisation.ui \
    formchangepassword.ui \
    formmainwindowadmin.ui \
    formmainwindowclient.ui \
    formuserlist.ui \
    passphrase.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
