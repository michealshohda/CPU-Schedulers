#include "CPUSimulator.hpp"
#include "mainwindow.h"

CPUSimulator::CPUSimulator(Scheduler *sched , QObject *parent) :  QObject(parent), scheduler(sched) {}

void CPUSimulator::addProcess(const Process &p)
{
    scheduler->addProcess(p);
    processMap[p.pid] = p;
}

void CPUSimulator::runSimulation()
{
    for (auto it = processMap.begin(); it != processMap.end(); ++it) {
        emit drawLabelsWithRemainingTime(it->first,it->second.burstTime);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    while (!processMap.empty())
    {
        scheduler->updateQueue(currentTime);
        Process *p = scheduler->getNextProcess(currentTime);

        if (p != nullptr)
        {
            int pid = p->pid;

            if (processMap[pid].startTime == -1)
                processMap[pid].startTime = currentTime;

            int timeSlice = scheduler->getExecutionTimeSlice(processMap[pid]);
            while (timeSlice-- > 0 && processMap[pid].remainingTime > 0)
            {
                ganttChartLog.push_back({currentTime, pid});

                processMap[pid].remainingTime--;
                emit updateRemainingTime(pid,processMap[pid].remainingTime);

                emit drawProcessBlock(0,currentTime,pid,1); //signal to gui

                updateLiveTable();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                currentTime++;
            }

            if (processMap[pid].remainingTime == 0)
            {
                emit updateRemainingTime(pid,processMap[pid].remainingTime);
                processMap[pid].finishTime = currentTime;
                processMap[pid].isCompleted = true;
                completedProcesses.push_back(processMap[pid]);
                processMap.erase(pid);
            }
            else
            {
                scheduler->addProcess(processMap[pid]);
            }

            delete p;
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            currentTime++;
        }
    }
    // emit finished();
}

int CPUSimulator::runSimulation_notLive(){
    while (!processMap.empty())
    {
        scheduler->updateQueue(currentTime);
        Process *p = scheduler->getNextProcess(currentTime);

        if (p != nullptr)
        {
            int pid = p->pid;

            if (processMap[pid].startTime == -1)
                processMap[pid].startTime = currentTime;

            int timeSlice = scheduler->getExecutionTimeSlice(processMap[pid]);
            while (timeSlice-- > 0 && processMap[pid].remainingTime > 0)
            {
                ganttChartLog.push_back({currentTime, pid});
                processMap[pid].remainingTime--;

                emit drawProcessBlock(0,currentTime,pid,1); //signal to gui
                emit drawLabels(pid);

                updateLiveTable();
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                currentTime++;
            }

            if (processMap[pid].remainingTime == 0)
            {
                processMap[pid].finishTime = currentTime;
                processMap[pid].isCompleted = true;
                completedProcesses.push_back(processMap[pid]);
                processMap.erase(pid);
            }
            else
            {
                scheduler->addProcess(processMap[pid]);
            }

            delete p;
        }
        else
        {
            //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            currentTime++;
        }
    }
}


void CPUSimulator::updateLiveTable()
{
    std::cout << "\nTime: " << currentTime + 1 << "\n";
    std::cout << "Live Table:\n";
    for (const auto &[pid, p] : processMap)
    {
        std::cout << "PID: " << pid << " | Remaining Time: " << p.remainingTime << "\n";
    }
    std::cout << "----------------------------\n";
}

void CPUSimulator::printGanttChart()
{
    std::cout << "\nGantt Chart:\n| ";
    for (const auto &[time, pid] : ganttChartLog)
    {
        if (pid == -1)
            std::cout << "Idle | ";
        else
            std::cout << "P" << pid << " | ";
    }
    std::cout << "\n";
}

double CPUSimulator::avgWaitingTime()
{
    calculator = new StatisticsCalculator(completedProcesses);
    return calculator->getAverageWaitingTime();
}

double CPUSimulator::avgTurnaroundTime()
{
    calculator = new StatisticsCalculator(completedProcesses);
    return calculator->getAverageTurnaroundTime();
}

int CPUSimulator::getInitialTotalBurstTime()
{
    return StatisticsCalculator::getTotalBurstTime(processMap);
}

int CPUSimulator::getCurrentTime(){
    return currentTime;
}
