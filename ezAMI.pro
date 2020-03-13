#-------------------------------------------------
#
# Project created by QtCreator 2019-11-25T15:48:14
#
#-------------------------------------------------

QT       += core gui
QT       += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ezAMI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        amidialog.cpp \
        basemodel.cpp \
        excitation.cpp \
        main.cpp \
        mainwindow.cpp \
        plotting.cpp \
        sceneclick.cpp \
        svgload.cpp

HEADERS += \
        amidialog.h \
        basemodel.h \
        excitation.h \
        mainwindow.h \
        plotting.h \
        sceneclick.h \
        svgload.h \
        ui_mainwindow.h \
        ui_plotwindow.h

FORMS += \
        amidialog.ui \
        mainwindow.ui \
        plotwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/AMI.svg \
    img/Excitation.svg \
    img/Plotting .svg \
    img/Plotting .svg \
    img/Plotting .svg \
    img/Plotting .svg \
    img/Plotting .svg \
    img/Plotting.svg \
    img/add.png \
    img/connect.png \
    img/logo.svg \
    img/play_stop.png \
    img/preferences.png \
    img/stop.png
