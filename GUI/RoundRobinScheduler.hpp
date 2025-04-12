#pragma once

#include "Headers.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"
#define QUANTUM_TIME 2

class RoundRobinScheduler:public Scheduler
{
private:
    std::vector<Process> pending;
    std::queue<Process> readyQueue;
    int quantumTime;

public:
    RoundRobinScheduler(int quantum);
    void addProcess(const Process &p);
    void updateQueue(int currentTime);
    Process *getNextProcess(int currentTime);
    
    int getExecutionTimeSlice(const Process &p);
};


