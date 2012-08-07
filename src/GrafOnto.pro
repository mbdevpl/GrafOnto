#-------------------------------------------------
# Project created by QtCreator 2012-07-24T10:22:51
#-------------------------------------------------

QT       += core gui

TARGET = bin
TEMPLATE = app

DEFINES += CONSOLE_LINUX
debug:DEFINES += DEBUG
release:DEFINES += RELEASE

SOURCES += main.cpp \
	 mainwindow.cpp \
	 ontology/node.cpp \
	 ontology/element.cpp \
	 ontology/category.cpp \
	 ontology/ontology.cpp \
    mbdev/string.cpp \
	 mbdev/strings.cpp \
    mbdev/vector.cpp \
    mbdev/toolkit.cpp \
    mbdev/string_vector.cpp \
    mbdev/ptr_vector.cpp \
    grafonto.cpp \
    mbdev/console_application.cpp \
    ontology/cell.cpp \
    ontology/statement.cpp


HEADERS  += \
    mainwindow.h \
    ontology/node.h \
    ontology/element.h \
    ontology/category.h \
    ontology/ontology.h \
    mbdev/string.h \
	 mbdev/strings.h \
    mbdev/vector.h \
    mbdev/toolkit.h \
    mbdev/string_vector.h \
    mbdev/ptr_vector.h \
    grafonto.h \
    mbdev/console_application.h \
    ontology/cell.h \
    ontology/statement.h

FORMS    += mainwindow.ui
