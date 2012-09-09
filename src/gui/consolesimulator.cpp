#include "consolesimulator.h"
#include "ui_consolesimulator.h"

ConsoleSimulator::ConsoleSimulator(QWidget *parent)
   : QWidget(parent), ui(new Ui::ConsoleSimulator), app(nullptr) {
   ui->setupUi(this);
   QWidget::connect(ui->commandLine, SIGNAL(returnPressed()), this, SLOT(executeCurrent()));
   QWidget::connect(ui->bExecute, SIGNAL(clicked()), this, SLOT(executeCurrent()));
   QWidget::connect(ui->bClear, SIGNAL(clicked()), ui->commandLine, SLOT(clear()));
   QWidget::connect(ui->bPasteLast, SIGNAL(clicked()), this, SLOT(pasteLastCommand()));
   QWidget::connect(ui->bClearLog, SIGNAL(clicked()), ui->commandLog, SLOT(clear()));
   //QWidget::connect(ui->commandLog, SIGNAL()
}

ConsoleSimulator::~ConsoleSimulator() {
   delete ui;
}

void ConsoleSimulator::setApplication(console_application* app) {
   if(this->app == app)
      return;
   ui->commandLog->clear();
   this->app = app;
   size_t size = app->getCommandHistorySize();
   for(size_t i=0; i<size; i++) {
      QString sym(app->getUserSymbol().c_str());
      ui->commandLog->appendPlainText(sym.append(app->getCommandHistoryEntry(i).c_str()));
   }
}

void ConsoleSimulator::execute(const QString& command) {
   string cmd(command.toStdString());
   if(app == nullptr) {
      ui->commandLog->appendPlainText(QString("error: there is no application to handle the command"));
      return;
   }
   ui->commandLog->appendPlainText(QString(app->getUserSymbol().append(cmd).c_str()));
   try {
      string result = app->externExecute(cmd);
      ui->commandLog->appendPlainText(QString(result.c_str()));
      emit commandExecutionSuccess();
   } catch (std::runtime_error ex) {
      ui->commandLog->appendPlainText(QString(ex.what()));
      emit commandExecutionFailure();
   }
   emit commandExecutionCompleted();
}

void ConsoleSimulator::executeCurrent() {
   execute(ui->commandLine->text());
   ui->commandLine->clear();
}

void ConsoleSimulator::pasteLastCommand() {
   QString s(app->getCommandHistoryEntry(app->getCommandHistorySize()-1).c_str());
   ui->commandLine->setText(s);
}
