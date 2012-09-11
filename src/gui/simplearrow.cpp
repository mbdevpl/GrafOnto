#include "simplearrow.h"
#include "ui_simplearrow.h"

SimpleArrow::SimpleArrow(QPoint from, QPoint to, QWidget *parent) :
   QWidget(parent), ui(new Ui::SimpleArrow)
{
   ui->setupUi(this);

   this->from = from;
   this->to = to;
   prepare();
}

SimpleArrow::SimpleArrow(int from_x, int from_y,
                         int to_x, int to_y, QWidget *parent) :
   QWidget(parent), ui(new Ui::SimpleArrow)
{
   ui->setupUi(this);
   this->from = QPoint(from_x, from_y);
   this->to = QPoint(to_x, to_y);
   prepare();
}

SimpleArrow::~SimpleArrow()
{
   delete ui;
}

void SimpleArrow::prepare()
{
   this->move(0, 0);
   int x = from.x() > to.x() ? from.x() : to.x();
   int y = from.y() > to.y() ? from.y() : to.y();
   this->resize(x+1, y+1);
}

void SimpleArrow::paintEvent(QPaintEvent* /* event */)
{
   QPainter p(this);
   p.setPen(QPen(Qt::black));
   //p.setBrush(Qt::NoBrush);
   p.drawLine(from,to);
   QPoint pt(to.x(), to.y());
   pt.rx() += (to.x() >= from.x() ? -10 : 10);
   pt.ry() += (to.y() >= from.y() ? -10 : 10);
   p.drawLine(to, pt);
}
