QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alien.cpp \
    alienboss.cpp \
    bullet.cpp \
    main.cpp \
    shield.cpp \
    spacecraft.cpp \
    startgame.cpp \
    widget.cpp

HEADERS += \
    alien.h \
    alienboss.h \
    bullet.h \
    shield.h \
    spacecraft.h \
    startgame.h \
    widget.h

FORMS += \
    startgame.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
