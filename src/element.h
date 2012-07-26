#pragma once
#include <ostream>
#include <vector>
#include "node.h"
#include "category.h"

class Element;

typedef Element Elem;

/*!
  \brief Element stores a value of a specific Category. Value may affect other values of the Cell
   containing it, as well as Cells connected to the above mentioned cell.
  */
class Element: public Node
{
protected:
   /*!
     \brief determines what kind of Element it is i.e. 'thing', 'situation', etc.
     */
   Category* category;
   /*!
     \brief determines if this element is transitive, i.e. if:
      1) three Cells are connected like a->b->c
      2) both Cell a and Cell b have this element in them
      then the ontology interprets this as if there was a connection between a and c (a->c)

      example ontology: "add category obj" "add category relation" "add obj a" "add obj b"
         "add obj c" "add relation is" "set is transitive" "a is: b" "b is: c"
      query: "find all that is c"
      program responds: "[obj:a, obj:b]"
     */
   bool transitive;
public:
   Element(std::string& name, Category* category, bool transitive = false);
   Element(std::string& name, std::string& friendlyName, Category* category, bool transitive = false);
   Category getCategory() const;
   bool isTransitive() const;
   void setTransitive(bool isTransitive);
   friend std::ostream& operator<<(std::ostream& os, const Element& e);
};
