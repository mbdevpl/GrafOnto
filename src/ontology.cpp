#include "ontology.h"

const char* Ontology::Reserved[] = {"add", "set", "delete", "find", "load", "save",
                                    "category", "all", "not", "transitive"};

Ontology::Ontology() {
}

Ontology::Ontology(const char* categories) {
   addCategories(std::string(categories));
}

Ontology::Ontology(const std::string& categories) {
   addCategories(categories);
}

std::string Ontology::execute(const char* command) {
   return execute(std::string(command));
}

std::string Ontology::execute(const std::string& command) {
   try {
      if(command.length() == 0)
         throw std::runtime_error("empty command");
      std::vector<std::string> parsed = Strings::stringToArray(command,' ');
      Strings::trimVector(parsed);
      Strings::cleanseVector(parsed);
      int len = parsed.size();
      if(len == 0)
         throw std::runtime_error("empty command");

      std::string& s0 = parsed[0];
      if(!s0.compare("add")) return executeAdd(parsed);
      if(!s0.compare("set")) return executeSet(parsed);

      if(s0.compare("delete") == 0) {
         //TODO: deleting things
         return "error: not_implemented";
      }

      if(!s0.compare("find")) return executeFind(parsed);

      if(s0.compare("load") == 0) {
         return "error: not_implemented";
      }

      if(s0.compare("save") == 0) {
         return "error: not_implemented";
      }

      //handling of natural language
      std::vector<std::string> half = Strings::stringToArray(command,':');
      Strings::trimVector(half);
      int vecLen;
      std::vector<std::string> leftVec = Strings::stringToArray(half[0],' ');
      Strings::trimVector(leftVec);
      Cell* left = new Cell();
      vecLen = leftVec.size();
      for(int i=0; i<vecLen; i++) {
         Element* e = findElement(leftVec[i]);
         if(e == nullptr)
            return "error"; //no such element defined
         Category* p = findCategory(e->getCategory().getName());
         left->insert(ElementPair(p,e));
      }

      std::vector<std::string> rightVec = Strings::stringToArray(half[1],' ');
      Strings::trimVector(rightVec);
      Cell* right = new Cell();
      vecLen = rightVec.size();
      for(int i=0; i<vecLen; i++) {
         Element* e = findElement(rightVec[i]);
         if(e == nullptr)
            return "error"; //no such element defined
         Category* p = findCategory(e->getCategory().getName());
         right->insert(ElementPair(p,e));
      }
      addStatement(*left, *right);
      return "added statement?";
   } catch (std::runtime_error e) {
      std::stringstream ss;
      ss << "execution error with command '";
      ss << command;
      ss << "': ";
      ss << e.what();
      throw std::runtime_error(ss.str().c_str());
   }
}

std::string Ontology::executeAdd(std::vector<std::string>& parameters) {
   int len = parameters.size();
   if(len != 3) {
      //TODO: adding multiple objects: many properties at the same time etc.
      return "error: not_implemented";
   }
   std::string& s1 = parameters[1];
   std::string& s2 = parameters[2];
   if(s1.compare("category") == 0) {
      addCategory(s2);
      return "added?";
   }
   // adding element of given kind
   addElement(s1, s2);
   return Strings::EmptyString;
}

std::string Ontology::executeSet(std::vector<std::string>& parameters) {
   int len = parameters.size();
   if(len < 3)
      throw std::runtime_error("too few arguments");
   std::string& s1 = parameters[1];
   std::string& s2 = parameters[2];
   Element* e = findElement(s1);
   if(e == nullptr)
      throw std::runtime_error("cannot set parameter of non-existing element");
   if(len == 3) {
      if(!s2.compare("transitive"))
         e->setTransitive(true);
      else
         throw std::runtime_error("missing keyword 'transitive'");
   }
   if(len == 4) {
      if(!s2.compare("not") && !parameters[3].compare("transitive"))
         e->setTransitive(false);
      else
         throw std::runtime_error("missing keywords 'not transitive'");
   }
   return Strings::EmptyString;
}

std::string Ontology::executeFind(std::vector<std::string>& parameters) {
   int size = parameters.size();
   std::string& s1 = parameters[1];
   std::string& s2 = parameters[2];
   Category* cat = nullptr;
   if(s1.compare("all")) {
      cat = findCategory(s1);
      if(cat == nullptr)
         throw std::runtime_error("cannot find the element from a non-existing category");
   }

   if(s2.compare("that"))
      throw std::runtime_error("missing keyword 'that'");

   if(size < 4)
      throw std::runtime_error("too few arguments");

   std::stringstream ss;
   for(int i=3; i<size; i++)
      ss << parameters[i] << ' ';
   std::string str = ss.str();
   Strings::trim(str);

   // split the statement into left and right parts
   std::vector<std::string> vec = Strings::stringToArray(str, ':');
   Strings::trimVector(vec);
   if(vec.size() != 2)
      throw std::runtime_error("searched statement must have exactly two parts");

   // left hand side
   std::vector<std::string> vecL = Strings::stringToArray(vec[0], ' ');
   Strings::trimVector(vecL);
   Strings::cleanseVector(vecL);
   Cell left;
   for(int i=0; i<vecL.size(); i++) {
      Element* e = findElement(vecL[i]);
      Category* c = findCategory(e->getCategory().getName());
      ElementPair p(c,e);
      left.insert(p);
   }

   // right hand side
   std::vector<std::string> vecR = Strings::stringToArray(vec[1], ' ');
   Strings::trimVector(vecR);
   Strings::cleanseVector(vecR);
   Cell right;
   for(int i=0; i<vecR.size(); i++) {
      Element* e = findElement(vecR[i]);
      Category* c = findCategory(e->getCategory().getName());
      ElementPair p(c,e);
      right.insert(p);
   }

   //looking for any matching statements
   Statement s(&left, &right);
   findStatements(s);

   return Strings::EmptyString;
}

void Ontology::addCategory(std::string& name) {
   if(findCategory(name) != nullptr)
      return; //cannot add the category with the same name
   Category* p = new Category(name);
   categories.push_back(p);
}

void Ontology::addCategories(const std::string& categories) {
   if(categories.length() == 0)
      return;
   std::vector<std::string> parsed = Strings::stringToArray(categories,',');
   Strings::trimVector(parsed);
   Strings::cleanseVector(parsed);
   int size = parsed.size();
   if(size == 0)
      return;
   for(int i=0; i<size; i++) {
      addCategory(parsed[i]);
   }
}

void Ontology::addElement(std::string& kind, std::string& name) {
   if(findElement(name) != nullptr)
      return; //cannot redefine the element
   Category* p = findCategory(kind);
   if(p == nullptr)
      return; //cannot add element of a non-existing kind
   Element* e = new Element(name, p);
   elements.push_back(e);
}

Cell* Ontology::addCell(const Cell& cell) {
   Cell* c = new Cell(cell);
   cells.push_back(c);
   return c;
}

void Ontology::addStatement(Cell& left, Cell& right) {
   Cell* leftPtr = addCell(left);
   Cell* rightPtr = addCell(right);
   Statement* s = new Statement(leftPtr, rightPtr);
   statements.push_back(s);
}

Category* Ontology::findCategory(const std::string& name) {
   int len = categories.size();
   for(int i=0; i<len; i++) {
      if(name.compare(categories[i]->getName()) == 0)
         return categories[i];
   }
   return nullptr;
}

Element* Ontology::findElement(const std::string& name) {
   int len = elements.size();
   for(int i=0; i<len; i++) {
      if(name.compare(elements[i]->getName()) == 0)
         return elements[i];
   }
   return nullptr;
}

CellVector Ontology::findCells(Cell& matching, bool exact) {
   //std::cout << matching << "\n";
   //std::cout.flush();

   CellVector results;
   int size = cells.size();
   if(size == 0 || matching.size() == 0)
      return results;

   Cell::iterator it;
   for(int n=0; n<size; n++) {
      Cell& c = *cells[n];
      //std::cout << c << "\n";
      //std::cout.flush();
      bool found = true;
      for (it = matching.begin(); it != matching.end(); ++it) {
         Cell::iterator itt = c.find(it->first);
         if(itt == c.end()) {
            found = false;
            break;
         }
         Element* e = itt->second;
         if(e->getName().compare(it->second->getName())) {
            found = false;
            break;
         }
      }
      if(!found)
         continue;
      results.push_back(&c);
      //std::cout << "found" << "\n";
      //std::cout.flush();
   }
   return results;
}

StatementVector Ontology::findStatements(Statement& matching,
                                         bool ignoreTransitivity) {
   CellVector left = findCells(*(matching.first));
   CellVector right = findCells(*(matching.second), true);
   int sizeL = left.size();
   int sizeR = right.size();
   int size = statements.size();

   StatementVector results;
   for(int n=0; n<size; n++) {
      for(int i=0; i<sizeL; i++) {
         for(int j=0; j<sizeR; j++) {
            if(left[i] != statements[n]->first
                  || right[i] != statements[n]->second)
               continue;
            std::cout << *left[i] << ' ' << *right[j] << "\n";
            std::cout << *statements[n] << "\n";
            std::cout.flush();
         }
      }
   }
   //findStatement
   //if(ignoreTransitivity)
   //   return results;
   // transitivity handling
   return results;
}

//std::vector<Element*>& Ontology::getElems() {
//    return elems;
//}

//int Ontology::getElemsSize() const {
//    return elems.size();
//}

//Element& Ontology::getElem(int index) {
//    return *elems[index];
//}

//Element Ontology::getElemCopy(int index) const {
//    return Element(*elems[index]);
//}

std::ostream& operator<<(std::ostream& os, const Ontology& o) {
   os << o.toString().c_str();
   return os;
}

std::string Ontology::toString() const {
   std::stringstream s;
   s << "Categories: ";
   s << categories;
   s << "\n";
   s << "Elements: ";
   s << elements;
   s << "\n";
   s << "Cells: ";
   s << cells;
   s << "\n";
   s << "Statements: ";
   s << statements;
   s << "\n";
   return s.str();
}

std::ostream& operator<<(std::ostream& os, const CategoryVector& vec) {
   int size = vec.size() - 1;
   os << '[';
   for(int i = 0; i <= size ; i++) {
      os << *(vec[i]);
      if(i < size)
         os << ',';
   }
   os << ']';
   return os;
}

std::ostream& operator<<(std::ostream& os, const ElementVector& vec) {
   int size = vec.size() - 1;
   os << '[';
   for(int i = 0; i <= size ; i++) {
      os << *(vec[i]);
      if(i < size)
         os << ',';
   }
   os << ']';
   return os;
}

std::ostream& operator<<(std::ostream& os, const Cell& map) {
   int size = map.size() - 1;
   int i;
   os << '[';
   if(size >= 0) {
      Cell* map2p = (Cell*)&map;
      Cell& map2 = *map2p;
      Cell::iterator it;
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

std::ostream& operator<<(std::ostream& os, const CellVector& vec) {
   int size = vec.size() - 1;
   os << '[';
   for(int i = 0; i <= size ; i++) {
      os << *(vec[i]);
      if(i < size)
         os << ',';
   }
   os << ']';
   return os;
}

std::ostream& operator<<(std::ostream& os, const Statement& pai) {
   os << *(pai.first);
   os << "->";
   os << *(pai.second);
   return os;
}

std::ostream& operator<<(std::ostream& os, const StatementVector& vec) {
   int size = vec.size() - 1;
   os << '[';
   for(int i = 0; i <= size ; i++) {
      os << *(vec[i]);
      if(i < size)
         os << ',';
   }
   os << ']';
   return os;
}

//std::ostream& operator<<(std::ostream& os, const ElementPair& ep) {
//   os << ep.first->getName()[0] << ':' << ep.second->getName();
//   return os;
//}

//std::ostream& operator<<(std::ostream& os, const ElementPairVector& epv) {
//   //ElementPairVector& lhs = *(it->first);
//   int size = epv.size();
//   os << '(';
//   for(int i = 0; i <= size ; i++) {
//      ElementPair& p = *(epv[i]);
//      os << p;
//      if(i < size)
//         os << ',';
//   }
//   os << ')';
//   return os;
//}
