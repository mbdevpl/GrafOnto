/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 11. Aug 13:55:23 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

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
    QAction *actionAdd_relation;
    QAction *actionSet_property;
    QAction *actionRemove_relation;
    QAction *actionInsert_element;
    QAction *actionDelete_element;
    QAction *actionDelete;
    QWidget *centralWidget;
    QScrollArea *scrollGraphArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QSlider *verticalSlider;
    QLineEdit *commandLine;
    QPlainTextEdit *commandHistory;
    QPushButton *bExecute;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuOntology;
    QMenu *menuElement;
    QMenu *menuApplication;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 460);
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
        actionAdd_relation = new QAction(MainWindow);
        actionAdd_relation->setObjectName(QString::fromUtf8("actionAdd_relation"));
        actionSet_property = new QAction(MainWindow);
        actionSet_property->setObjectName(QString::fromUtf8("actionSet_property"));
        actionRemove_relation = new QAction(MainWindow);
        actionRemove_relation->setObjectName(QString::fromUtf8("actionRemove_relation"));
        actionInsert_element = new QAction(MainWindow);
        actionInsert_element->setObjectName(QString::fromUtf8("actionInsert_element"));
        actionDelete_element = new QAction(MainWindow);
        actionDelete_element->setObjectName(QString::fromUtf8("actionDelete_element"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        scrollGraphArea = new QScrollArea(centralWidget);
        scrollGraphArea->setObjectName(QString::fromUtf8("scrollGraphArea"));
        scrollGraphArea->setGeometry(QRect(260, 0, 439, 400));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollGraphArea->sizePolicy().hasHeightForWidth());
        scrollGraphArea->setSizePolicy(sizePolicy);
        scrollGraphArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollGraphArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollGraphArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 424, 385));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 121, 16));
        scrollGraphArea->setWidget(scrollAreaWidgetContents);
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(230, 0, 29, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        commandLine = new QLineEdit(centralWidget);
        commandLine->setObjectName(QString::fromUtf8("commandLine"));
        commandLine->setGeometry(QRect(0, 340, 259, 26));
        commandHistory = new QPlainTextEdit(centralWidget);
        commandHistory->setObjectName(QString::fromUtf8("commandHistory"));
        commandHistory->setGeometry(QRect(0, 0, 229, 339));
        bExecute = new QPushButton(centralWidget);
        bExecute->setObjectName(QString::fromUtf8("bExecute"));
        bExecute->setGeometry(QRect(0, 370, 69, 27));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 370, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 24));
        menuOntology = new QMenu(menuBar);
        menuOntology->setObjectName(QString::fromUtf8("menuOntology"));
        menuElement = new QMenu(menuBar);
        menuElement->setObjectName(QString::fromUtf8("menuElement"));
        menuApplication = new QMenu(menuBar);
        menuApplication->setObjectName(QString::fromUtf8("menuApplication"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(commandLine, bExecute);
        QWidget::setTabOrder(bExecute, commandHistory);
        QWidget::setTabOrder(commandHistory, pushButton);
        QWidget::setTabOrder(pushButton, verticalSlider);
        QWidget::setTabOrder(verticalSlider, scrollGraphArea);

        menuBar->addAction(menuApplication->menuAction());
        menuBar->addAction(menuOntology->menuAction());
        menuBar->addAction(menuElement->menuAction());
        menuOntology->addAction(actionInsert_element);
        menuOntology->addSeparator();
        menuOntology->addAction(actionNew);
        menuOntology->addAction(actionSave);
        menuOntology->addAction(actionLoad);
        menuOntology->addAction(actionClear);
        menuElement->addAction(actionSet_name);
        menuElement->addAction(actionSet_property);
        menuElement->addAction(actionAdd_relation);
        menuElement->addAction(actionRemove_relation);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionSet_name->setText(QApplication::translate("MainWindow", "Set name", 0, QApplication::UnicodeUTF8));
        actionAdd_relation->setText(QApplication::translate("MainWindow", "Add relation", 0, QApplication::UnicodeUTF8));
        actionSet_property->setText(QApplication::translate("MainWindow", "Set property", 0, QApplication::UnicodeUTF8));
        actionRemove_relation->setText(QApplication::translate("MainWindow", "Remove relation", 0, QApplication::UnicodeUTF8));
        actionInsert_element->setText(QApplication::translate("MainWindow", "Insert element", 0, QApplication::UnicodeUTF8));
        actionDelete_element->setText(QApplication::translate("MainWindow", "Delete element", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Graph will be here", 0, QApplication::UnicodeUTF8));
        commandLine->setText(QString());
        commandHistory->setPlainText(QApplication::translate("MainWindow", "$ add category obj\n"
"added category obj\n"
"$ add category rel\n"
"added category rel\n"
"", 0, QApplication::UnicodeUTF8));
        bExecute->setText(QApplication::translate("MainWindow", "Execute", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Paste last cmd", 0, QApplication::UnicodeUTF8));
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
