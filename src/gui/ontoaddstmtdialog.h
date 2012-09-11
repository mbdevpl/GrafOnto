#ifndef ONTOADDSTMTDIALOG_H
#define ONTOADDSTMTDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class OntoAddStmtDialog;
}

class OntoAddStmtDialog : public QDialog
{
   Q_OBJECT
   
public:
   explicit OntoAddStmtDialog(QWidget *parent = 0);
   ~OntoAddStmtDialog();
   
private:
   Ui::OntoAddStmtDialog *ui;

private slots:
   void applyChanges();
signals:
   void sendCommand(const QString& command);
};

#endif // ONTOADDSTMTDIALOG_H
