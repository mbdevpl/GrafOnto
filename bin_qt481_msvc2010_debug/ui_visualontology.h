/********************************************************************************
** Form generated from reading UI file 'visualontology.ui'
**
** Created: Sat 11. Aug 23:03:47 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALONTOLOGY_H
#define UI_VISUALONTOLOGY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QWidget>
#include <ontologygraph.h>

QT_BEGIN_NAMESPACE

class Ui_VisualOntology
{
public:
    QGridLayout *gridLayout;
    QSlider *zoomSlider;
    QScrollArea *scrollArea;
    OntologyGraph *graph;

    void setupUi(QWidget *VisualOntology)
    {
        if (VisualOntology->objectName().isEmpty())
            VisualOntology->setObjectName(QString::fromUtf8("VisualOntology"));
        VisualOntology->resize(400, 300);
        gridLayout = new QGridLayout(VisualOntology);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        zoomSlider = new QSlider(VisualOntology);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(zoomSlider, 0, 0, 1, 1);

        scrollArea = new QScrollArea(VisualOntology);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        graph = new OntologyGraph();
        graph->setObjectName(QString::fromUtf8("graph"));
        graph->setGeometry(QRect(0, 0, 355, 280));
        scrollArea->setWidget(graph);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);


        retranslateUi(VisualOntology);

        QMetaObject::connectSlotsByName(VisualOntology);
    } // setupUi

    void retranslateUi(QWidget *VisualOntology)
    {
        VisualOntology->setWindowTitle(QApplication::translate("VisualOntology", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VisualOntology: public Ui_VisualOntology {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALONTOLOGY_H