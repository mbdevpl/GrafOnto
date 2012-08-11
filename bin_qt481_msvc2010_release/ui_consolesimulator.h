/********************************************************************************
** Form generated from reading UI file 'consolesimulator.ui'
**
** Created: Sat 11. Aug 22:51:18 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLESIMULATOR_H
#define UI_CONSOLESIMULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConsoleSimulator
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *commandLog;
    QLineEdit *commandLine;
    QPushButton *bExecute;
    QPushButton *bClearLog;
    QPushButton *bClear;
    QPushButton *bPasteLast;

    void setupUi(QWidget *ConsoleSimulator)
    {
        if (ConsoleSimulator->objectName().isEmpty())
            ConsoleSimulator->setObjectName(QString::fromUtf8("ConsoleSimulator"));
        ConsoleSimulator->resize(280, 415);
        gridLayout = new QGridLayout(ConsoleSimulator);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(5);
        commandLog = new QPlainTextEdit(ConsoleSimulator);
        commandLog->setObjectName(QString::fromUtf8("commandLog"));

        gridLayout->addWidget(commandLog, 0, 0, 1, 4);

        commandLine = new QLineEdit(ConsoleSimulator);
        commandLine->setObjectName(QString::fromUtf8("commandLine"));

        gridLayout->addWidget(commandLine, 1, 0, 1, 4);

        bExecute = new QPushButton(ConsoleSimulator);
        bExecute->setObjectName(QString::fromUtf8("bExecute"));

        gridLayout->addWidget(bExecute, 2, 0, 1, 1);

        bClearLog = new QPushButton(ConsoleSimulator);
        bClearLog->setObjectName(QString::fromUtf8("bClearLog"));

        gridLayout->addWidget(bClearLog, 2, 3, 1, 1);

        bClear = new QPushButton(ConsoleSimulator);
        bClear->setObjectName(QString::fromUtf8("bClear"));

        gridLayout->addWidget(bClear, 2, 1, 1, 1);

        bPasteLast = new QPushButton(ConsoleSimulator);
        bPasteLast->setObjectName(QString::fromUtf8("bPasteLast"));

        gridLayout->addWidget(bPasteLast, 2, 2, 1, 1);


        retranslateUi(ConsoleSimulator);

        QMetaObject::connectSlotsByName(ConsoleSimulator);
    } // setupUi

    void retranslateUi(QWidget *ConsoleSimulator)
    {
        ConsoleSimulator->setWindowTitle(QApplication::translate("ConsoleSimulator", "Form", 0, QApplication::UnicodeUTF8));
        bExecute->setText(QApplication::translate("ConsoleSimulator", "Execute", 0, QApplication::UnicodeUTF8));
        bClearLog->setText(QApplication::translate("ConsoleSimulator", "Clear log", 0, QApplication::UnicodeUTF8));
        bClear->setText(QApplication::translate("ConsoleSimulator", "Clear", 0, QApplication::UnicodeUTF8));
        bPasteLast->setText(QApplication::translate("ConsoleSimulator", "Paste last", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConsoleSimulator: public Ui_ConsoleSimulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLESIMULATOR_H
