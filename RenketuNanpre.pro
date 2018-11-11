#-------------------------------------------------
#
# Project created by QtCreator 2018-05-22T19:07:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RenketuNanpre
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

QT += multimedia
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    weditclass.cpp \
    boardclass.cpp \
    boardgroupclass.cpp \
    boardhistorycclass.cpp \
    consoleclass.cpp \
    consolemanageclass.cpp \
    editerclass.cpp \
    SudokuPuzzle.cpp \
    ndataset.cpp \
    stonecreateclass.cpp \
    solverfuncclass.cpp \
    memoryclass.cpp \
    numberloopclass.cpp \
    rootsearchclass.cpp \
    imagenumberclass.cpp \
    aiclass.cpp \
    reloadclassa.cpp \
    inputquestclass.cpp \
    main4.cpp \
    main3.cpp \
    main2.cpp \
    dataeraseclass.cpp \
    selecterasechipclass.cpp

HEADERS += \
        mainwindow.h \
    weditclass.h \
    boardclass.h \
    boardgroupclass.h \
    boardhistorycclass.h \
    consoleclass.h \
    consolemanageclass.h \
    editerclass.h \
    SudokuPuzzle.h \
    ndataset.h \
    stonecreateclass.h \
    solverfuncclass.h \
    memoryclass.h \
    numberloopclass.h \
    rootsearchclass.h \
    imagenumberclass.h \
    aiclass.h \
    reloadclassa.h \
    inputquestclass.h \
    edtdata.h \
    dataeraseclass.h \
    selecterasechipclass.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    memo1.txt \
    mamo2.txt \
    memo3.txt \
    boardhistryclass-backup \
    memo4.txt \
    backup.txt \
    backup2.txt \
    osii.txt \
    memo5.txt \
    profile.txt \
    saitekika

QMAKE_CXXFLAGS +=  -mfpmath=both -fopenmp

LIBS += -fopenmp


QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig
