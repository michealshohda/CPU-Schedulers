#pragma once

/**
 * @brief Represents a process in a scheduling simulation.
 */
struct Process
{
    int pid;                  ///< Process ID
    int arrivalTime;          ///< Time when the process arrives
    int burstTime;            ///< Total execution time required by the process
    int remainingTime;        ///< Remaining execution time
    int priority;             ///< Priority of the process (lower value means higher priority)
    int startTime = -1;       ///< Time when the process starts execution
    int finishTime = -1;      ///< Time when the process finishes execution
    bool isCompleted = false; ///< Completion status of the process

    /**
     * @brief Constructs a new Process object with specified values.
     *
     * @param id         The process ID.
     * @param arrival    The arrival time of the process.
     * @param burst      The burst (execution) time of the process.
     * @param priority   The priority of the process (optional, default is -1).
     */
    Process(int id, int arrival, int burst, int priority = -1)
        : pid(id), arrivalTime(arrival), burstTime(burst),
          remainingTime(burst), priority(priority) {}

    /**
     * @brief Default constructor for Process.
     */
    Process() : pid(-1), arrivalTime(0), burstTime(0),
                remainingTime(0), priority(-1) {}
};
