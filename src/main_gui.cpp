#include <iostream>
#include <QtGui/QApplication>
#include "ontology/ontology.h"
//#include "ontology/ontointerpreter.h"
#include "gui/mainwindow.h"

using namespace mbdev;

/*!
  \brief Launches GrafOnto. There are several modes of operation possible. By default,
   simply GUI written in Qt is launched. For other options see argv parameter description.
  \param argc number of commandline arguments
  \param argv command line arguments
   will load the file, add a statement to the ontology, save it under the same name, and exit
   \code -demo \endcode will load an example ontology at application startup it can be used
   in conjunction with any of the three: gui/text/none
  */
int main(int argc, char *argv[]) {
   ontology onto;
   //ontointerpreter interpreter(onto);
   QApplication a(argc, argv);
   std::cout << "GrafOnto: interactive graphical visualisation" << std::endl
             << "          of a categorial ontology" << std::endl
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
   MainWindow w(onto, a);
   w.show();
   return a.exec();

   //grafonto gr(argc, argv);
   //return gr.exec();

   //console_application c(argc, argv);
   //return c.exec();
   return 0;
}
