QT       += core gui sql multimedia charts printsupport serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    afficherunpersonnel.cpp \
    arduino.cpp \
    connexionsql.cpp \
    dialog.cpp \
    formation.cpp \
    login.cpp \
    main.cpp \
    modifierprofil.cpp \
    options.cpp \
    personnels.cpp \
    profils.cpp \
    projets.cpp \
    smart_factory_2a1.cpp \
    smtp.cpp \
    statistique2.cpp \
    statistiques.cpp

HEADERS += \
    afficherunpersonnel.h \
    arduino.h \
    connexionsql.h \
    dialog.h \
    formation.h \
    login.h \
    modifierprofil.h \
    options.h \
    personnels.h \
    profils.h \
    projets.h \
    smart_factory_2a1.h \
    smtp.h \
    statistique2.h \
    statistiques.h

FORMS += \
    afficherunpersonnel.ui \
    dialog.ui \
    modifierprofil.ui \
    options.ui \
    smart_factory_2a1.ui \
    statistique2.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
