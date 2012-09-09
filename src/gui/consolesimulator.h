#pragma once
#include <QWidget>
#include "mbdev/toolkit.h"
#include "mbdev/console_application.h"

using namespace mbdev;

namespace Ui {
class ConsoleSimulator;
}

/*!
  \brief Very simple widget written to handle a console application
  from inside a Qt GUI application.
  */
class ConsoleSimulator : public QWidget
{
   Q_OBJECT
private:
   Ui::ConsoleSimulator* ui;
   // command handler for this simulator
   console_application* app;
signals:
   void commandExecutionCompleted();
   void commandExecutionSuccess();
   void commandExecutionFailure();
   //void logCleared();
   //void commandLineCleared();
public:
   // constructor
   explicit ConsoleSimulator(QWidget *parent = 0);
   // destructor
   ~ConsoleSimulator();
   /*!
     \brief Sets the command handler for this console simulator.
     \param app console application that will handle all of the commands and will provide responses
     */
   void setApplication(console_application* app);
public slots:
   /*!
     \brief Executes an arbitrary command as if it was entered in the command line.
     \param command the command
     */
   void execute(const QString& command);
   // executes the current contents of the command line
   void executeCurrent();
   // pastes last executed command back into the command line
   void pasteLastCommand();
};
