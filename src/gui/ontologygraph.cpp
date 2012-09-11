#include "ontologygraph.h"
#include "ui_ontologygraph.h"

OntologyGraph::OntologyGraph(QWidget *parent)
   : QWidget(parent), ui(new Ui::OntologyGraph), /*ontoSizeHint(0, 0),*/
     onto(nullptr), cells(), min_x(0), max_x(0), min_y(0), max_y(0) {
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

void OntologyGraph::initCells(size_t size)
{
   cells = QVector<OntologyCell*>();
   positions = QVector<QPoint>();
   sizes = QVector<QSize>();
   added = QVector<bool>();
   if(size == 0)
      return;
   for(size_t i=0; i<size; ++i)
   {
      cells.push_back(0);
      positions.push_back(QPoint(0,0));
      sizes.push_back(QSize(0,0));
      added.push_back(false);
   }
}

void OntologyGraph::clearCells()
{
   size_t size = cells.size();
   if(size == 0)
      return;

   //const QObjectList& chldrn = this->children();

   for(size_t i=0; i<size; --i)
   {
      delete cells[i];
      cells[i] = nullptr;
   }
   this->cells.clear();
   positions.clear();
   sizes.clear();
   added.clear();
}

void OntologyGraph::createCellAt(size_t index, cell* c) {
   OntologyCell* oc = new OntologyCell(this);
   oc->setCell(c);
   QSize hint = oc->sizeHint();
   int w = hint.width();
   int h = hint.height();
   oc->resize(w, h);

   cells[index] = oc;
   sizes[index] = QSize(w, h);
}

void OntologyGraph::drawCell(size_t index, int x, int y) {
   OntologyCell* oc = cells[index];
   int w = oc->width();
   int h = oc->height();

   oc->move(x, y);

   if(x < min_x)
      min_x = x;
   if(x+w > max_x)
      max_x = x+w;
   if(y < min_y)
      min_y = y;
   if(y+h > max_y)
      max_y = y+h;

   oc->show();

   positions[index] = QPoint(x, y);
   added[index] = true;
}

void OntologyGraph::drawConnection(size_t from, size_t to)
{
   if(!added[from] || !added[to])
      return;

   QPoint begin = cells[from]->pos();
   begin.rx() += cells[from]->width();
   begin.ry() += (cells[from]->height()/2);

   QPoint end = cells[to]->pos();
   end.ry() += (cells[to]->height()/2);

   SimpleArrow* sa = new SimpleArrow(begin, end, this);
   connections.append(sa);
   sa->show();
}

void OntologyGraph::addAllConnectedCells(size_t index, QPoint at)
{
   size_t size = cells.size();

   // handle trivial cases
   if(index >= size)
      return;
   if(added[index])
      return;

   //draw the cell
   drawCell(index, at.x(), at.y());

   cell* c = cells[index]->getCell();
   // find all connections
   ptr_vector<statement> leads_to = onto->findStatements(c, 0);
   size_t size_to = leads_to.size();
   if(size_to > 0)
      for(size_t i=0; i<size_to; ++i)
      {
         statement* st = leads_to[i];
         int ind = -1;
         for(size_t n=0; n<size; ++n)
            if(st->rightPtr() == cells[n]->getCell())
            {
               ind = n;
               break;
            }
         if(ind == -1)
            continue;
         QPoint at_next = QPoint(at.x(), at.y());
         at_next.rx()+= cells[index]->width()+30;
         addAllConnectedCells(ind, at_next);
         drawConnection(index, ind);
      }

//   ptr_vector<statement> leads_from = onto->findStatements(0, c);
//   size_t size_from = leads_from.size();
//   if(size_from > 0)
//      for(size_t i=0; i<size_from; ++i)
//      {
//         int ind = -1;
//         for(size_t n=0; n<size; ++n)
//            if(leads_from[i]->leftPtr() == cells[n])
//            {
//               ind = n;
//               break;
//            }
//         if(ind == -1)
//            continue;
//         addAllConnectedCells(ind, cells, added);
//      }
}

void OntologyGraph::refreshGraphics() {
   //remove out-of-date content
   clearCells();

   //get all cells of the ontology
   ptr_vector<cell> cs = onto->findCells();

   // check trivial case
   size_t size = cs.size();
   if(size == 0)
      return;

   // init variables
   initCells(cs.size());

   // create all cells for future rearanging and display
   for(size_t i=0; i<size; ++i)
      createCellAt(i, cs[i]);

   for(size_t i=0; i<size; ++i)
   {
      cell* c = cs[i];
#ifdef DEBUG
      qDebug() << "drawing cell " << c->str().c_str();
#endif
      // skip if the current cell was added
      // (this happens due to connections with other cells)
      if(added[i])
         continue;
      // recursively add all connected cells
      addAllConnectedCells(i);
   }
   this->resize(-min_x+max_x, -min_y+max_y);
   return;

//      QSize c_size = addCell(c, 0, 0);
//      ptr_vector<statement> leading_to = onto->findStatements(c, 0);
//      ptr_vector<statement> result_of = onto->findStatements(0, c);
      //for(ptr_vector<cell>::iterator it = cs.begin()+1; it != cs.end(); ++it)

   //   QSize c_size = addCell(cs[0], 0, 0);
//   ptr_vector<statement> leading_to = onto->findStatements(cs[0], 0);
//   ptr_vector<statement> result_of = onto->findStatements(0, cs[0]);

//   for(ptr_vector<cell>::iterator it = cs.begin()+1; it != cs.end(); ++it) {
//      cell* c = *it;
//      size_t currX = index*15;
//      size_t currY = index*32;
//      addCell(c, currX, currY);
//      index++;
//   }
}

QSize OntologyGraph::sizeHint() {
   //return ontoSizeHint;
   return QSize(0, 0);
}

/* old graphics:

   size_t maxWidth = 50, maxHeight = 50;
//create a new cell
//      OntologyCell* oc = new OntologyCell(this);
//      oc->setCell(c);
//apply geometry
//size_t currWidth = 10+20*c->size();
//size_t currHeight = 30;
//      QSize s = oc->sizeHint();
//      size_t currWidth = s.width();
//      size_t currHeight = s.height();
//      oc->setGeometry(currX, currY, currWidth, currHeight);
//oc->width() + oc->pos().x();
//      if(currX+currWidth > maxWidth)
//         maxWidth = currX+currWidth;
//size_t currHeight = oc->height() + oc->pos().y();
//      if(currY+currHeight > maxHeight)
//         maxHeight = currY+currHeight;
// show the cell
//      oc->show();
// add pointer to the list
//      cells.push_back(oc);
//#ifdef DEBUG
//      std::cout << "size=" << currWidth << 'x' << currHeight
//                << " pt=" << currX << 'x' << currY
//                << std::endl;
//#endif
//ontoSizeHint.setWidth(maxWidth);
//ontoSizeHint.setHeight(maxHeight);
//this->updateGeometry();
//#ifdef DEBUG
//   QSize graph_size = this->size();
//   //this->setSizePolicy();
//   //this->setGeometry(0, 0, maxWidth, maxHeight);
//   graph_size = this->size();
//   std::cout << "graph_size=" << graph_size.width()
//             << 'x' << graph_size.height() << std::endl;
//#endif

//QString s("hint=");
//s = s.append(QString::number(sizeHint().width())).append("x")
//      .append(QString::number(sizeHint().height()));
//QLabel* l = new QLabel(s,this);
//l->setGeometry(50,5,500,16);
//l->show();
//this->updateGeometry();

// old graphics above

*/
