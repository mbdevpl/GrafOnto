#include "ontoaddcatdialog.h"
#include "ui_ontoaddcatdialog.h"

OntoAddCatDialog::OntoAddCatDialog(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::OntoAddCatDialog)
{
   ui->setupUi(this);
   QObject::connect(this, SIGNAL(accepted()), this, SLOT(applyChanges()));
}

OntoAddCatDialog::~OntoAddCatDialog()
{
   delete ui;
}

void OntoAddCatDialog::applyChanges() {
   QString cmd("add category ");
   emit sendCommand(cmd.append(ui->inputName->text()));
}
