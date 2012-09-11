#pragma once
#include <QMainWindow>
#include "mbdev/toolkit.h"
#include "ontology/ontology.h"
#include "ontology/ontointerpreter.h"
#include "console/ontoconsoleinterpreter.h"
#include "gui/ontoaddcatdialog.h"
#include "gui/ontoaddelemdialog.h"
#include "gui/ontoaddstmtdialog.h"

using namespace mbdev_ontology;

//class ontointerpreter;

namespace Ui {
class MainWindow;
}

/*!
  \brief Main window consists of two parts, command line with log on the left,
  and ontology visualisation area on the right hand side.
  */
class MainWindow : public QMainWindow {
   Q_OBJECT
private:
   Ui::MainWindow *ui;
   ontology& onto;
   //ontointerpreter& graf;
protected:
public:
   /*!
     \brief Constructs the main window of GrafOnto.
     \param graf reference to the console application with all data and command interpreter
     \param direct reference to the ontology that is visualized in this application
     */
   explicit MainWindow(ontology &onto, QApplication& app, QWidget* parent = 0);
   // destructor
   ~MainWindow();
private slots:
   void showAddCategoryDialog();
   void showAddElementDialog();
   void showAddStatementDialog();
   void refreshGraphics();
private:
};
