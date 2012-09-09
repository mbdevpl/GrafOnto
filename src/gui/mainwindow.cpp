#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ontology& onto, QApplication& app, QWidget* parent)
   : QMainWindow(parent), ui(new Ui::MainWindow), onto(onto) {
   ui->setupUi(this);
   QWidget::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
   QWidget::connect(ui->console, SIGNAL(commandExecutionCompleted()),
                    ui->graph, SLOT(refreshGraphics()));
   //set the references for command log and visualisation area

   //ontointerpreter interp(onto);
   OntoConsoleInterpreter* onto_console = new OntoConsoleInterpreter(app.argc(), app.argv(), onto);
   ui->console->setApplication(onto_console);
   if(onto_console->getDemoMode()) {
      const string_vector& demo = onto_console->prepareDemo();
      for(size_t i=0; i<demo.size(); i++)
         ui->console->execute(demo[i].c_str());
   }
   //ui->console->setApplication(&onto);
   //OntologyGraph& og = ui->graph->getGraph();
   //og.setOntology(&onto);
   ui->graph->setOntology(&onto);
   this->updateGeometry();
}

MainWindow::~MainWindow() {
   delete ui;
}
