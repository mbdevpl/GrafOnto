#pragma once
//#include <QPainter>
#include <QVector>
#include <QWidget>
#include <QLine>
#include "ontology/ontology.h"
#include "ontologycell.h"
#ifdef DEBUG
#include <iostream>
#include <sstream>
#include <QDebug>
#endif
#include "SimpleArrow.h"

using namespace mbdev_ontology;

namespace Ui {
class OntologyGraph;
}

/*!
  \brief Contains only the graphical representation of an ontology.
  No manipulation tools. Use signal/slot mechanism
  to react on clicks and text edits in this widget.
  */
class OntologyGraph : public QWidget {
   Q_OBJECT

private:
   Ui::OntologyGraph *ui;
   //QSize ontoSizeHint;
   ontology* onto;
   /*!
     \brief Contains all objects added to the graph;
     they are all used to graphically represent an ontology.
     */
   QVector<OntologyCell*> cells;
   QVector<QPoint> positions;
   QVector<QSize> sizes;
   QVector<bool> added;
   /*!
     \brief Contains arrows that connect the cells.
     */
   QVector<SimpleArrow*> connections;
   //stores current minimum and maximum coordinates used by cells in this graph
   int min_x, max_x, min_y, max_y;
public:
   explicit OntologyGraph(QWidget *parent = 0);
   ~OntologyGraph();
   /*!
     \brief Sets the ontology represented in this widget.
     Refreshes all graphics.
     */
   void setOntology(ontology* onto);
private:
   void initCells(size_t size);
   void clearCells();
   //// returns size of graphical representation of the cell
   //QSize addCell(cell* c, int x, int y);
   void createCellAt(size_t index, cell* c);
   void drawCell(size_t index, int x, int y);
   /*!
     \brief Adds an arrow from cell at given index from 'QVector<OntologyCell*> cells' field,
     to another cell from this field at a second given index. Both cells (obviously)
     have to be already drawn.
     \param arrow will start at cell having this index
     \param arrow will end at cell having this index
     */
   void drawConnection(size_t from, size_t to);
   void addAllConnectedCells(size_t index, QPoint at = QPoint(0, 0));
public slots:
   void refreshGraphics();
public:
   virtual QSize sizeHint();
};
