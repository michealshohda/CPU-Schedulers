#include "RoundRobinScheduler.hpp"

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
        Process current = readyQueue.front();
        readyQueue.pop();

        if (current.startTime == -1)
        {
            current.startTime = currentTime;
        }

        int executedTime = min(timeQuantum, current.remainingTime);
        current.remainingTime -= executedTime;

        if (current.remainingTime <= 0)
        {
            current.finishTime = currentTime + executedTime;
            current.isCompleted = true;
        }
        else
        {
            readyQueue.push(current); 
        }

        return current; 
    }

    return nullptr;
}

int getExecutionTimeSlice(const Process &p)
{
    return min(p.remainingTime, timeQuantum);
}
