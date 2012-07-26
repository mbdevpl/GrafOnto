#pragma once
#include "node.h"

class Category;

typedef Category Cat;

/*!
  \brief Defines a property than an Element can have.
  */
class Category : public Node {
private:
public:
   Category(std::string& name);
   Category(std::string& name, std::string& friendlyName);
};
