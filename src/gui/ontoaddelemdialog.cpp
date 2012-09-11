#include "ontoaddelemdialog.h"
#include "ui_ontoaddelemdialog.h"

OntoAddElemDialog::OntoAddElemDialog(const QStringList& categories, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::OntoAddElemDialog)
{
   ui->setupUi(this);
   QObject::connect(this, SIGNAL(accepted()), this, SLOT(applyChanges()));
   ui->inputCat->addItems(categories);
}

OntoAddElemDialog::~OntoAddElemDialog()
{
   delete ui;
}

void OntoAddElemDialog::applyChanges() {
   QString cmd = QString("add ").append(ui->inputCat->currentText())
         .append(" ").append(ui->inputName->text());
   emit sendCommand(cmd);
}
