#include <QObject>
#include <QCoreApplication>
#include <iostream>
//#if (defined RELEASE || defined DEBUG)
//#endif
#include "console/ontoconsoleinterpreter.h"

/*!
  \brief Launches GrafOnto. There are several modes of operation possible. By default,
   simply interactive console is launched. For other options see argv parameter description.
  \param argc number of commandline arguments
  \param argv command line arguments
   \code -auto \endcode interprets all subsequent commands and then immediately exits
   the application
   fore example: \code -auto load 'db.txt'; john is: human; save 'db.txt' \endcode
   will load the file, add a statement to the ontology, save it under the same name, and exit
   \code -demo \endcode will load an example ontology at application startup it can be used
   in conjunction with any of the three: gui/text/none
  */
int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   std::cout << "GrafOntoConsole: text-mode ontology editor" << std::endl
             << "                 for interactive graphical visualisation" << std::endl
             << "                 of a categorial ontologies" << std::endl
             << "(C) 2012 Mateusz Bysiek, http://mbdev.pl/" << std::endl;
#ifdef RELEASE
   std::cout << "released under GNU General Public License version 3" << std::endl;
   std::cout << " running in release mode" << std::endl;
#endif
#ifdef DEBUG
   std::cout << " running in debug mode" << std::endl;
#endif
#ifdef LINUX
   std::cout << " linux version" << std::endl;
#endif
#ifdef WINDOWS
   std::cout << " windows version" << std::endl;
#endif
   ontology onto;
   OntoConsoleInterpreter interpreter(argc, argv, onto);
   int result = interpreter.exec();
   if(result!=0)
      return result;

   a.quit();
   //return a.exec();
   return 0;
}
