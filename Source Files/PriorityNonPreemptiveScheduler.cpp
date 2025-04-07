#include "PriorityNonPreemptiveScheduler.hpp"

void PriorityNonPreemptiveScheduler::addProcess(const Process &p)
{
    pending.push_back(p);
}

void PriorityNonPreemptiveScheduler::updateQueue(int currentTime)
{
    auto it = pending.begin();
    while (it != pending.end())
    {
        if (it->arrivalTime <= currentTime)
        {
            readyQueue.push(*it);
            it = pending.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

Process *PriorityNonPreemptiveScheduler::getNextProcess(int currentTime)
{
    if (!readyQueue.empty())
    {
        Process *next = new Process(readyQueue.top());
        readyQueue.pop();
        return next;
    }
    return nullptr;
}

int PriorityNonPreemptiveScheduler::getExecutionTimeSlice(const Process &p)
{
    return p.remainingTime; // Non-preemptive: run until completion
}
