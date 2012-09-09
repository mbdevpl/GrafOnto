#include "ontologygraph.h"
#include "ui_ontologygraph.h"

void OntologyGraph::clearCells() {
   size_t size = cells.size();
   if(size == 0)
      return;
   for(size_t i=0; i<size; i--) {
      delete cells[i];
      cells[i] = nullptr;
   }
   this->cells.clear();
}

OntologyGraph::OntologyGraph(QWidget *parent)
   : QWidget(parent), ui(new Ui::OntologyGraph), ontoSizeHint(0, 0),
     onto(nullptr), cells() {
   ui->setupUi(this);
}

OntologyGraph::~OntologyGraph() {
   delete ui;
   clearCells();
}

//void OntologyGraph::paintEvent(QPaintEvent *) {
//   QPainter painter(this);

//}

void OntologyGraph::setOntology(ontology* onto) {
   if(this->onto == onto)
      return;
   this->onto = onto;
   refreshGraphics();
}

QSize OntologyGraph::sizeHint() {
   return ontoSizeHint;
}

void OntologyGraph::refreshGraphics() {
   clearCells();
   ptr_vector<cell> cs = onto->findCells();
   size_t size = cs.size();
   if(size == 0)
      return;
   ptr_vector<cell>::iterator it;
   size_t index = 0;
   size_t maxWidth = 50, maxHeight = 50;
   for(it = cs.begin(); it != cs.end(); it++) {
      cell* c = *it;
      //create a new cell
      OntologyCell* oc = new OntologyCell(this);
      oc->setCell(c);
      //apply geometry
      size_t currX = 0;
      size_t currY = index*32;
      //size_t currWidth = 10+20*c->size();
      //size_t currHeight = 30;
      QSize s = oc->sizeHint();
      size_t currWidth = s.width();
      size_t currHeight = s.height();
      oc->setGeometry(currX, currY, currWidth, currHeight);
      //oc->width() + oc->pos().x();
      if(currX+currWidth > maxWidth)
         maxWidth = currX+currWidth;
      //size_t currHeight = oc->height() + oc->pos().y();
      if(currY+currHeight > maxHeight)
         maxHeight = currY+currHeight;
      // show the cell
      oc->show();
      // add pointer to the list
      cells.push_back(oc);
      index++;
#ifdef DEBUG
      std::cout << "size=" << currWidth << 'x' << currHeight
                << " pt=" << currX << 'x' << currY
                << std::endl;
#endif
   }
   ontoSizeHint.setWidth(maxWidth);
   ontoSizeHint.setHeight(maxHeight);
   this->updateGeometry();
   //QString s("hint=");
   //s = s.append(QString::number(sizeHint().width())).append("x")
   //      .append(QString::number(sizeHint().height()));
   //QLabel* l = new QLabel(s,this);
   //l->setGeometry(50,5,500,16);
   //l->show();
   //this->updateGeometry();
}
