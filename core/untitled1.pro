TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        block.cpp \
        disk.cpp \
        ifilesystem.cpp \
        inode.cpp \
        inodetable.cpp \
        main.cpp \
        masterbootrecord.cpp \
        partition.cpp

HEADERS += \
    block.h \
    disk.h \
    ifilesystem.h \
    inode.h \
    inodetable.h \
    masterbootrecord.h \
    partition.h
