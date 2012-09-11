#-------------------------------------------------
# Project created by QtCreator 2012-07-24T10:22:51
#-------------------------------------------------

QT       += core gui

#name of target executable
TARGET = grafonto

TEMPLATE = app

# platform specific defines
unix:DEFINES += LINUX
win32:DEFINES += WINDOWS

CONFIG(debug, debug|release) {
   DEFINES += DEBUG
}

CONFIG(release, debug|release) {
   DEFINES += RELEASE
}

# *.cpp
SOURCES += main_gui.cpp \
    ontology/category.cpp \
    ontology/cell.cpp \
    ontology/element.cpp \
    ontology/node.cpp \
    ontology/ontointerpreter.cpp \
    ontology/ontology.cpp \
    ontology/statement.cpp \
    mbdev/console_application.cpp \
    mbdev/ptr_vector.cpp \
    mbdev/string.cpp \
    mbdev/string_vector.cpp \
    mbdev/strings.cpp \
    mbdev/toolkit.cpp \
    mbdev/vector.cpp \
    console/ontoconsoleinterpreter.cpp \
    gui/simplearrow.cpp \
    gui/consolesimulator.cpp \
    gui/mainwindow.cpp \
    gui/ontologycell.cpp \
    gui/ontologygraph.cpp \
    gui/visualontology.cpp \
    gui/ontoaddcatdialog.cpp \
    gui/ontoaddstmtdialog.cpp \
    gui/ontoaddelemdialog.cpp \

# *.h
HEADERS  += \
    ontology/category.h \
    ontology/cell.h \
    ontology/element.h \
    ontology/node.h \
    ontology/ontointerpreter.h \
    ontology/ontology.h \
    ontology/statement.h \
    mbdev/console_application.h \
    mbdev/ptr_vector.h \
    mbdev/string.h \
    mbdev/string_vector.h \
    mbdev/strings.h \
    mbdev/toolkit.h \
    mbdev/vector.h \
    console/ontoconsoleinterpreter.h \
    gui/simplearrow.h \
    gui/consolesimulator.h \
    gui/mainwindow.h \
    gui/ontologycell.h \
    gui/ontologygraph.h \
    gui/visualontology.h \
    gui/ontoaddcatdialog.h \
    gui/ontoaddstmtdialog.h \
    gui/ontoaddelemdialog.h \

# *.ui
FORMS    += \
    gui/simplearrow.ui \
    gui/consolesimulator.ui \
    gui/mainwindow.ui \
    gui/ontologycell.ui \
    gui/ontologygraph.ui \
    gui/visualontology.ui \
    gui/ontoaddcatdialog.ui \
    gui/ontoaddstmtdialog.ui \
    gui/ontoaddelemdialog.ui \
