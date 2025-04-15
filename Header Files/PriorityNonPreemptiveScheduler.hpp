#pragma once

#include "Headers.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"

/**
 * @brief Non-Preemptive Priority scheduling algorithm.
 *
 * This scheduler selects the ready process with the highest priority (lowest numeric value)
 * and runs it to completion. Once a process starts execution, it is not preempted by newly arriving processes.
 */
class PriorityNonPreemptiveScheduler : public Scheduler
{
private:
    /**
     * @brief Comparator for priority queue (min-heap).
     * Processes with lower `priority` values are considered higher priority.
     */
    struct ComparePriority
    {
        bool operator()(const Process &a, const Process &b)
        {
            if (a.priority == b.priority)
            {
                return a.arrivalTime > b.arrivalTime; // Earlier arrival gets higher priority
            }
            return a.priority > b.priority;  // Lower value => Higher priority        
        }
    };

    priority_queue<Process, vector<Process>, ComparePriority> readyQueue; ///< Priority queue of ready processes
    vector<Process> pending;                                              ///< List of processes that have not yet arrived

public:
    /**
     * @brief Adds a process to the pending list.
     *
     * @param p The process to be added.
     */
    void addProcess(const Process &p) override;

    /**
     * @brief Moves any processes that have arrived into the ready queue.
     *
     * @param currentTime The current simulation time.
     */
    void updateQueue(int currentTime) override;

    /**
     * @brief Returns the next process to execute, based on the highest priority.
     *
     * @param currentTime The current simulation time.
     * @return Pointer to the selected process or nullptr if the queue is empty.
     */
    Process *getNextProcess(int currentTime) override;

    /**
     * @brief Returns the remaining time for the process until completion
     *
     *
     * @param p The process being scheduled.
     * @return The remaining time of the process (full execution).
     */
    int getExecutionTimeSlice(const Process &p) override;
};
