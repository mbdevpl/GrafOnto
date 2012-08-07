#include "console_application.h"

namespace mbdev {

void console_application::initialize() {
   //userSymbol = "$ ";
   //commandHistory = ;

   allowedIntervalsStart.push_back('0');
   allowedIntervalsEnd.push_back('9');
   allowedIntervalsStart.push_back('A');
   allowedIntervalsEnd.push_back('Z');
   allowedIntervalsStart.push_back('a');
   allowedIntervalsEnd.push_back('z');

   allowedChars.push_back(' ');
   allowedChars.push_back(',');
   allowedChars.push_back(':');
   allowedChars.push_back('(');
   allowedChars.push_back(')');
   allowedChars.push_back(';');
   allowedChars.push_back('_');
   allowedChars.push_back('.');
   allowedChars.push_back('-');
   allowedChars.push_back('!');
   allowedChars.push_back('@');
   allowedChars.push_back('$');
   allowedChars.push_back('%');
   allowedChars.push_back('&');
   allowedChars.push_back('*');
   allowedChars.push_back('/');
   allowedChars.push_back('\\');
}

void console_application::printLine(string& text, size_t caretPosition, size_t toClear) {
   out << "\xd";
   for(size_t i=0; i < toClear; i++)
      out << " ";
   out << "\xd" << userSymbol;
   //std::string s(currentText.str());
   out << text;
   size_t len = text.length();
#ifdef DEBUG
   if(debugMode) {
      out << " position=" << caretPosition;
      out << " index=" << index;
      out << " len=" << len;
   }
#endif
   if(caretPosition < len) {
      out << "\xd" << userSymbol;
      if(caretPosition > 0)
         out << text.substr(0, caretPosition);
   }
   out.flush();
}

//void console_application::overwriteStream(std::stringstream& str, const string& s) {
//   str.str(std::string());
//   str.clear();
//   str << s;
//}

console_application::console_application(int argc, char *argv[])
   : out(std::cout),
     allowedChars(), allowedIntervalsStart(), allowedIntervalsEnd(), userSymbol(string("$ ")),
     index(0), position(0), commandHistory(), debugMode(false), argc(argc), argv(argv), args() {
   // reading command line arguments
   for(int i = 0; i < argc; i++) {
      string arg(argv[i]);
      if(!debugMode && arg.equals("-debug")) {
         debugMode = true;
         continue;
      }
      args.push_back(arg);
   }
   initialize();
}

bool console_application::isAllowed(char ch) {
   size_t size = allowedIntervalsStart.size();
   for(size_t i=0; i<size; i++)
      if(ch >= allowedIntervalsStart[i] && ch <= allowedIntervalsEnd[i])
         return true;
   if(allowedChars.indexOf(ch) >= 0)
      return true;
   return false;
}

void console_application::handleTab(string& text) {
   out << std::endl;
   out << getClue(text);
   out << std::endl;
   printLine(text, position); // << userSymbol << text;
}

string console_application::execute(const string& command) {
   if(!command.empty()) {
      int index = commandHistory.indexOf(command);
      if(index >=0)
         commandHistory.erase(commandHistory.begin() + index);
      commandHistory.push_back(command);
   }
   index = commandHistory.size();
   return string::emptyStr;
}

string console_application::getClue(const string& current) {
   current.begin();
   return string::emptyStr;
}

string console_application::getCommand() {
   //std::stringstream str;
   string text;
   //text.capacity() = 60;
   //text.resize(60, 0);
   size_t len = 0;
   position = 0;
   char ch = 0;
   while(ch != 10) {
      printLine(text, position);
      len = text.length();
      //s = string(str.str());
      ch = getch();
      if(isAllowed(ch)) {
         //string stri(str.str());
         if(position < len) {
            text.insert(text.begin()+position, ch);
            //overwriteStream(str, stri);
         } else {
            text.push_back(ch);
            //str << ch;
         }
         position++;
      } else if(ch == 9) {
         // tab
         handleTab(text);
      } else if(ch == 127) {
         // backspace
         if(position == 0)
            continue;
         if(len == 0)
            continue;
         text.erase(text.begin()+position-1);
         //overwriteStream(str, s);
         position--;
         //std::cout << "\xd";
         //for(int i=0; i < 50; i++)
         //   std::cout << " ";
         //std::cout << "\xd" << "$ ";
         //std::cout << str.str();
      } else if(ch == 91) {
         // special characters (double characters, with leading special value)
         ch = getch();
         if(ch == 67 || ch == 68) {
            if(ch == 67) {
               //right arrow
               if(position == len)
                  continue;
               position++;
            } else if(ch == 68) {
               //left arrow
               if(position == 0)
                  continue;
               position--;
               //std::cout << "\xd" << userSymbol;
               //for(int i=0; i < position; i++)
               //std::cout << str.str().substr(0, position);
               //std::cout << "{position=" << position << "}";
            }
         } else if(ch == 65 || ch == 66) {
            if(ch == 65) {
               // arrow up
               if(index < 0) index = 0;
               if(index == 0)
                  continue;
               index--;
            } else if(ch == 66) {
               // arrow down
               index++;
               int size = commandHistory.size();
               if(index >= size) {
                  index = size;
                  //std::cout << "\xd";
                  //for(int i=0; i < 50; i++)
                  //   std::cout << " ";
                  //std::cout << "\xd" << userSymbol;
                  //overwriteStream(str, "");
                  text.clear();
                  continue;
               }
            }
            //int len = commandHistory[index].length();
            //std::cout << "\xd";
            //for(int i=0; i < 50; i++)
            //   std::cout << " ";
            //std::cout << "\xd" << userSymbol << commandHistory[index];
            //std::cout << " ch=" << (int)ch;
            //std::cout << " index=" << index;
            text = commandHistory[index];
            position = commandHistory[index].size();
            //overwriteStream(str, commandHistory[index]);
         }
      } else {
         //std::cout << " ch=" << (int)ch;
      }
      //std::cout.flush();
   }
   if(ch == 10) {
      out << std::endl;
   }
   out.flush();

   //string command = str.str();
   if(!text.equals(""))
      commandHistory.push_back(text);
   return text;
}

string console_application::getSimulatedCommand(const string& simulated) {
   out << userSymbol;
   std::stringstream command;
   size_t len = simulated.length();
   for(size_t i=0; i<len; i++) {
      char ch = simulated[i];
      if(isAllowed(ch)) {
         out << ch;
         command << ch;
      }
   }
   out << std::endl;
   out.flush();
   return string(command.str());
}

int console_application::exec() {
   string command;
   while(true) {
      command = getCommand();
      if(command.equals("exit"))
         break;
      try {
         out << execute(command) << std::endl;
      } catch (std::runtime_error e) {
         out << e.what() << std::endl;
      }
   }
   return 0;
}

int console_application::simulateExec(const string& input) {
   string command;
   while(true) {
      command = getSimulatedCommand(input);
      if(command.equals("exit"))
         break;
      try {
         out << execute(command) << std::endl;
      } catch (std::runtime_error e) {
         out << e.what() << std::endl;
      }
      break;
   }
   return 0;
}

}
