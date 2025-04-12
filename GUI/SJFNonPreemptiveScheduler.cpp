#include "SJFNonPreemptiveScheduler.hpp"

void SJFNPScheduler::addProcess(const Process& p)
{
    pending.push_back(p);
}

void SJFNPScheduler::updateQueue(int currentTime) {
    auto it = pending.begin();
    while (it != pending.end())
    {
        if (it->arrivalTime <= currentTime)
        {
            minHeap.push(*it);
            it = pending.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

Process* SJFNPScheduler::getNextProcess(int currentTime) {
    if (!minHeap.empty()) {
        Process* next = new Process(minHeap.top());
        minHeap.pop();
        return next;
    }
    return nullptr;
}

int SJFNPScheduler::getExecutionTimeSlice(const Process& p) {
    return p.remainingTime; // run to completion
}