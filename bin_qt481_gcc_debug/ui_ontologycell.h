/********************************************************************************
** Form generated from reading UI file 'ontologycell.ui'
**
** Created: Sun Sep 9 22:10:50 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONTOLOGYCELL_H
#define UI_ONTOLOGYCELL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OntologyCell
{
public:

    void setupUi(QWidget *OntologyCell)
    {
        if (OntologyCell->objectName().isEmpty())
            OntologyCell->setObjectName(QString::fromUtf8("OntologyCell"));
        OntologyCell->resize(30, 30);

        retranslateUi(OntologyCell);

        QMetaObject::connectSlotsByName(OntologyCell);
    } // setupUi

    void retranslateUi(QWidget *OntologyCell)
    {
        OntologyCell->setWindowTitle(QApplication::translate("OntologyCell", "Cell of the ontology", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OntologyCell: public Ui_OntologyCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONTOLOGYCELL_H
