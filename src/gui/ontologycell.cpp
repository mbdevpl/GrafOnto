#include "ontologycell.h"
#include "ui_ontologycell.h"

void OntologyCell::refreshGraphics() {
   size_t DefaultHeight = 16;
   if(c == nullptr)
      return;
   size_t size = c->size();
   //cellSizeHint.setWidth(32);
   if(size == 0)
      return;
   //this->setGeometry(QRect(0, 0, size*50, 2*20));
   cell::iterator it;
   size_t index = 0;
   size_t width = 0;
   for(it = c->begin(); it != c->end(); it++) {
      cell_element& ce = *it;
      //category
      QString s1(ce.first->getName().c_str());
      s1 = QString(s1.at(0).toUpper());
      QLabel* categ = new QLabel(s1, this);
      categ->setGeometry(width, 0, DefaultHeight, DefaultHeight);
      categories.push_back(categ);
      //element
      QString s2(ce.second->getName().c_str());
      QLabel* elem = new QLabel(s2, this);
      QSize hint = elem->sizeHint();
      elem->setGeometry(width, DefaultHeight, hint.width(), hint.height());
      //elem->geometry().
      elem->adjustSize();
      elements.push_back(elem);
      //make changes visible
      index++;
      width+=elem->width()+5;
      categ->show();
      elem->show();
   }
   this->cellSizeHint.setWidth(width);
   this->updateGeometry();
}

OntologyCell::OntologyCell(QWidget *parent)
   : QWidget(parent), ui(new Ui::OntologyCell), cellSizeHint(32,32), c(nullptr),
     categories(), elements() {
   ui->setupUi(this);
}

OntologyCell::~OntologyCell() {
   delete ui;
}

void OntologyCell::setCell(cell* c) {
   if(this->c == c)
      return;
   this->c = c;
   refreshGraphics();
}

QSize OntologyCell::sizeHint() {
   return cellSizeHint;
}
