#include "ontoaddstmtdialog.h"
#include "ui_ontoaddstmtdialog.h"

OntoAddStmtDialog::OntoAddStmtDialog(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::OntoAddStmtDialog)
{
   ui->setupUi(this);
   QObject::connect(this, SIGNAL(accepted()), this, SLOT(applyChanges()));
}

OntoAddStmtDialog::~OntoAddStmtDialog()
{
   delete ui;
}

void OntoAddStmtDialog::applyChanges() {
   QString cmd = ui->inputLHS->text().append(": ").append(ui->inputRHS->text());
   emit sendCommand(cmd);
}
