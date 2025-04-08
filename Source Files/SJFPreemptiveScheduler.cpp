#include "SJFPreemptiveScheduler.hpp"

void SJFPScheduler::addProcess(const Process& p)
{
    pending.push_back(p);
}

void SJFPScheduler::updateQueue(int currentTime) {
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

Process* SJFPScheduler::getNextProcess(int currentTime) {
    if (!minHeap.empty()) {
        Process* next = new Process(minHeap.top());
        minHeap.pop();
        return next;
    }
    return nullptr;
}

int SJFPScheduler::getExecutionTimeSlice(const Process& p) {
    if (p.remainingTime == 2)
        return 2;

    return 1;
}