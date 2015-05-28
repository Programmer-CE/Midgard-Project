#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T17:55:03
#
#-------------------------------------------------

QT       += core gui network xml xmlpatterns
QT += widgets
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Midgard
TEMPLATE = app


SOURCES += main.cpp\
        midgardmenu.cpp \
    logic/customgenetics/hpentity.cpp \
    logic/customgenetics/villager.cpp \
    io/xmlreader.cpp \
    logic/xmlconstanst.cpp \
    logic/random.cpp \
    logic/customgenetics/villagercrosser.cpp \
    logic/customgenetics/villagerfabric.cpp \
    logic/customgenetics/midgardarwin.cpp \
    logic/customgenetics/villagersverificator.cpp \
    logic/customgenetics/villagerfinalstate.cpp \
    genetics/comparer.cpp \
    genetics/crosser.cpp \
    genetics/darwin.cpp \
    genetics/finalstateverificator.cpp \
    genetics/fitnessverificator.cpp \
    genetics/individuo.cpp \
    genetics/individuousfabric.cpp \
    genetics/poblation.cpp \
    exception/exception.cpp \
    exception/nullpointerexception.cpp \
    mapselector.cpp \
    updater.cpp \
    logic/emulator.cpp \
    logic/emulationsmanager.cpp \
    logic/idemulatormessage.cpp \
    logic/initialstats.cpp \
    logic/raza.cpp \
    logic/connectionManager/fclient.cpp \
    logic/connectionManager/fserver.cpp \
    logic/god.cpp \
    logic/pathfinding/priorityQueue.cpp \
    logic/pathfinding/pqNode.cpp \
    logic/pathfinding/pathpoint.cpp \
    logic/pathfinding/aStarPathFinder.cpp \
    logic/pathfinding/aStarNode.cpp

HEADERS  += midgardmenu.h \
    logic/customgenetics/hpentity.h \
    logic/customgenetics/villager.h \
    io/xmlreader.h \
    logic/xmlconstanst.h \
    logic/random.h \
    logic/customgenetics/villagercrosser.h \
    logic/customgenetics/villagerfabric.h \
    logic/customgenetics/midgardarwin.h \
    logic/customgenetics/villagersverificator.h \
    logic/customgenetics/villagerfinalstate.h \
    genetics/comparer.h \
    genetics/crosser.h \
    genetics/darwin.h \
    genetics/finalstateverificator.h \
    genetics/fitnessverificator.h \
    genetics/individuo.h \
    genetics/individuousfabric.h \
    genetics/poblation.h \
    exception/exception.h \
    exception/nullpointerexception.h \
    mapselector.h \
    updater.h \
    logic/emulator.h \
    logic/emulationsmanager.h \
    logic/idemulatormessage.h \
    logic/initialstats.h \
    logic/raza.h \
    logic/connectionManager/fclient.h \
    logic/connectionManager/fserver.h \
    logic/god.h \
    logic/pathfinding/PriorityQueue.h \
    logic/pathfinding/pqNode.h \
    logic/pathfinding/pathpoint.h \
    logic/pathfinding/aStarPathFinder.h \
    logic/pathfinding/aStarNode.h

FORMS    += midgardmenu.ui \
    mapselector.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-CPPDataStructure-Desktop-Release/release/ -lCPPDataStructure
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-CPPDataStructure-Desktop-Release/debug/ -lCPPDataStructure
else:unix: LIBS += -L$$PWD/../../build-CPPDataStructure-Desktop-Release/ -lCPPDataStructure

INCLUDEPATH += $$PWD/../../CPPDataStructure
DEPENDPATH += $$PWD/../../CPPDataStructure

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build-CPPDataStructure-Desktop-Release/release/libCPPDataStructure.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build-CPPDataStructure-Desktop-Release/debug/libCPPDataStructure.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build-CPPDataStructure-Desktop-Release/release/CPPDataStructure.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build-CPPDataStructure-Desktop-Release/debug/CPPDataStructure.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../build-CPPDataStructure-Desktop-Release/libCPPDataStructure.a

RESOURCES += \
    resource.qrc


LIBS += -ljsoncpp
LIBS += -lserial
