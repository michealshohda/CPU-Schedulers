#ifndef CPUSCHEDULEROS_H
#define CPUSCHEDULEROS_H

#include <QDialog>
#include <QGridLayout>
#include <QSpinBox>

#include "mainwindow.h"
#include"Headers.hpp"
#include"FCFSScheduler.hpp"
#include"PriorityNonPreemptiveScheduler.hpp"
#include"PriorityPreemptiveScheduler.hpp"
#include"RoundRobinScheduler.hpp"
#include"StatisticsCalculator.hpp"
#include "SJFPreemptiveScheduler.hpp"
#include "SJFNonPreemptiveScheduler.hpp"
#include"CPUSimulator.hpp"
#include"global.h"



namespace Ui {
class CPUSchedulerOS;
}

class CPUSchedulerOS : public QDialog
{
    Q_OBJECT

public:
    explicit CPUSchedulerOS(QWidget *parent = nullptr);
    ~CPUSchedulerOS();
    void setAlgorithm(const QString &algorithm);
    void setProcessCount(int count);
    void showPreemptiveOption(bool show);

    bool isPreemptive() const;
private slots:
    void on_OK_clicked();

private:
    Ui::CPUSchedulerOS *ui;
    QString currentAlgorithm;
    int processCount=0;
    void updateUI();
    void setupPriorityUI(QGridLayout *gridLayout);
    void setupSJFUI(QGridLayout *gridLayout);
    void setupRRUI(QGridLayout *gridLayout);
    void setupDefaultUI(QGridLayout *gridLayout);

    QList<QSpinBox*> burstSpinBoxes;   // Stores spin box widgets
    QList<QSpinBox*> arrivalSpinBoxes;
    QList<QSpinBox*> prioritySpinBoxes;

    QList<int> burstValues;            // Will store final values
    QList<int> arrivalValues;
     QList<int> priorityValues;

    QSpinBox *arrivalSpin = new QSpinBox();
    QSpinBox *burstSpin = new QSpinBox();
    QSpinBox *quantumSpinBox;
    QSpinBox *prioritySpin = new QSpinBox();

    MainWindow *mainwindow;


};

#endif // CPUSCHEDULEROS_H
