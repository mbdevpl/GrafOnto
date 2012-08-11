#pragma once
#include <QLabel>
#include <QRect>
#include <QVector>
#include <QWidget>
#include "ontology/cell.h"

using namespace mbdev_ontology;

namespace Ui {
class OntologyCell;
}

class OntologyCell : public QWidget
{
   Q_OBJECT
private:
   Ui::OntologyCell *ui;
   cell* c;
   QVector<QLabel> categories;
   QVector<QLabel> elements;
   void refreshGraphics();
public:
   explicit OntologyCell(QWidget *parent = 0);
   ~OntologyCell();
   inline void setCell(cell* c);
};

inline void OntologyCell::setCell(cell* c) {
   if(this->c == c)
      return;
   this->c = c;
   refreshGraphics();
}
