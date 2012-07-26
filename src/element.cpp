#include "element.h"

Element::Element(std::string& name, Category *category, bool transitive)
   : Node(name) {
   this->category = category;
   this->transitive = transitive;
}

Element::Element(std::string& name, std::string& friendlyName, Category* category, bool transitive)
   : Node(name, friendlyName) {
   this->category = category;
   this->transitive = transitive;
}

Category Element::getCategory() const {
   return *category;
}

bool Element::isTransitive() const {
   return transitive;
}

void Element::setTransitive(bool isTransitive) {
   this->transitive = isTransitive;
}

std::ostream& operator<<(std::ostream& os, const Element& e) {
   os << e.getCategory();
   if(e.isTransitive())
      os << "+transitive";
   os << ':';
   os << e.getName();
   if(e.getFriendlyName().compare(e.getName()) == 0)
      return os;
   os << '(' << e.getFriendlyName() << ')';
   return os;
}
