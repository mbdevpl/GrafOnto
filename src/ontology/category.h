#pragma once
#include "mbdev/string.h"
#include "ontology/node.h"

using namespace mbdev;

namespace mbdev_ontology {

/*!
  \brief Defines a property than an element can have.
  */
class category : public node {
private:
//   /*!
//     \brief Determines if this category is a relation.

//     This has severe consequences:

//     1) statements can contain only one relation, and only on left side,
//     i.e. if we have a statement a->b, cell a must contain an element of this category
//     */
//   bool is_relation;
public:
   category(string& name/*, bool is_relation = false*/);
   category(string& name, string& friendlyName/*, bool is_relation = false*/);
//   bool isRelation() const;
//   void setRelation(bool is_relation);
};

}
