#include "ontoconsoleinterpreter.h"

OntoConsoleInterpreter::OntoConsoleInterpreter(int argc, char *argv[], ontology& onto)
   : console_application(argc, argv), interpreter(onto),
     interactiveMode(true), demoMode(false) {
   // interpretation of command line arguments
   for(size_t i = 0; i < args.size(); i++) {
      if(args[i].equals("-demo")) {
         demoMode = true;
//      } else if(!args[i].compare("-text")) {
//         textMode = true;
//      } else if(!args[i].compare("-gui")) {
//         textMode = false;
      } else if(args[i].equals("-auto")) {
         interactiveMode = false;
      }
   }
}

string OntoConsoleInterpreter::execute(const string& command) {
   //handling command history etc.
   console_application::execute(command);
   //handling command contents i.e. ontology changes
   return interpreter.execute(command);
}

string OntoConsoleInterpreter::getClue(const string& current) {
   std::stringstream s;
   s << console_application::getClue(current);
   if(s.str().length() > 0)
      s << ' ';
   s << interpreter.getClue(current);
   return string(s.str());
}

int OntoConsoleInterpreter::exec() {
   if(demoMode) {
      int result = execDemo(interpreter.prepareDemo());
      if(result)
         return result;
   }
   if(interactiveMode)
      return console_application::exec();
   else {
      int result = 0;
      for(size_t i = 1; i < args.size(); i++) {
         // if(args[i].equals("-demo") || args[i].equals("-auto") || args[i].equals("-debug"))
         if(args[i].length() == 0 || args[i].at(0) == '-')
            continue;
         result = simulateExec(args[i]);
         if(result != 0)
            return result;
      }
      return 0;
   }
   //   else {
   //   }
}

int OntoConsoleInterpreter::execDemo(const string_vector& demo) {
   size_t size = demo.size();
   if(size == 0)
      return 1;
   for(size_t i=0; i<size; i++) {
      int result = simulateExec(demo[i]);
      if(result)
         return result;
   }
   return 0;
}

string_vector OntoConsoleInterpreter::prepareDemo() {
   return interpreter.prepareDemo();
}

bool OntoConsoleInterpreter::getDemoMode() {
   return demoMode;
}
