#include "element.h"

namespace mbdev_ontology {

element::element(string& name, category *cat, bool transitive)
   : node(name), cat(cat), transitive(transitive) {
}

element::element(string& name, string& friendlyName, category* cat, bool transitive)
   : node(name, friendlyName), cat(cat), transitive(transitive) {
}

category element::getCategory() const {
   return *cat;
}

category* element::getCategoryPtr() {
   return cat;
}

bool element::isTransitive() const {
   return transitive;
}

void element::setTransitive(bool isTransitive) {
   this->transitive = isTransitive;
}

std::ostream& operator<<(std::ostream& os, const element& e) {
   os << e.getCategory();
   if(e.isTransitive())
      os << "+transitive";
   os << ':';
   os << e.getName();
   if(e.getFriendlyName().equals(e.getName()))
      return os;
   os << '(' << e.getFriendlyName() << ')';
   return os;
}

}
