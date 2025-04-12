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

class CPUSimulator
{
private:
    int currentTime = 0;
    Scheduler *scheduler;
    StatisticsCalculator *calculator;
    std::vector<std::pair<int, int>> ganttChartLog; // <time, pid>
    std::map<int, Process> processMap;
    std::vector<Process> completedProcesses;

public:
    CPUSimulator(Scheduler *sched);

    void addProcess(const Process &p);
    void runSimulation();
    void updateLiveTable();
    void printGanttChart();
    double avgWaitingTime();
    double avgTurnaroundTime();
    int getInitialTotalBurstTime();
};

#endif // CPUSIMULATOR_HPP
