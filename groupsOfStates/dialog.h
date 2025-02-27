#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtStateMachine/QStateMachine>
#include <QtStateMachine/QState>
#include <QDebug>
#include <QtStateMachine/QFinalState>
#include <QtStateMachine/QAbstractState>
#include <QMessageBox>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void stateEntered();
    void stateExited();
    void stateFinished();
private:
    void createGroup(QString name, int count, QLineEdit *editor);
    void connectState(QState *state, QLineEdit *editor);
    void createTransitions();
    void createFinal();
private:
    Ui::Dialog *ui;
    QStateMachine m_statemachine;
    QList<QState*> m_states;

};
#endif // DIALOG_H
