#pragma once

#include <ostream>
#include <sstream>
#include <stdexcept> //for std::runtime_error
#include <string>
#include "ontology/category.h"
#include "ontology/element.h"
#include "ontology/cell.h"
#include "ontology/statement.h"
#include "mbdev/vector.h"
#include "mbdev/ptr_vector.h"
#include "mbdev/string_vector.h"

#ifdef DEBUG
// includes only for debugging
#include <iostream>
#endif

using namespace mbdev;

namespace mbdev_ontology {

class cell;
class statement;

// used to store property-element pair into a cell
//typedef std::pair<Category*, Element*> ElementPair;
//used to store all statements of an ontology
//typedef  StatementVector;
//typedef std::vector<ElementPair*> ElementPairVector;
//typedef std::multimap<ElementPairVector*, ElementPairVector*> StatementMap;
/*!
  \brief A network of possibly connected concepts. Concepts are organized into Elements,
   and these are organized into Categories. Each Element belongs to exactly one Category.
   Elements are then joined together into groups called Cells. A Cell contains at most one element
   of every category defined in the ontology.
  */
class ontology {
private:
   /*!
      \brief List of categories that any single node can have.
      */
   ptr_vector<category> categories;
   /*!
      \brief Defines names of elements supported by this ontology.
      */
   ptr_vector<element> elements;
   /*!
      \brief Stores concepts currently existing in this ontology.
      */
   ptr_vector<cell> cells;
protected:
   /*!
     \brief List of statements that makes up the ontology.
     */
   ptr_vector<statement> statements;
public:
#ifdef DEBUG
   static bool debugMode;
#endif
   /*!
     \brief Constructs an empty ontology.
     */
   ontology();
   //ontology(const char* categories);
//   /*!
//     \brief Constructs an ontology that has given categories.
//     \param categories array of names of the categories
//     */
//   ontology(string_vector& categories);
   /*!
     \brief Adds a new property to the ontology definitions list.
     \param name name of the new property
     */
   string addCategory(string& name);
   /*!
     \brief Adds multiple categories at once.
     */
   string addCategories(string_vector& names);
   /*!
     \brief Adds a new element to the ontology definitions list.
     \param kind property, to which given value will be assigned
     \param name name of the new element
     */
   string addElement(string& kind, string& name);
   string addElements(string& kind, string_vector& names);
   /*!
     \brief Adds a cell to the list of defined cells.
     \param cell
     \return address of a cell that was actually stored in the ontology
     */
   cell* addCell(const cell& cell);
   /*!
     \brief
     */
   string addStatement(cell& left, cell& right);
   /*!
     \brief Looks for a category that has the given name and returns its address.
     */
   category* findCategory(const string& name);
   /*!
     \brief Looks for an element that has the given name and returns its address.
     */
   element* findElement(const string& name);
   /*!
     \brief Looks for cells that are matching the given one
      and returns their address.
     */
   ptr_vector<cell> findCells(const cell& matching, bool exact = false);
   /*!
     \brief Looks for a category that has the given name and returns its address.
     */
   ptr_vector<statement> findStatements(statement& matching,
                                  bool ignoreTransitivity = false);
   string_vector getCategories() const;
   string_vector getElements() const;
   string_vector getCells() const;
   string toString() const;
   friend std::ostream& operator<<(std::ostream& os, const ontology& o);
};

std::ostream& operator<<(std::ostream& os, const ptr_vector<category>& vec);
std::ostream& operator<<(std::ostream& os, const ptr_vector<element>& vec);
std::ostream& operator<<(std::ostream& os, const ptr_vector<cell>& vec);
std::ostream& operator<<(std::ostream& os, const ptr_vector<statement>& vec);

}
