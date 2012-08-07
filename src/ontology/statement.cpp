#include "statement.h"

namespace mbdev_ontology {

statement::statement() : cell_pair() {
}

statement::statement(cell* leftSide, cell* rightSide) : cell_pair(leftSide, rightSide) {
}

cell& statement::left() {
   return *first;
}

cell& statement::right() {
   return *second;
}

cell* statement::leftPtr() {
   return first;
}

cell* statement::rightPtr() {
   return second;
}

std::ostream& operator<<(std::ostream& os, const statement& s) {
   os << *(s.first);
   os << "->";
   os << *(s.second);
   return os;
}

}
