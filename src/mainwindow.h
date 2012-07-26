#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef nullptr
#define nullptr NULL
#endif

#include <QMainWindow>
//#include "ontology.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
protected:
    //Ontology* ontology;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
