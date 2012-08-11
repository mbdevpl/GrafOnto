#pragma once
// general includes
#include <iostream>
#include "mbdev/string.h"
#include "mbdev/string_vector.h"
#include "ontology/ontology.h"
//Qt gui
#include <QString>
#include <QtGui/QApplication>
#include "mainwindow.h"

#include "mbdev/console_application.h" //text mode

using namespace mbdev;
using namespace mbdev_ontology;

class grafonto : public console_application {
private:
   /*!
     \brief List of reserved words.
     */
   string_vector reserved;
   bool textMode;
   bool interactiveMode;
   ontology onto;
protected:
   string executeAdd(string_vector& arguments);
   string executeSet(string_vector& arguments);
   string executeDelete(string_vector& arguments);
   string executeFind(string_vector& arguments);
   string executeLoad(string_vector& arguments);
   string executeSave(string_vector& arguments);
   string executeStatement(string_vector& arguments);
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
   grafonto(int argc, char *argv[]);
   virtual int exec();
   int text_mode();
   int gui_mode();
   inline QString executeQt(const QString& command);
};

inline QString grafonto::executeQt(const QString& command) {
   return QString(execute(command.toStdString()).c_str());
}
