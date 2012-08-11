#ifdef RELEASE
#include <iostream>
#endif

#include "grafonto.h"

using namespace mbdev;

/*!
  \brief Launches GrafOnto. There are several modes of operation possible. By default,
   GUI written in Qt is launched. For other options see argv parameter description.
  \param argc number of commandline arguments
  \param argv command line arguments
   \code -gui \endcode is the default mode,
   \code -text \endcode launches text mode, which essentially is an interpreter directly
   in the console
   \code -auto \endcode interprets all subsequent commands and then immediately exits
   the application
   fore example: \code -auto load 'db.txt'; john is: human; save 'db.txt' \endcode
   will load the file, add a statement to the ontology, save it under the same name, and exit
   \code -demo \endcode will load an example ontology at application startup it can be used
   in conjunction with any of the three: gui/text/none
  */
int main(int argc, char *argv[]) {
#ifdef RELEASE
   std::cout << "GrafOnto: interactive graphical visualisation" << std::endl
             << "          of a categorial ontology" << std::endl
             << "(C) 2012 Mateusz Bysiek, http://mbdev.pl/" << std::endl
             << "released under GNU General Public License version 3" << std::endl;
#endif
   //#ifdef DEBUG
   //   //ontology::debugMode = debugMode;
   //   std::cout << "command line arguments:\n";
   //   if(argc > 0) {
   //      for(int i = 0; i < argc; i++)
   //         std::cout << "  arg" << i << "=" << argv[i] << std::endl;
   //   } else
   //      std::cout << "  none" << std::endl;
   //#endif

   grafonto gr(argc, argv);
   return gr.exec();

   //console_application c(argc, argv);
   //return c.exec();
}
