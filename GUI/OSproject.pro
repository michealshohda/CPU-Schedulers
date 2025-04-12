QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CPUSimulator.cpp \
    FCFSScheduler.cpp \
    PriorityNonPreemptiveScheduler.cpp \
    PriorityPreemptiveScheduler.cpp \
    RoundRobinScheduler.cpp \
    SJFNonPreemptiveScheduler.cpp \
    SJFPreemptiveScheduler.cpp \
    StatisticsCalculator.cpp \
    MAINmainwindow.cpp \
    cpuscheduleros.cpp \
    global.cpp \
    mainwindow.cpp \
    main.cpp

HEADERS += \
    CPUSimulator.hpp \
    FCFSScheduler.hpp \
    Headers.hpp \
    PriorityNonPreemptiveScheduler.hpp \
    PriorityPreemptiveScheduler.hpp \
    RoundRobinScheduler.hpp \
    SJFNonPreemptiveScheduler.hpp \
    SJFPreemptiveScheduler.hpp \
    Scheduler.hpp \
    StatisticsCalculator.hpp \
    global.h \
    process.hpp \
    MAINmainwindow.h \
    cpuscheduleros.h \
    mainwindow.h \
    mainwindow.h

FORMS += \
    MAINmainwindow.ui \
    cpuscheduleros.ui \
    mainwindow.ui

TRANSLATIONS += \
    OSproject_en_CA.ts \
    OSproject_en_CA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
