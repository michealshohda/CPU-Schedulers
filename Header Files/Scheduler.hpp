#pragma once
#include "process.hpp"

/**
 * @brief Abstract base class for different CPU scheduling algorithms.
 *
 * This class defines a common interface for adding processes,
 * retrieving the next process to execute, and updating the
 * scheduling queue based on the current time.
 */
class Scheduler
{
public:
    /**
     * @brief Adds a process to the scheduler's queue.
     *
     * @param p The process to be added.
     */
    virtual void addProcess(const Process &p) = 0;

    /**
     * @brief Retrieves the next process to execute based on the scheduling policy.
     *
     * @param currentTime The current simulation time.
     * @return A pointer to the selected Process, or nullptr if no process is ready.
     */
    virtual Process *getNextProcess(int currentTime) = 0;

    /**
     * @brief Updates the scheduling queue based on the current time.
     *
     * This can be used to manage arrival of new processes or to re-evaluate the queue.
     *
     * @param currentTime The current simulation time.
     */
    virtual void updateQueue(int currentTime) = 0;
    /**
     * @brief Determines how many time units a given process should run before yielding the CPU.
     *
     * This function allows the scheduler to control whether a process should run for its full
     * remaining burst time (non-preemptive), a fixed time slice (e.g., in Round Robin), or just
     * one unit at a time (e.g., in preemptive scheduling strategies).
     *
     * @param p The process to evaluate for execution.
     * @return The number of time units the process should be allowed to run before a context switch.
     */
    virtual int getExecutionTimeSlice(const Process &p) = 0;
    /**
     * @brief Virtual destructor.
     */
    virtual ~Scheduler() {}
};
