#pragma once
#include "mbdev/console_application.h"
#include "ontology/ontointerpreter.h"

using namespace mbdev;
using namespace mbdev_ontology;

class OntoConsoleInterpreter : public console_application {
private:
   ontointerpreter interpreter;
   bool interactiveMode;
   bool demoMode;
protected:
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
   virtual string execute(const string& command);
   virtual string getClue(const string& current);
public:
   // constructor
   OntoConsoleInterpreter(int argc, char *argv[], ontology& onto);
   virtual int exec();
   int execDemo(const string_vector& demo);
   // returns a list of example commands, they are all ready for execution
   string_vector prepareDemo();
   bool getDemoMode();
};
