#pragma once
#include <stdexcept> //for std::runtime_error
#include <iostream> //for std::cout
#include "mbdev/toolkit.h"
#include "mbdev/vector.h"
#include "mbdev/string_vector.h"
#include "mbdev/string.h"

#ifndef WINDOWS
#ifndef LINUX
//ordinary text input - per line buffering
#include <QTextStream>
#endif
#endif

namespace mbdev {

/*!
  \brief Meant to be sub-classed with a real console application.
  */
class console_application
{
private:
   std::ostream& out;
   vector<char> allowedChars;
   vector<char> allowedIntervalsStart;
   vector<char> allowedIntervalsEnd;
   string userSymbol;
   /*!
     \brief currently browsed index of command history
     */
   int index;
   /*!
     \brief current caret position in the edited command
     */
   size_t position;
   /*!
     \brief previously executed commands
     */
   string_vector commandHistory;
   void initialize();
   void printLine(string& text, size_t caretPosition, size_t toClear = 60);
   void overwriteStream(std::stringstream& str, const string& s);
protected:
   bool debugMode;
   int argc;
   char** argv;
   string_vector args;
   void handleTab(string& text);
   virtual string execute(const string& command);
   virtual string getClue(const string& current);
   /*!
     \brief Blocks the console and waits for user input.

     \return user command, after pressing Enter
     */
   string getCommand();
   string getSimulatedCommand(const string& simulated);
public:
   console_application(int argc, char *argv[]);
   inline string getUserSymbol() const;
   bool isAllowed(char ch);
   virtual int exec();
   int simulateExec(const string& input);
};

inline string console_application::getUserSymbol() const {
    return userSymbol;
}

}
