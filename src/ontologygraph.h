#pragma once
#include <QVector>
#include <QWidget>
#include "ontology/ontology.h"
//#include "mbdev/ptr_vector.h"
#include "ontologycell.h"

using namespace mbdev_ontology;

namespace Ui {
class OntologyGraph;
}

/*!
  \brief Contains only the graphical representation of an ontology.
  No manipulation tools. Use signal/slot mechanism
  to react on clicks and text edits in this widget.
  */
class OntologyGraph : public QWidget
{
   Q_OBJECT

private:
   Ui::OntologyGraph *ui;
   ontology* onto;
   /*!
     \brief Contains all objects added to the graph;
     they are all used to graphically represent an ontology.
     */
   QVector<OntologyCell*> cells;
   //QVector<OntologyCell*> cells;
   void refreshGraphics();
public:
   explicit OntologyGraph(QWidget *parent = 0);
   ~OntologyGraph();
   /*!
     \brief Sets the ontology represented by this widget.
     refreshes all graphics.
     */
   inline void setOntology(ontology* onto);
};

inline void OntologyGraph::setOntology(ontology* onto) {
   if(this->onto == onto)
      return;
   this->onto = onto;
   refreshGraphics();
}
