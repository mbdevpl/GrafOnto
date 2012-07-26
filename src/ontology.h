#pragma once
#include <iostream> // only for debugging
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "element.h"
#include "category.h"
#include "strings.h"

#ifndef nullptr
#define nullptr NULL
#endif

class Ontology;

typedef Ontology Onto;

// used to store property definitions
typedef std::vector<Category*> CategoryVector;

// used to store the element definitions
typedef std::vector<Element*> ElementVector;

// used to store property-element pair into a cell
typedef std::pair<Category*, Element*> ElementPair;

/*!
  \brief Used to store a set of elements, each of which belonging to
   a different category. Uses a map: a structure that contains at most one value
   for each category defined in the ontology.
  */
typedef std::map<Category*, Element*> Cell;

//used to store all cells present in an ontology
typedef std::vector<Cell*> CellVector;

/*!
  \brief Used to store a single statement of an ontology. Statement is a pair of cells.
  */
typedef std::pair<Cell*, Cell*> Statement;

//used to store all statements of an ontology
typedef std::vector<Statement*> StatementVector;

//typedef std::pair<Property*, Element*> ElementPair;

//typedef std::vector<ElementPair*> ElementPairVector;

//typedef std::multimap<ElementPairVector*, ElementPairVector*> StatementMap;

/*!
  \brief A network of possibly connected concepts. Concepts are organized into Elements,
   and these are organized into Categories. Each Element belongs to exactly one Category.
   Elements are then joined together into groups called Cells. A Cell contains at most one element
   of every category defined in the ontology.
  */
class Ontology
{
private:
   /*!
      \brief List of categories that any single node can have.
      */
   CategoryVector categories;
   /*!
      \brief Defines names of elements supported by this ontology.
      */
   ElementVector elements;
   /*!
      \brief Stores concepts currently existing in this ontology.
      */
   CellVector cells;
protected:
   /*!
     \brief List of statements that makes up the ontology.
     */
   StatementVector statements;
public:
   /*!
     \brief List of reserved words.
     */
   static const char* Reserved[];
   /*!
     \brief Constructs an empty ontology.
     */
   Ontology();
   /*!
     \brief Constructs an ontology that has given categories.

     \param categories array of names of the categories
     */
   Ontology(const char* categories);

   Ontology(const std::string& categories);
   /*!
     \brief Executes a command on the ontology.

     \param command natural language command given as a parameter, which is parsed, analyzed
      and executed; operation is aborted in case of any error in command; example commands:
      to add a category 'thing': \code add category thing \endcode
      to delete a category 'thing': \code delete category thing \endcode
      to add an element of category 'thing', named 'car' \code add thing car \endcode
      to add a relation 'is' (assuming category named 'relation' exists):
         \code add relation is \endcode
      to make relation 'is' transitive: \code set is transitive \endcode
      to make relation 'is' not transitive (which is a default
         for every element): \code set is not transitive \endcode
      to add a connection (assuming things 'car' and 'vehicle' exist, and relation 'is' exists):
         \code car is: vehicle \endcode
      to find every element that 'is animal': \code find all that is animal \endcode
      to find every 'thing' that 'has wings': \code find thing that has wings \endcode
     \return result of the command, which non-empty only in case of queries. queries are done
      using 'find' keyword, for example, given an ontology:
      \code add category (obj, relation)
      add obj (a, b, c)
      add relation is
      set is transitive
      a is: b
      b is: c\endcode
      by executing the command \code find all that is c \endcode
      program returns \code a, b \endcode
     */
   std::string execute(const char* command);
   /*!
     \see execute(const char*)
     */
   std::string execute(const std::string& command);

   std::string executeAdd(std::vector<std::string>& parameters);

   std::string executeSet(std::vector<std::string>& parameters);

   std::string executeFind(std::vector<std::string>& parameters);
   /*!
     \brief Adds a new property to the ontology definitions list.

     \param name name of the new property
     */
   void addCategory(std::string& name);

   void addCategories(const std::string& categories);
   /*!
     \brief Adds a new element to the ontology definitions list.

     \param kind property, to which given value will be assigned
     \param name name of the new element
     */
   void addElement(std::string& kind, std::string& name);
   /*!
     \brief Adds a cell to the list of defined cells.

     \param cell
     \return address of a cell that was actually stored in the ontology
     */
   Cell* addCell(const Cell& cell);

   void addStatement(Cell& left, Cell& right);

   Category* findCategory(const std::string& name);

   Element* findElement(const std::string& name);

   CellVector findCells(Cell& matching, bool exact = false);

   StatementVector findStatements(Statement& matching,
                                  bool ignoreTransitivity = false);

   //std::vector<Element*>& getElems();
   //int getElemsSize() const;
   //Element& getElem(int index);
   //Element getElemCopy(int index) const;

   friend std::ostream& operator<<(std::ostream& os, const Ontology& o);
   std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const CategoryVector& vec);
std::ostream& operator<<(std::ostream& os, const ElementVector& vec);
std::ostream& operator<<(std::ostream& os, const Cell& map);
std::ostream& operator<<(std::ostream& os, const CellVector& vec);
std::ostream& operator<<(std::ostream& os, const Statement& pai);
std::ostream& operator<<(std::ostream& os, const StatementVector& vec);

//std::ostream& operator<<(std::ostream& os, const ElementPair& ep);
//std::ostream& operator<<(std::ostream& os, const ElementPairVector& epv);
