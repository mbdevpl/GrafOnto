#pragma once
#include <ostream>
#include <string>

#ifndef nullptr
#define nullptr NULL
#endif

/*!
  \brief Contains common behaviour of Element and Relation.
  */
class Node
{
protected:
   /*!
      \brief a name used to identify the object when using text mode
      */
   std::string name;
   /*!
      \brief name used when the object is displayed in graphical mode
      */
   std::string friendlyName;
public:
   Node(std::string& name);
   Node(std::string& name, std::string& friendlyName);
   std::string getName() const;
   void setName(std::string& name);
   std::string getFriendlyName() const;
   void setFriendlyName(std::string& freindlyName);
   friend std::ostream& operator<<(std::ostream& os, const Node& n);
};
