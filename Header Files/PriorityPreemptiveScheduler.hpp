#pragma once

#include "Headers.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"

/**
 * @brief Preemptive Priority scheduling algorithm.
 *
 * This scheduler selects the ready process with the highest priority (lowest numeric value)
 * and allows it to run for one time unit before reevaluating. If a higher-priority process arrives,
 * it preempts the currently running process.
 */
class PriorityPreemptiveScheduler : public Scheduler
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
            return a.priority > b.priority;
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
     * @brief Specifies that each process runs for one time unit before reevaluation.
     *
     * This enables preemption, allowing the scheduler to check for higher-priority processes.
     *
     * @param p The process being scheduled.
     * @return Always returns 1 for preemptive behavior.
     */
    int getExecutionTimeSlice(const Process &p) override;
};
