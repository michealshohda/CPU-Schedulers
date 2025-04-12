#include "StatisticsCalculator.hpp"

StatisticsCalculator::StatisticsCalculator(const vector<Process> &completedProcesses)
    : processes(completedProcesses)
{
}



vector<int> StatisticsCalculator::getTurnaroundTimes() const
{
    vector<int> turnaroundTimes;
    for (const auto &p : processes)
    {
        turnaroundTimes.push_back(p.finishTime - p.arrivalTime);
    }
    return turnaroundTimes;
}

vector<int> StatisticsCalculator::getWaitingTimes() const
{
    vector<int> waitingTimes;
    for (const auto &p : processes)
    {
        int turnaroundTime = p.finishTime - p.arrivalTime;
        int waitingTime = turnaroundTime - p.burstTime;
        waitingTimes.push_back(waitingTime);
    }
    return waitingTimes;
}

double StatisticsCalculator::getAverageTurnaroundTime() const
{
    auto tat = getTurnaroundTimes();
    return static_cast<double>(accumulate(tat.begin(), tat.end(), 0)) / tat.size();
}

double StatisticsCalculator::getAverageWaitingTime() const
{
    auto wt = getWaitingTimes();
    return static_cast<double>(accumulate(wt.begin(), wt.end(), 0)) / wt.size();
}

int StatisticsCalculator::getTotalBurstTime(const std::map<int, Process> &processMap)
{
    int total = 0;
    for (const auto &[pid, process] : processMap)
    {
        total += process.burstTime;
    }
    return total;
}
