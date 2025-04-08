#include "FCFSScheduler.hpp"

void FCFSScheduler::addProcess(const Process &p)
{
    pending.push_back(p);
}

void FCFSScheduler::updateQueue(int currentTime)
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

Process *FCFSScheduler::getNextProcess(int currentTime)
{
    if (!readyQueue.empty())
    {
        Process *next = new Process(readyQueue.front());
        readyQueue.pop();
        return next;
    }
    return nullptr;
}

int FCFSScheduler::getExecutionTimeSlice(const Process &p)
{
    return p.remainingTime; // run to completion
}