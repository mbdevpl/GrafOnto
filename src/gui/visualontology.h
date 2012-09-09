#pragma once
#include <QWidget>
#include "ontologygraph.h"

namespace Ui {
class VisualOntology;
}

/*!
  \brief Scaled view of ontology.
  */
class VisualOntology : public QWidget {
   Q_OBJECT
private:
   Ui::VisualOntology *ui;
public:
   explicit VisualOntology(QWidget *parent = 0);
   ~VisualOntology();
   OntologyGraph& getGraph();
   /*!
     \brief Sets the ontology represented in this widget.
     Refreshes all graphics.
     */
   void setOntology(ontology* onto);
public slots:
   void refreshGraphics();
};
