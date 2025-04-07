#pragma once

#include "Headers.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"

class RoundRobinScheduler
{
private:
    std::vector<Process> pending;
    std::queue<Process> readyQueue;

public:
    static const int timeQuantum = 2; 

    void addProcess(const Process &p);
    void updateQueue(int currentTime);
    Process *getNextProcess(int currentTime);
    
    int getExecutionTimeSlice(const Process &p);
};


