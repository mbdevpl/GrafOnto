#include "ontology.h"

namespace mbdev_ontology {

#ifdef DEBUG
bool ontology::debugMode = false;
#endif

ontology::ontology() {
}

//ontology::ontology(const char* categories) {
//   addCategories(std::string(categories));
//}

//Ontology::Ontology(const std::string& categories) {
//   addCategories(categories);
//}

string ontology::addCategory(string& name) {
   if(findCategory(name) != nullptr)
      throw std::runtime_error("cannot add category with the same name as one already existing");
   category* c = new category(name);
   categories.push_back(c);
   std::stringstream s;
   s << "added category " << *c;
   return string(s.str());
}

string ontology::addCategories(string_vector& names) {
   size_t size = names.size();
   if(size == 0)
      throw std::runtime_error("list of categories is empty");
   std::stringstream ss;
   for(size_t i=0; i<size; i++) {
      ss << addCategory(names[i]);
      if(i < size - 1)
         ss << ", ";
   }
   return ss.str();
}

string ontology::addElement(string& kind, string& name) {
   if(findElement(name) != nullptr)
      throw std::runtime_error("cannot add element with already existing name");
   category* p = findCategory(kind);
   if(p == nullptr)
      throw std::runtime_error("cannot add element of a non-existing category");
   element* e = new element(name, p);
   elements.push_back(e);
   std::stringstream s;
   s << "added element " << *e;
   return s.str();
}

string ontology::addElements(string& kind, string_vector& names) {
   if(kind.length() == 0)
      throw std::runtime_error("not given any element category");
   size_t size = names.size();
   if(size == 0)
      throw std::runtime_error("list of elements is empty");
   std::stringstream ss;
   for(size_t i=0; i<size; i++) {
      ss << addElement(kind, names[i]);
      if(i < size - 1)
         ss << ", ";
   }
   return ss.str();
}

cell* ontology::addCell(const cell& c) {
   ptr_vector<cell> found = findCells(c, true);
   if(found.size() == 1)
      return found[0];
   if(found.size() > 1) {
      std::stringstream ss;
      ss << "found more than one identical cell";
      ss << " when adding: " << c;
      throw std::runtime_error(ss.str().c_str());
   }
   cell* ce = new cell(c);
   cells.push_back(ce);
   return ce;
}

string ontology::addStatement(cell& left, cell& right) {
   cell* leftPtr = addCell(left);
   cell* rightPtr = addCell(right);
   statement* s = new statement(leftPtr, rightPtr);
   ptr_vector<statement> v = findStatements(*s, true);
   for(unsigned int i=0; i<v.size(); i++) {
      const statement& st = *(v[i]);
      if(st.first == leftPtr && st.second == rightPtr)
         throw std::runtime_error("statement already exists in the ontology");
   }
   statements.push_back(s);
   return "added a statement";
}

category* ontology::findCategory(const string& name) {
   int len = categories.size();
   for(int i=0; i<len; i++) {
      if(name.compare(categories[i]->getName()) == 0)
         return categories[i];
   }
   return nullptr;
}

element* ontology::findElement(const string& name) {
   int len = elements.size();
   for(int i=0; i<len; i++) {
      if(name.compare(elements[i]->getName()) == 0)
         return elements[i];
   }
   return nullptr;
}

ptr_vector<cell> ontology::findCells(const cell& matching, bool exact) {
#ifdef DEBUG
   if(debugMode) {
      std::cout << "looking for cells " << (exact?"exactly ":"~") << "matching ";
      std::cout << matching << ":";
      //std::cout.flush();
   }
#endif
   cell& matched = *((cell*)&matching); //conversion to non-const ref.
   ptr_vector<cell> results;
   size_t size = cells.size();
   if(size == 0)
      return results;
   if(matching.size() == 0) { // returning all cells
      if(exact)
         return results; // or none, if exact matching
      for(size_t i=0; i<size; i++)
         results.push_back(cells[i]);
      return results;
   }

   cell::iterator it;
   for(size_t n=0; n<size; n++) {
      cell& c = *cells[n];
#ifdef DEBUG
      if(debugMode) {
         std::cout << " " << c << "?";
         std::cout.flush();
      }
#endif
      bool found = true;
      if(exact && matching.size() != c.size())
         continue;
      for (it = matched.begin(); it != matched.end(); ++it) {
         cell::iterator itt = c.find(it->first);
         if(itt == c.end()) {
            found = false;
            break;
         }
         element* e = itt->second;
         if(e->getName().compare(it->second->getName())) {
            found = false;
            break;
         }
      }
      if(!found)
         continue;
      results.push_back(&c);
#ifdef DEBUG
      if(debugMode) {
         std::cout << "yes";// << "\n";
         std::cout.flush();
      }
#endif
   }
#ifdef DEBUG
   if(debugMode) {
      std::cout << " fin.\n";
      std::cout.flush();
   }
#endif
   return results;
}

ptr_vector<cell> ontology::findCells() {
   return findCells(cell(), false);
}

ptr_vector<statement> ontology::findStatements(statement& matching,
                                               bool ignoreTransitivity) {
   ptr_vector<statement> results;
   size_t size = statements.size();
   if(size == 0)
      return results;
   ptr_vector<cell> left = findCells(*(matching.first));
   size_t sizeL = left.size();
   ptr_vector<cell> right = findCells(*(matching.second), true);
   size_t sizeR = right.size();
   if(sizeL == 0 || sizeR == 0)
      return results;

#ifdef DEBUG
   if(debugMode) {
      std::cout << "looking for statements matching ";
      std::cout << matching << ": ";
      std::cout.flush();
   }
#endif
   for(size_t n=0; n<size; n++) {
      for(size_t l=0; l<sizeL; l++) {
         for(size_t r=0; r<sizeR; r++) {
            if(left[l] != statements[n]->first)
               continue;
            if(right[r] != statements[n]->second) {
               //#ifdef DEBUG
               // // print addresses
               // std::cout << left[i] << ' ' << right[j] << " ";
               // std::cout << statements[n]->first << "->" << statements[n]->second << "\n";
               // std::cout.flush();
               //#endif
               continue;
            }
#ifdef DEBUG
            if(debugMode) {
               // print plaintext
               std::cout << " (" << *left[l] << ' ' << *right[r] << ")";
               std::cout << " " << *statements[n];
               std::cout.flush();
            }
#endif
            results.push_back(statements[n]);
         }
      }
   }
   if(ignoreTransitivity) {
#ifdef DEBUG
      if(debugMode) {
         std::cout << "\n";
         std::cout.flush();
      }
#endif
      return results;
   }
   // transitivity handling
#ifdef DEBUG
   if(debugMode) {
      std::cout << " now using transitivity:";
      std::cout.flush();
   }
#endif
   size_t sizeRes = results.size();
   if(sizeRes == 0)
      return results;
   cell& base = matching.left();
   // find all transitive elements of the original left side
   for(cell::iterator it = base.begin(); it != base.end(); it++) {
      cell_element& elem = *it;
      element& e = *(elem.second); //second of pair (category,element)
      if(e.isTransitive()) {
         // found transitive element
#ifdef DEBUG
         if(debugMode) {
            std::cout << " checking " << e;
            std::cout.flush();
         }
#endif
         // find all the statements that have:
         for(size_t i = 0; i<sizeRes; i++) {
            statement& st = *(results[i]);
#ifdef DEBUG
            if(debugMode) {
               std::cout << " st=" << st;
            }
#endif
            // a) the left side:
            //    having the transitive element, but without any other constraints
            //    like exact matches etc.
            cell l;
            l.insert(&e);
#ifdef DEBUG
            if(debugMode) {
               std::cout << " l=" << l;
            }
#endif
            // b) the right side  (i.e. consequence):
            //    exactly equal to the left side of current matching statements
            //    with the transitive element taken out
            cell r(st.left());
            cell::iterator cat = r.find(e.getCategoryPtr());
            if(cat == r.end())
               throw std::runtime_error("transitive element was not found on the left side of statement"
                                        " that was transformed while doing transitive search");
            r.erase(cat);
#ifdef DEBUG
            if(debugMode) {
               std::cout << " r=" << r;
               std::cout << " ..." << std::endl;
            }
#endif
            statement stat(&l, &r);
            ptr_vector<statement> moreResults = findStatements(stat, false);
#ifdef DEBUG
            if(debugMode) {
               std::cout << std::endl;
               std::cout << "... found by transitivity: {";
               std::cout << moreResults;
               std::cout << "}" << std::endl;
               std::cout.flush();
            }
#endif
            size_t sizeResMore = moreResults.size();
            for(size_t j = 0; j<sizeResMore; j++) {
               if(results.indexOf(moreResults[j]) < 0)
                  results.push_back(moreResults[j]);
            }
         }
      }
      //if()
   }
#ifdef DEBUG
   if(debugMode) {
      std::cout << "\n";
      std::cout.flush();
   }
#endif
   return results;
}

string_vector ontology::getCategories() const {
   string_vector vec;
   for(unsigned int i=0; i<categories.size(); i++)
      vec.push_back(categories[i]->getName());
   return vec;
}

string_vector ontology::getElements() const {
   string_vector vec;
   for(unsigned int i=0; i<elements.size(); i++)
      vec.push_back(elements[i]->getName());
   return vec;
}

string_vector ontology::getCells() const {
   string_vector vec;
   for(unsigned int i=0; i<cells.size(); i++) {
      const cell& c = *(cells[i]);
      std::stringstream s;
      s << c;
      vec.push_back(s.str());
   }
   return vec;
}

std::ostream& operator<<(std::ostream& os, const ontology& o) {
   os << o.toString().c_str();
   return os;
}

string ontology::toString() const {
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

std::ostream& operator<<(std::ostream& os, const ptr_vector<category>& vec) {
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

std::ostream& operator<<(std::ostream& os, const ptr_vector<element>& vec) {
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

std::ostream& operator<<(std::ostream& os, const ptr_vector<cell>& vec) {
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

std::ostream& operator<<(std::ostream& os, const ptr_vector<statement>& vec) {
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

}
