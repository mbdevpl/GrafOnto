#include "ontologygraph.h"
#include "ui_ontologygraph.h"

void OntologyGraph::refreshGraphics() {
   this->cells.clear();
   ptr_vector<cell> cs = onto->findCells();
   ptr_vector<cell>::iterator it;
   for(it = cs.begin(); it != cs.end(); it++) {
      //cell& c = *it;
      OntologyCell* oc = new OntologyCell(this);
      oc->setCell(*it);
      cells.push_back(oc);
   }
}

OntologyGraph::OntologyGraph(QWidget *parent)
   : QWidget(parent), ui(new Ui::OntologyGraph), cells() {
   ui->setupUi(this);
}

OntologyGraph::~OntologyGraph() {
   delete ui;
}
