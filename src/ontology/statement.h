#pragma once
#include <utility>
#include "ontology/cell.h"

namespace mbdev_ontology {

class cell;

typedef std::pair<cell*, cell*> cell_pair;

/*!
  \brief Used to store a single statement of an ontology. Statement is a pair of cells.
  */
class statement : public cell_pair {
public:
   statement();
   statement(cell* leftSide, cell* rightSide);
   cell& left();
   cell& right();
   cell* leftPtr();
   cell* rightPtr();
   friend std::ostream& operator<<(std::ostream& os, const statement& s);
};
}
