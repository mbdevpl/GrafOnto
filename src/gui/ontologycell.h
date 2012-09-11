#pragma once
#include <QPainter>
#include <QLabel>
#include <QRect>
#include <QVector>
#include <QWidget>
#include "ontology/cell.h"

#ifdef DEBUG
#include <QDebug>
#endif

using namespace mbdev_ontology;

namespace Ui {
class OntologyCell;
}

/*!
  \brief Graphical representation of a mbdev_ontology::cell.
  */
class OntologyCell : public QWidget
{
   Q_OBJECT
private:
   Ui::OntologyCell *ui;
   QSize cellSizeHint;
   cell* c;
   QVector<QLabel*> categories;
   QVector<QLabel*> elements;
   void refreshGraphics();
public:
   explicit OntologyCell(QWidget *parent = 0);
   ~OntologyCell();
   /*!
     \brief Sets the cell represented by this widget.
     \param c address of the cell
     */
   void setCell(cell* c);
   cell* getCell()
   {
      return c;
   }
protected:
   void paintEvent(QPaintEvent *event);
public:
   virtual QSize sizeHint();
};
