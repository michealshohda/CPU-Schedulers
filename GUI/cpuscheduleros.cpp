#include "cpuscheduleros.h"
#include "ui_cpuscheduleros.h"
#include <QLabel>
#include <QSpinBox>
#include <qscrollarea.h>
#include <QMessageBox>
#include "global.h"
#include "mainwindow.h"


CPUSchedulerOS::CPUSchedulerOS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CPUSchedulerOS)
{
    ui->setupUi(this);
    // Create preemptive option widgets (hidden by default)
    ui->preemptiveGroupBox->setVisible(false);
     QPixmap pix2(":/background.png");
     ui->label->setPixmap(pix2.scaled(512,150,Qt::KeepAspectRatio));
}

CPUSchedulerOS::~CPUSchedulerOS()
{
    delete ui;
}
void CPUSchedulerOS::showPreemptiveOption(bool show)
{
    ui->preemptiveGroupBox->setVisible(show);
}

bool CPUSchedulerOS::isPreemptive() const
{
    return ui->preemptiveRadio->isChecked();
}
void CPUSchedulerOS::updateUI()
{
    // qDebug() << "BEFORE CLEANUP - Children of main layout:" << ui->mainLayout->count();
    // qDebug() << "BEFORE CLEANUP - Scroll area widget:" << ui->scrollArea->widget();
    // Clear previous process inputs
    if (ui->scrollArea->widget()) {
        delete ui->scrollArea->takeWidget();// This will delete the layout and all child widgets
    }
     QWidget *container = new QWidget();
     QGridLayout *gridLayout = new QGridLayout(container);
     gridLayout->setSpacing(10);
     if (currentAlgorithm == "PRIORITY") {
       setupPriorityUI(gridLayout);
     }
    else if (currentAlgorithm == "SJF") {
       setupSJFUI(gridLayout);
    }
   else if (currentAlgorithm == "RR") {
       setupRRUI(gridLayout);
     }
    else {
        setupDefaultUI(gridLayout);
    }
    container->setMinimumSize(gridLayout->sizeHint());
    ui->scrollArea->setWidget(container);
    ui->scrollArea->setWidgetResizable(true);
//     qDebug() << "AFTER UPDATE - Children of main layout:" << ui->mainLayout->count();
//     qDebug() << "AFTER UPDATE - Scroll area widget:" << ui->scrollArea->widget();
}
void CPUSchedulerOS::setAlgorithm(const QString &algorithm)
{
    currentAlgorithm = algorithm;
    updateUI();
}

void CPUSchedulerOS::setProcessCount(int count)
{
    processCount = count;
    updateUI();
}

void CPUSchedulerOS::setupPriorityUI(QGridLayout *gridLayout)
{
    gridLayout->addWidget(new QLabel("Process"), 0, 0);
    gridLayout->addWidget(new QLabel("Burst Time"), 0, 1);
    gridLayout->addWidget(new QLabel("Priority"), 0, 2);
    gridLayout->addWidget(new QLabel("Arrival Time"), 0, 3);
    // Add priority and burst time for each process
    for (int i = 0; i < processCount; ++i) {
        int row = i + 1; // Start from row 1 (row 0 is header)

        // Process label
        gridLayout->addWidget(new QLabel(QString("P%1").arg(i+1)),row, 0);

        // Burst time
        QSpinBox *burstSpin = new QSpinBox();
        burstSpin->setRange(1, 100);
        gridLayout->addWidget(burstSpin, row, 1);
        burstSpinBoxes.append(burstSpin);

        // Priority
        QSpinBox *prioritySpin = new QSpinBox();
        prioritySpin->setRange(1, 10);
        gridLayout->addWidget(prioritySpin, row, 2);
        prioritySpinBoxes.append(prioritySpin);

        // Arrival time
        QSpinBox *arrivalSpin = new QSpinBox();
        arrivalSpin->setRange(0, 100);
        gridLayout->addWidget(arrivalSpin, row, 3);
        arrivalSpinBoxes.append(arrivalSpin);
    }
}
void CPUSchedulerOS::setupSJFUI(QGridLayout *gridLayout)
{

    // Add process rows
    for (int i = 0; i < processCount; ++i) {


        gridLayout->addWidget(new QLabel(QString("Process %1").arg(i+1)), i, 0);// Process label
        gridLayout->addWidget(new QLabel("Burst Time :"), i, 1);
        gridLayout->addWidget(new QLabel("Arrival Time:"), i, 3);


        // Burst time
        QSpinBox *burstSpin = new QSpinBox();
        burstSpin->setRange(1, 100);
        gridLayout->addWidget(burstSpin, i, 2);
        burstSpinBoxes.append(burstSpin);

        // Arrival time
        QSpinBox *arrivalSpin = new QSpinBox();
        arrivalSpin->setRange(0, 100);
        gridLayout->addWidget(arrivalSpin, i, 4);
        arrivalSpinBoxes.append(arrivalSpin);

    }
}
void CPUSchedulerOS::setupRRUI(QGridLayout *gridLayout)
{

    qDeleteAll(burstSpinBoxes);
    qDeleteAll(arrivalSpinBoxes);
    burstSpinBoxes.clear();
    arrivalSpinBoxes.clear();

    gridLayout->addWidget(new QLabel("Time Quantum:"), 0, 0);
    quantumSpinBox = new QSpinBox(this);
    quantumSpinBox->setRange(0, 100);
    gridLayout->addWidget(quantumSpinBox, 0, 1);


    // Add process rows (starting from row 2)
    for (int i = 0; i < processCount; ++i) {

        gridLayout->addWidget(new QLabel(QString("Process %1").arg(i+1)), i+1, 0);// Process label
        gridLayout->addWidget(new QLabel("Burst Time :"), i+1, 1);
        gridLayout->addWidget(new QLabel("Arrival Time:"), i+1, 3);


        // Burst time
        QSpinBox *burstSpin = new QSpinBox();
        burstSpin->setRange(1, 100);  gridLayout->addWidget(burstSpin, i+1, 2);
        burstSpinBoxes.append(burstSpin);

        // Arrival time
        QSpinBox *arrivalSpin = new QSpinBox();
        arrivalSpin->setRange(0, 100);
        gridLayout->addWidget(arrivalSpin, i+1, 4);
        arrivalSpinBoxes.append(arrivalSpin);

    }
}
void CPUSchedulerOS::setupDefaultUI(QGridLayout *gridLayout)
{
    // For FCFS


        // qDebug() << "Starting UI setup for" << processCount << "processes";

        // if (!gridLayout) {
        //     qDebug() << "Error: gridLayout is null!";
        //     return;
        // }

        // Clear existing widgets
        qDeleteAll(burstSpinBoxes);
        qDeleteAll(arrivalSpinBoxes);
        burstSpinBoxes.clear();
        arrivalSpinBoxes.clear();

        // Debug layout clearing
        //qDebug() << "Cleared existing widgets";

        for (int i = 0; i < processCount; ++i) {
           // qDebug() << "Creating widgets for process" << i+1;

            // Labels
           gridLayout->addWidget(new QLabel(QString("Process %1").arg(i+1)), i, 0);
           gridLayout->addWidget(new QLabel("Burst Time :"), i, 1);
           gridLayout->addWidget(new QLabel("Arrival Time:"), i, 3);


            // Spin boxes
            QSpinBox* burstSpin = new QSpinBox(this);
            burstSpin->setRange(1, 100);
            gridLayout->addWidget(burstSpin, i, 2);
            burstSpinBoxes.append(burstSpin);

            QSpinBox* arrivalSpin = new QSpinBox(this);
            arrivalSpin->setRange(0, 100);
            gridLayout->addWidget(arrivalSpin, i, 4);
            arrivalSpinBoxes.append(arrivalSpin);

        //     qDebug() << "Created widgets for process" << i+1
        //              << "| Burst box:" << burstSpin
        //              << "Arrival box:" << arrivalSpin;
        // }

        // qDebug() << "UI setup complete. Total spin boxes:"
        //          << "Burst:" << burstSpinBoxes.size()
        //          << "Arrival:" << arrivalSpinBoxes.size();

    }
}
void CPUSchedulerOS::on_OK_clicked()
{
        // // Verify UI is properly set up
        // if (burstSpinBoxes.size() != processCount ||
        //     arrivalSpinBoxes.size() != processCount) {
        //     QMessageBox::critical(this, "Error",
        //                           QString("UI setup incomplete. Expected %1 processes, got %2 burst/%3 arrival boxes")
        //                               .arg(processCount)
        //                               .arg(burstSpinBoxes.size())
        //                               .arg(arrivalSpinBoxes.size()));
        //     return;
        // }
        bool preemptive = false;
        if (currentAlgorithm == "SJF" ) {
        preemptive = isPreemptive();
            if(preemptive)
                scheduler=new SJFPScheduler();
            else
                scheduler=new SJFNPScheduler();
        qDebug() << "Preemptive mode in case SJF:" << preemptive;
        }
        if (currentAlgorithm == "PRIORITY" ) {
           preemptive = isPreemptive();
           priorityValues.clear();
           for (int i = 0; i < processCount; i++) {
               priorityValues.append(prioritySpinBoxes[i]->value());
           }

           if(preemptive)
               scheduler=new PriorityPreemptiveScheduler();
           else
               scheduler=new PriorityNonPreemptiveScheduler();
            qDebug() << "Collected values - priority:" << priorityValues;
            qDebug() << "Preemptive mode in case PRIORITY:" << preemptive;
        }
        int quantum = 0;
        if (currentAlgorithm == "RR" && quantumSpinBox) {
        quantum = quantumSpinBox->value();
            scheduler=new RoundRobinScheduler(quantum);


        qDebug() << "Time Quantum:" << quantum;
        }

        if(currentAlgorithm=="FCFS")
        {
            scheduler=new FCFSScheduler();
        }
        // Collect values
        burstValues.clear();
        arrivalValues.clear();

        for (int i = 0; i < processCount; i++) {
            burstValues.append(burstSpinBoxes[i]->value());
            arrivalValues.append(arrivalSpinBoxes[i]->value());
        }

        sim=new CPUSimulator(scheduler);
        for( pid_Global = 0; pid_Global < processCount; pid_Global++)
        {
            if(currentAlgorithm=="PRIORITY")
                sim->addProcess(Process(pid_Global+1,arrivalValues[pid_Global],burstValues[pid_Global],priorityValues[pid_Global]));
            else
                sim->addProcess(Process(pid_Global+1,arrivalValues[pid_Global],burstValues[pid_Global]));
        }



        // Success message
        QMessageBox::information(this, "Success",
                                 QString("%1 processes added successfully").arg(processCount));

        hide();
        mainwindow= new MainWindow(this);

        mainwindow->show();


    //i want in the main window after adding the process with same concept as up want to tell me in status bar succesfully done press graph again
}

