#pragma once

#include "Headers.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"

/**
 * @brief First-Come, First-Served (FCFS) scheduling algorithm.
 *
 * This scheduler selects the process that arrived first (i.e., the earliest arrival time)
 * and runs it to completion. It uses a queue to manage ready processes.
 */
class FCFSScheduler : public Scheduler
{
private:
    std::queue<Process> readyQueue; ///< Queue of ready-to-run processes
    std::vector<Process> pending;   ///< List of processes that have not yet arrived

public:
    /**
     * @brief Adds a process to the pending list.
     *
     * @param p The process to be added.
     */
    void addProcess(const Process &p) override;

    /**
     * @brief Updates the ready queue by moving processes whose arrival time has passed.
     *
     * @param currentTime The current simulation time.
     */
    void updateQueue(int currentTime) override;

    /**
     * @brief Retrieves the next process to run based on FCFS policy.
     *
     * @param currentTime The current simulation time.
     * @return Pointer to the next process or nullptr if no process is ready.
     */
    Process *getNextProcess(int currentTime) override;
};
