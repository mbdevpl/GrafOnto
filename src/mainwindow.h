#pragma once
#include <QMainWindow>
#include "mbdev/toolkit.h"
#include "ontology/ontology.h"
#include "grafonto.h"

using namespace mbdev_ontology;

class grafonto;

namespace Ui {

class MainWindow;

}

class MainWindow : public QMainWindow {
   Q_OBJECT

private:
   Ui::MainWindow *ui;
   ontology& onto;
   grafonto& graf;

protected:
public:
   explicit MainWindow(ontology &onto, grafonto& graf, QWidget* parent = 0);
   ~MainWindow();
private slots:
private:
//   void execute(const QString& command);
};
