#ifndef SIMPLEARROW_H
#define SIMPLEARROW_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class SimpleArrow;
}

class SimpleArrow : public QWidget
{
   Q_OBJECT
private:
   Ui::SimpleArrow *ui;
private:
   QPoint from;
   QPoint to;
public:
   explicit SimpleArrow(QPoint from, QPoint to, QWidget *parent = 0);
   explicit SimpleArrow(int from_x, int from_y, int to_x, int to_y, QWidget *parent = 0);
   ~SimpleArrow();
private:
   void prepare();
protected:
    void paintEvent(QPaintEvent *event);

};

#endif // SIMPLEARROW_H
