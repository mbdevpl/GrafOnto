#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->ontology = new Ontology();

    //QString s(this->ontology->toString().c_str());

    //QWidget::connect(ui->actionNew, SIGNAL(triggered()), ui->lineEdit, SLOT(setText(s)));
}

MainWindow::~MainWindow()
{
    //if(ontology != nullptr) {
    //    delete ontology;
    //    ontology = nullptr;
    //}

    delete ui;
}
