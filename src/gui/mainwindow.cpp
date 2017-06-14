#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ontology& onto, int argc, char *argv[], QApplication& app, QWidget* parent)
   : QMainWindow(parent), ui(new Ui::MainWindow), onto(onto) {
   ui->setupUi(this);
   // initialise console, run demo if it is desired
   OntoConsoleInterpreter* onto_console = new OntoConsoleInterpreter(argc, argv, onto);
   ui->console->setApplication(onto_console);
   if(onto_console->getDemoMode()) {
      const string_vector& demo = onto_console->prepareDemo();
      for(size_t i=0; i<demo.size(); i++)
         ui->console->execute(demo[i].c_str());
   }
   // set the active ontology for visualisation widget
   ui->visualisation->setOntology(&onto);
   // refresh graphics for whole window, together with console and visualisation graphics
   //refreshGraphics();
   // set connection for future visualisation widget refresh
   QWidget::connect(ui->console, SIGNAL(commandExecutionCompleted()),
                    ui->visualisation, SLOT(refreshGraphics()));
   // Application
   QWidget::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
   // Ontology
   QWidget::connect(ui->actionAddCat, SIGNAL(triggered()), this, SLOT(showAddCategoryDialog()));
   QWidget::connect(ui->actionAddElem, SIGNAL(triggered()), this, SLOT(showAddElementDialog()));
   QWidget::connect(ui->actionAddStmt, SIGNAL(triggered()), this, SLOT(showAddStatementDialog()));
}

MainWindow::~MainWindow() {
   delete ui;
}

void MainWindow::showAddCategoryDialog() {
   OntoAddCatDialog* dialog = new OntoAddCatDialog(this);
   QObject::connect(dialog, SIGNAL(sendCommand(QString)), ui->console, SLOT(execute(QString)));
   dialog->show();
   //QObject::connect(dialog, SIGNAL(rejected()), ui->console, SLOT());
}

void MainWindow::showAddElementDialog() {
   QStringList cats;
   string_vector v = onto.getCategories();
   for(string_vector::iterator i= v.begin(); i != v.end(); ++i)
      cats.push_back(QString(i->c_str()));
   OntoAddElemDialog* dialog = new OntoAddElemDialog(cats,this);
   QObject::connect(dialog, SIGNAL(sendCommand(QString)), ui->console, SLOT(execute(QString)));
   dialog->show();
}

void MainWindow::showAddStatementDialog() {
   OntoAddStmtDialog* dialog = new OntoAddStmtDialog(this);
   QObject::connect(dialog, SIGNAL(sendCommand(QString)), ui->console, SLOT(execute(QString)));
   dialog->show();
}

void MainWindow::refreshGraphics() {
   ui->console->updateGeometry();
   ui->visualisation->refreshGraphics();
   this->updateGeometry();
}
