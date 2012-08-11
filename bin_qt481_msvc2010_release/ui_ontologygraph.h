/********************************************************************************
** Form generated from reading UI file 'ontologygraph.ui'
**
** Created: Sat 11. Aug 22:51:18 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONTOLOGYGRAPH_H
#define UI_ONTOLOGYGRAPH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OntologyGraph
{
public:

    void setupUi(QWidget *OntologyGraph)
    {
        if (OntologyGraph->objectName().isEmpty())
            OntologyGraph->setObjectName(QString::fromUtf8("OntologyGraph"));
        OntologyGraph->resize(400, 300);

        retranslateUi(OntologyGraph);

        QMetaObject::connectSlotsByName(OntologyGraph);
    } // setupUi

    void retranslateUi(QWidget *OntologyGraph)
    {
        OntologyGraph->setWindowTitle(QApplication::translate("OntologyGraph", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OntologyGraph: public Ui_OntologyGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONTOLOGYGRAPH_H
