#include "PriorityPreemptiveScheduler.hpp"

void PriorityPreemptiveScheduler::addProcess(const Process &p)
{
    pending.push_back(p);
}

void PriorityPreemptiveScheduler::updateQueue(int currentTime)
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

Process *PriorityPreemptiveScheduler::getNextProcess(int currentTime)
{
    if (!readyQueue.empty())
    {
        Process *next = new Process(readyQueue.top());
        readyQueue.pop();
        return next;
    }
    return nullptr;
}

int PriorityPreemptiveScheduler::getExecutionTimeSlice(const Process &p)
{
    return 1; // Preemptive: run for 1 time unit then reevaluate
}
