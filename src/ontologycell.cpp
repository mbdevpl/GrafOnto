#include "ontologycell.h"
#include "ui_ontologycell.h"

void OntologyCell::refreshGraphics() {
   if(c == nullptr)
      return;
   size_t size = c->size();
   if(size == 0)
      return;


   this->setGeometry(QRect(0, 0, size*50, 2*20));
   cell::iterator it;
   for(it = c->begin(); it != c->end(); it++) {

   }
}

OntologyCell::OntologyCell(QWidget *parent)
   : QWidget(parent), ui(new Ui::OntologyCell) {
   ui->setupUi(this);
   this->c = nullptr;
}

OntologyCell::~OntologyCell() {
   delete ui;
}
