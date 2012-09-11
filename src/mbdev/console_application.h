#pragma once
//#include <limits> //for std::numeric_limits
#include <iostream> //for std::cout
#include <stdexcept> //for std::runtime_error
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
   // set of starts of allowed characters intervals
   vector<char> allowedIntervalsStart;
   /*!
     Set of ends of allowed characters intervals. The list must
     have the same length as allowedIntervalsStart, and the ends must have
     larger integer values than the starts.
     */
   vector<char> allowedIntervalsEnd;
   // symbol displayed at the beginning of each line with user input
   string userSymbol;
   // return character
   char charReturn;
   // tab character
   char charTab;
   // backspace character
   char charBackspace;
   // special character
   char charSpecial;
   // arrows
   char charUp, charDown, charRight, charLeft;
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
protected:
   bool debugMode;
   int argc;
   char** argv;
   string_vector args;
private:
   void initialize();
   void printLine(string& text, size_t caretPosition, size_t toClear = 60);
   void overwriteStream(std::stringstream& str, const string& s);
protected:
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
   console_application(int argc, char *argv[], std::ostream& outputStream = std::cout);
   inline string getUserSymbol() const;
   inline size_t getCommandHistorySize() const;
   inline string getCommandHistoryEntry(const size_t index) const;
   bool isAllowed(char ch);
   virtual int exec();
   int simulateExec(const string& input);
   string externExec(const string& input);
};

inline string console_application::getUserSymbol() const {
    return userSymbol;
}

inline size_t console_application::getCommandHistorySize() const {
   return commandHistory.size();
}

inline string console_application::getCommandHistoryEntry(const size_t index) const {
   return commandHistory[index];
}

}
