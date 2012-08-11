#pragma once
#include <QWidget>
#include "mbdev/toolkit.h"
#include "mbdev/console_application.h"

using namespace mbdev;

namespace Ui {
class ConsoleSimulator;
}

class ConsoleSimulator : public QWidget
{
   Q_OBJECT
private:
   Ui::ConsoleSimulator* ui;
   console_application* app;
public:
   explicit ConsoleSimulator(QWidget *parent = 0);
   ~ConsoleSimulator();
   void setApplication(console_application* app);
   void execute(const QString& command);
public slots:
   void executeCurrent();
   void pasteLastCommand();
};
