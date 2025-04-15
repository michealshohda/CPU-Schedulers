#ifndef CPUSIMULATOR_HPP
#define CPUSIMULATOR_HPP

#include <iostream>
#include <vector>
#include <map>
#include <thread>
#include <chrono>
#include "Scheduler.hpp"
#include "StatisticsCalculator.hpp"
#include "process.hpp"
#include "global.h"
#include <QObject>

class CPUSimulator : public QObject // make it compatable with Qobject
{
    Q_OBJECT
private:
    int currentTime = 0;
    Scheduler *scheduler;
    StatisticsCalculator *calculator;
    std::vector<std::pair<int, int>> ganttChartLog; // <time, pid>
    std::map<int, Process> processMap;
    std::vector<Process> completedProcesses;

public:
    CPUSimulator(Scheduler *sched , QObject *parent = nullptr); // make it compatable with Qobject

    void addProcess(const Process &p);
    void runSimulation();
    void updateLiveTable();
    void printGanttChart();
    double avgWaitingTime();
    double avgTurnaroundTime();
    int getInitialTotalBurstTime();
    int runSimulation_notLive();
    int getCurrentTime();

signals:
    void drawProcessBlock(int row, int startTime, int colorID, int processWidth);
    void drawLabels(int pid );
    void drawLabelsWithRemainingTime(int pid, int remainingTime);
    void updateRemainingTime(int pid, int remainingTime);
    void finished();
};

#endif // CPUSIMULATOR_HPP
