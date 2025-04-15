#include "RoundRobinScheduler.hpp"

RoundRobinScheduler::RoundRobinScheduler(int quantum)
{
    quantumTime=quantum;
}

void RoundRobinScheduler::addProcess(const Process &p)
{
    pending.push_back(p);
}

void RoundRobinScheduler::updateQueue(int currentTime)
{
    auto it = pending.begin();
    while (it != pending.end())
    {
        Process process = *it;
        if (process.arrivalTime <= currentTime)
        {
            readyQueue.push(process);
            it = pending.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

Process *RoundRobinScheduler::getNextProcess(int currentTime)
{
    if (!readyQueue.empty())
    {
        Process *next = new Process(readyQueue.front());
        readyQueue.pop();
        return next;
    }
    return nullptr;
}

int RoundRobinScheduler::getExecutionTimeSlice(const Process &p)
{
    return min(p.remainingTime, quantumTime);
}
