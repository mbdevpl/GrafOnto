#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(ontology& onto, grafonto& graf, QWidget* parent)
   : QMainWindow(parent), ui(new Ui::MainWindow), onto(onto), graf(graf) {
    ui->setupUi(this);
    //QString s(this->ontology->toString().c_str());
    //QWidget::connect(ui->actionNew, SIGNAL(triggered()), ui->lineEdit, SLOT(setText(s)));
    QWidget::connect(ui->bExecute, SIGNAL( clicked() ), this, SLOT( execute(ui->commandLine->text()) ));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::execute(const QString& command) {
   ui->commandHistory->appendPlainText(graf.getUserSymbol().c_str());
   ui->commandHistory->appendPlainText(command);
   ui->commandHistory->appendPlainText("\n");
   QString result = graf.executeQt(command);
   ui->commandHistory->appendPlainText(result);
}
