#-------------------------------------------------
#
# Project created by QtCreator 2019-08-19T16:28:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
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

SOURCES +=  main.cpp \
    core/api.cpp \
    core/block.cpp \
    core/disk.cpp \
    core/ifilesystem.cpp \
    core/masterbootrecord.cpp \
    core/partition.cpp \
    ui/customUI/customcontrolbar.cpp \
    ui/customUI/customlistwidgetitem.cpp \
    ui/pages/detailpage.cpp \
    ui/pages/diskinfo.cpp \
    ui/pages/mainwindow.cpp \
    ui/pages/resizepartition.cpp \
    ui/wizard/diskwizard.cpp \
    ui/wizard/pages/diskpage.cpp \
    ui/wizard/pages/intropage.cpp \
    ui/wizard/pages/partitionpage.cpp \
    ui/wizard/pages/summarypage.cpp \
    ui/wizard/partitionwizard.cpp


HEADERS +=  core/api.h \
    core/block.h \
    core/disk.h \
    core/ifilesystem.h \
    core/masterbootrecord.h \
    core/partition.h \
    ui/customUI/customcontrolbar.h \
    ui/customUI/customlistwidgetitem.h \
    ui/pages/detailpage.h \
    ui/pages/diskinfo.h \
    ui/pages/mainwindow.h \
    ui/pages/resizepartition.h \
    ui/wizard/diskwizard.h \
    ui/wizard/pages/diskpage.h \
    ui/wizard/pages/intropage.h \
    ui/wizard/pages/pages_enum.h \
    ui/wizard/pages/partitionpage.h \
    ui/wizard/pages/summarypage.h \
    ui/wizard/partitionwizard.h


FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=  res/code.svg \
    res/edit.svg \
    res/hard-drive.svg \
    res/help-circle.svg \
    res/info.svg \
    res/layout.svg \
    res/moon.svg \
    res/plus.svg \
    res/sun.svg \
    res/terminal.svg \
    res/trash-2.svg \
    res/trash.svg \
    ui/res/dark/align-center.svg \
    ui/res/dark/arrow-left-circle.svg \
    ui/res/dark/arrow-right-circle.svg \
    ui/res/dark/book.svg \
    ui/res/dark/code.svg \
    ui/res/dark/edit.svg \
    ui/res/dark/hard-drive.svg \
    ui/res/dark/help-circle.svg \
    ui/res/dark/info.svg \
    ui/res/dark/layout.svg \
    ui/res/dark/log-in.svg \
    ui/res/dark/log-out.svg \
    ui/res/dark/moon.svg \
    ui/res/dark/plus.svg \
    ui/res/dark/sun.svg \
    ui/res/dark/terminal.svg \
    ui/res/dark/trash-2.svg \
    ui/res/dark/trash.svg \
    ui/res/light/align-center.svg \
    ui/res/light/arrow-left-circle.svg \
    ui/res/light/arrow-right-circle.svg \
    ui/res/light/book.svg \
    ui/res/light/code.svg \
    ui/res/light/edit.svg \
    ui/res/light/hard-drive.svg \
    ui/res/light/help-circle.svg \
    ui/res/light/info.svg \
    ui/res/light/layout.svg \
    ui/res/light/log-in.svg \
    ui/res/light/log-out.svg \
    ui/res/light/moon.svg \
    ui/res/light/plus.svg \
    ui/res/light/sun.svg \
    ui/res/light/terminal.svg \
    ui/res/light/trash-2.svg \
    ui/res/light/trash.svg

RESOURCES +=  \
    resources.qrc
