#include "visualontology.h"
#include "ui_visualontology.h"

VisualOntology::VisualOntology(QWidget *parent)
   : QWidget(parent), ui(new Ui::VisualOntology) {
   ui->setupUi(this);
}

VisualOntology::~VisualOntology() {
   delete ui;
}

OntologyGraph& VisualOntology::getGraph() {
   return *(ui->graph);
}

void VisualOntology::setOntology(ontology* onto) {
   getGraph().setOntology(onto);
   this->updateGeometry();
}

void VisualOntology::refreshGraphics() {
   getGraph().refreshGraphics();
   this->updateGeometry();
}
