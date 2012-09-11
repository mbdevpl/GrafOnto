#ifndef ONTOADDELEMDIALOG_H
#define ONTOADDELEMDIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>

namespace Ui {
class OntoAddElemDialog;
}

class OntoAddElemDialog : public QDialog
{
   Q_OBJECT
   
public:
   explicit OntoAddElemDialog(const QStringList& categories, QWidget *parent = 0);
   ~OntoAddElemDialog();
   
private:
   Ui::OntoAddElemDialog *ui;

private slots:
   void applyChanges();
signals:
   void sendCommand(const QString& command);
};

#endif // ONTOADDELEMDIALOG_H
