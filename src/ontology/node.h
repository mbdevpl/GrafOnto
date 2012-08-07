#pragma once
#include <ostream>
#include "mbdev/string.h"

using namespace mbdev;

namespace mbdev_ontology {

/*!
  \brief Contains common behaviour of Element and Relation.
  */
class node {
protected:
   /*!
      \brief a name used to identify the object when using text mode
      */
   string name;
   /*!
      \brief name used when the object is displayed in graphical mode
      */
   string friendlyName;
public:
   node(string& name);
   node(string& name, string& friendlyName);
   string getName() const;
   void setName(string& name);
   string getFriendlyName() const;
   void setFriendlyName(string& freindlyName);
   friend std::ostream& operator<<(std::ostream& os, const node& n);
};

}
