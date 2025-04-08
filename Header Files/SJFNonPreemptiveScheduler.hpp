#pragma once

#include "Headers.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"

/*This is Functor (struct that acts like Function) that Overloads () operator 
    and used in priority queue to make min heap according to burst time*/
struct CompareByBurstTime {
    bool operator()(const Process& a, const Process& b) {
        return a.burstTime > b.burstTime;
    }
};


class SJFNPScheduler : public Scheduler
{
private:
    priority_queue<Process, vector<Process>, CompareByBurstTime> minHeap;///< Min Heap based On burst Time
    std::vector<Process> pending;///< List of processes that have not yet arrived

public:
    /**
     * @brief Adds a process to the pending list.
     *
     * @param p The process to be added.
     */
    void addProcess(const Process& p) override;

    /**
     * @brief Updates the ready queue (Min Heap) by moving processes whose arrival time has passed.
     *
     * @param currentTime The current simulation time.
     */
    void updateQueue(int currentTime) override;

    /**
     * @brief Retrieves the next process to run based on SJF Non Preemptive policy.
     *
     * @param currentTime The current simulation time.
     * @return Pointer to the next process or nullptr if no process is ready.
     */
    Process* getNextProcess(int currentTime) override;

    /**
     * @brief Determines how many time units a given process should run before yielding the CPU.
     *
     * @param p The process to evaluate for execution.
     * @return The number of time units the process should be allowed to run before a context switch.
     */
    int getExecutionTimeSlice(const Process& p) override;
};