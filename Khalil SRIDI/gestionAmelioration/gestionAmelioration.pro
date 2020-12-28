QT       += core gui sql serialport printsupport network charts multimedia
QT += sql
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    formation.cpp \
    main.cpp \
    mainwindow.cpp \
    projets.cpp \
    statistiques.cpp

HEADERS += \
    connection.h \
    formation.h \
    mainwindow.h \
    projets.h \
    statistiques.h

FORMS += \
    mainwindow.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
