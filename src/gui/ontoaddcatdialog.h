#ifndef ONTOADDCATDIALOG_H
#define ONTOADDCATDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class OntoAddCatDialog;
}

class OntoAddCatDialog : public QDialog
{
   Q_OBJECT
   
public:
   explicit OntoAddCatDialog(QWidget *parent = 0);
   ~OntoAddCatDialog();

private:
   Ui::OntoAddCatDialog *ui;

private slots:
   void applyChanges();
signals:
   void sendCommand(const QString& command);
};

#endif // ONTOADDCATDIALOG_H
