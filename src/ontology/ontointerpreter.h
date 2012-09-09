#pragma once
// general includes
#include <iostream>
#include "mbdev/string.h"
#include "mbdev/string_vector.h"
#include "ontology/ontology.h"

#include "mbdev/console_application.h" //text mode

using namespace mbdev;

namespace mbdev_ontology {

/*!
  \brief console application coupled with a command interpreter,
  which can be used as just an interpreter and console may be handled
  completely by external class, in GrafOnto gui it is the ConsoleSimulator.
  */
class ontointerpreter {
private:
   ontology& onto;
   /*!
     \brief List of reserved words - those cannot be used as category
     and element names, but may be contained inside anywhere in them
     as their part.
     */
   string_vector keywords;
   /*!
     \brief List of strings that cannot occur anywhere inside the names
     of categories and elements.
     */
   string_vector disallowed;
   /*!
     \brief List of disallowed starting sequences of characters
     - elements and category names cannot start with those.
     */
   string_vector disallowedStarts;
#ifdef DEBUG
public:
   static bool debugMode;
#endif
public:
   // main constructor
   ontointerpreter(ontology& onto);
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
   string execute(const string& command);
   string getClue(const string& current);
   string_vector prepareDemo();
private:
   void initialize();
   string executeAdd(string_vector& arguments);
   string executeSet(string_vector& arguments);
   string executeDelete(string_vector& arguments);
   string executeFind(string_vector& arguments);
   string executeLoad(string_vector& arguments);
   string executeSave(string_vector& arguments);
   string executeStatement(string_vector& arguments);
};

}
