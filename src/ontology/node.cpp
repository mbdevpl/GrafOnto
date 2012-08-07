#include "node.h"

namespace mbdev_ontology {

node::node(string& name) {
   this->name = name;
   this->friendlyName = name;
}

node::node(string& name, string& friendlyName) {
   this->name = name;
   this->friendlyName = friendlyName;
}

string node::getName() const {
   return name;
}

void node::setName(string& name) {
   this->name = name;
}

string node::getFriendlyName() const {
   return friendlyName;
}

void node::setFriendlyName(string& friendlyName) {
   this->friendlyName = friendlyName;
}

std::ostream& operator<<(std::ostream& os, const node& n) {
   os << n.getName();
   if(n.getFriendlyName().equals(n.getName()))
      return os;
   os << "(" << n.getFriendlyName() << ')';
   return os;
}

}
