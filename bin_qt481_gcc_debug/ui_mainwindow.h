/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Sep 9 22:10:50 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "gui/consolesimulator.h"
#include "gui/visualontology.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionLoad;
    QAction *actionClear;
    QAction *actionNew;
    QAction *actionSet_name;
    QAction *actionAddRel;
    QAction *actionSet_property;
    QAction *actionRemoveRel;
    QAction *actionInsertElem;
    QAction *actionDelete_element;
    QAction *actionDelete;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    ConsoleSimulator *console;
    VisualOntology *graph;
    QMenuBar *menuBar;
    QMenu *menuOntology;
    QMenu *menuElement;
    QMenu *menuApplication;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSet_name = new QAction(MainWindow);
        actionSet_name->setObjectName(QString::fromUtf8("actionSet_name"));
        actionAddRel = new QAction(MainWindow);
        actionAddRel->setObjectName(QString::fromUtf8("actionAddRel"));
        actionSet_property = new QAction(MainWindow);
        actionSet_property->setObjectName(QString::fromUtf8("actionSet_property"));
        actionRemoveRel = new QAction(MainWindow);
        actionRemoveRel->setObjectName(QString::fromUtf8("actionRemoveRel"));
        actionInsertElem = new QAction(MainWindow);
        actionInsertElem->setObjectName(QString::fromUtf8("actionInsertElem"));
        actionDelete_element = new QAction(MainWindow);
        actionDelete_element->setObjectName(QString::fromUtf8("actionDelete_element"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(1, 1, 1, 1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        console = new ConsoleSimulator(centralWidget);
        console->setObjectName(QString::fromUtf8("console"));

        gridLayout->addWidget(console, 0, 0, 1, 1);

        graph = new VisualOntology(centralWidget);
        graph->setObjectName(QString::fromUtf8("graph"));

        gridLayout->addWidget(graph, 0, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnMinimumWidth(0, 200);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 24));
        menuOntology = new QMenu(menuBar);
        menuOntology->setObjectName(QString::fromUtf8("menuOntology"));
        menuOntology->setEnabled(false);
        menuElement = new QMenu(menuBar);
        menuElement->setObjectName(QString::fromUtf8("menuElement"));
        menuElement->setEnabled(false);
        menuApplication = new QMenu(menuBar);
        menuApplication->setObjectName(QString::fromUtf8("menuApplication"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuApplication->menuAction());
        menuBar->addAction(menuOntology->menuAction());
        menuBar->addAction(menuElement->menuAction());
        menuOntology->addAction(actionInsertElem);
        menuOntology->addSeparator();
        menuOntology->addAction(actionNew);
        menuOntology->addAction(actionSave);
        menuOntology->addAction(actionLoad);
        menuOntology->addAction(actionClear);
        menuElement->addAction(actionSet_name);
        menuElement->addAction(actionSet_property);
        menuElement->addAction(actionAddRel);
        menuElement->addAction(actionRemoveRel);
        menuElement->addSeparator();
        menuElement->addAction(actionDelete);
        menuApplication->addAction(actionAbout);
        menuApplication->addSeparator();
        menuApplication->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GrafOnto", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionSet_name->setText(QApplication::translate("MainWindow", "Set name", 0, QApplication::UnicodeUTF8));
        actionAddRel->setText(QApplication::translate("MainWindow", "Add relation", 0, QApplication::UnicodeUTF8));
        actionSet_property->setText(QApplication::translate("MainWindow", "Set property", 0, QApplication::UnicodeUTF8));
        actionRemoveRel->setText(QApplication::translate("MainWindow", "Remove relation", 0, QApplication::UnicodeUTF8));
        actionInsertElem->setText(QApplication::translate("MainWindow", "Insert element", 0, QApplication::UnicodeUTF8));
        actionDelete_element->setText(QApplication::translate("MainWindow", "Delete element", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        menuOntology->setTitle(QApplication::translate("MainWindow", "Ontology", 0, QApplication::UnicodeUTF8));
        menuElement->setTitle(QApplication::translate("MainWindow", "Element", 0, QApplication::UnicodeUTF8));
        menuApplication->setTitle(QApplication::translate("MainWindow", "Application", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
