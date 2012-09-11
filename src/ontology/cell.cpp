#include "cell.h"

namespace mbdev_ontology {

cell::cell() : category_element_map() {
}

cell::cell(const string_vector& vec, ontology& onto)
   : category_element_map() {
   size_t size = vec.size();
   for(size_t i=0; i<size; i++) {
      element* e = onto.findElement(vec[i]);
      if(e == nullptr) {
         std::stringstream s;
         s << "'" << vec[i] << "'";
         s << " - no such element defined";
         throw std::runtime_error(s.str().c_str());
      }
      //category* c = e->getCategoryPtr(); //onto.findCategory(.getName());
      this->insert(e);
   }
}

void cell::insert(element* e) {
   category_element_map::insert(cell_element(e->getCategoryPtr(), e));
}

void cell::insert(category* c, element* e) {
   cell::iterator it = this->find(c);
   if(it == this->end()) {
      category_element_map::insert(cell_element(c, e));
      return;
   }
   std::stringstream s;
   s << "cannot add element " << *e;
   s << " - cell already contains an element of category ";
   s << "'" << *c << "'";
   throw std::runtime_error(s.str().c_str());
}

string cell::str()
{
   std::stringstream ss;
   ss << *this;
   return ss.str();
}

std::ostream& operator<<(std::ostream& os, const cell& c) {
   int size = c.size() - 1;
   int i;
   os << '[';
   if(size >= 0) {
      cell* map2p = (cell*)&c;
      cell& map2 = *map2p;
      cell::iterator it;
      for (i = 0, it = map2.begin(); it != map2.end(); ++it, i++) {
         os << (it->first)->getName().substr(0,1) << ':';
         os << (it->second)->getName();
         if(i < size)
            os << ',';
      }
   }
   os << ']';
   return os;
}

}
