#pragma once
//#include <QPainter>
#include <QVector>
#include <QWidget>
#include "ontology/ontology.h"
#include "ontologycell.h"
#ifdef DEBUG
#include <iostream>
#endif

using namespace mbdev_ontology;

namespace Ui {
class OntologyGraph;
}

/*!
  \brief Contains only the graphical representation of an ontology.
  No manipulation tools. Use signal/slot mechanism
  to react on clicks and text edits in this widget.
  */
class OntologyGraph : public QWidget {
   Q_OBJECT

private:
   Ui::OntologyGraph *ui;
   QSize ontoSizeHint;
   ontology* onto;
   /*!
     \brief Contains all objects added to the graph;
     they are all used to graphically represent an ontology.
     */
   QVector<OntologyCell*> cells;
   //QVector<OntologyCell*> cells;
   void clearCells();
public:
   explicit OntologyGraph(QWidget *parent = 0);
   ~OntologyGraph();
   //virtual void paintEvent(QPaintEvent *);
   /*!
     \brief Sets the ontology represented in this widget.
     Refreshes all graphics.
     */
   void setOntology(ontology* onto);
   virtual QSize sizeHint();
public slots:
   void refreshGraphics();
};
