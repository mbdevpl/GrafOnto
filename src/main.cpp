#include <QtGui/QApplication>
#include <iostream>
#include "mainwindow.h"
#include "ontology.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   if(argc > 0) {
      for(int i = 0; i < argc; i++)
         std::cout << "arg" << i << "=" << argv[i] << std::endl;
   }

   Ontology o("thing, feature, situation, class");

   o.execute("add thing animal");
   o.execute("add thing rabbit");
   o.execute("add thing bird");
   o.execute("add thing wings");
   o.execute("add thing aeroplane");
   o.execute("add thing penguin");
   o.execute("add thing wheels");
   o.execute("add thing windows");
   o.execute("add thing eyes");
   o.execute("add thing engine");

   o.execute("add feature big");
   o.execute("add feature large");
   o.execute("add feature small");
   o.execute("add feature black");
   o.execute("add feature transparent");
   o.execute("add feature loud");

   o.execute("add situation is");
   o.execute("add situation has");
   o.execute("add situation eats");
   o.execute("add situation loves");

   o.execute("set is transitive");

   //o.execute("add property (thing, feature, situation, class)");
   //o.execute("add feature (big, small, black, transparent, loud)");
   //o.execute("add situation (is, has, eats, loves)");

   o.execute("rabbit is: animal");
   o.execute("bird is: animal");
   o.execute("small bird is: small animal");
   o.execute("bird has: wings");
   o.execute("aeroplane has: wings");
   o.execute("aeroplane has: loud engine");
   o.execute("small bird loves: engine");
   o.execute("large bird eats: rabbit");

   std::cout << o << "\n";

   std::string s = o.execute("find all that has: wings");
   std::cout << s;

   //o.execute("big is: large");
   //o.execute("large is: big");

   return 0;

   MainWindow w;
   w.show();
   return a.exec();
}
