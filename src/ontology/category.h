#pragma once
#include "mbdev/string.h"
#include "ontology/node.h"

using namespace mbdev;

namespace mbdev_ontology {

/*!
  \brief Defines a property than an Element can have.
  */
class category : public node {
public:
   category(string& name);
   category(string& name, string& friendlyName);
};

}
