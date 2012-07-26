#include "node.h"

Node::Node(std::string& name) {
   this->name = name;
   this->friendlyName = name;
}

Node::Node(std::string& name, std::string& friendlyName) {
   this->name = name;
   this->friendlyName = friendlyName;
}

std::string Node::getName() const {
   return name;
}

void Node::setName(std::string& name) {
   this->name = name;
}

std::string Node::getFriendlyName() const {
   return friendlyName;
}

void Node::setFriendlyName(std::string& friendlyName) {
   this->friendlyName = friendlyName;
}

std::ostream& operator<<(std::ostream& os, const Node& n) {
   os << n.getName();
   if(n.getFriendlyName().compare(n.getName()) == 0)
      return os;
   os << "(" << n.getFriendlyName() << ')';
   return os;
}
