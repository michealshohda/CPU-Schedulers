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

// int StatisticsCalculator::getTotalBurstTime(const std::map<int, Process> &processMap)
// {
//     int total = 0;
//     for (const auto &[pid, process] : processMap)
//     {
//         total += process.burstTime;
//     }
//     return total;
// }
int StatisticsCalculator::getTotalBurstTime(const std::map<int, Process> &processMap)
{
    // Step 1: Extract and sort by arrival time
    std::vector<Process> sortedProcesses;
    for (const auto &[pid, process] : processMap)
    {
        sortedProcesses.push_back(process);
    }

    std::sort(sortedProcesses.begin(), sortedProcesses.end(), [](const Process &a, const Process &b) {
        return a.arrivalTime < b.arrivalTime;
    });

    // Step 2: Simulate scheduling to include idle time
    int currentTime = 0;
    int totalTime = 0;

    for (const auto &process : sortedProcesses)
    {
        if (process.arrivalTime > currentTime)
        {
            // Add idle time
            totalTime += process.arrivalTime - currentTime;
            currentTime = process.arrivalTime;
        }

        totalTime += process.burstTime;
        currentTime += process.burstTime;
    }

    return totalTime;
}

