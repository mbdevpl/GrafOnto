#pragma once
#include <QWidget>
#include "ontologygraph.h"

namespace Ui {
class VisualOntology;
}

class VisualOntology : public QWidget {
   Q_OBJECT
private:
   Ui::VisualOntology *ui;
public:
   explicit VisualOntology(QWidget *parent = 0);
   ~VisualOntology();
   OntologyGraph& getGraph();
};
