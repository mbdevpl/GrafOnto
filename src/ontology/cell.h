#pragma once
#include <map>
#include "ontology/category.h"
#include "ontology/element.h"
#include "ontology/ontology.h"

namespace mbdev_ontology {

class ontology;

typedef std::pair<category* const, element*> cell_element;
typedef std::map<category*, element*> category_element_map;

/*!
  \brief Used to store a set of elements, each of which belonging to
   a different category. Uses a map: a structure that contains at most one value
   for each category defined in the ontology.
  */
class cell : public category_element_map {
public:
   cell();
   cell(const string_vector& vec, ontology& onto);
   void insert(element* e);
   void insert(category* c, element* e);
   friend std::ostream& operator<<(std::ostream& os, const cell& c);
};

}
