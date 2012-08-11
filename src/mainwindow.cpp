#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ontology& onto, grafonto& graf, QWidget* parent)
   : QMainWindow(parent), ui(new Ui::MainWindow), onto(onto), graf(graf) {
   ui->setupUi(this);
   this->ui->console->setApplication(&graf);
   QWidget::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow() {
   delete ui;
}

//void MainWindow::execute(const QString& command) {
//}
