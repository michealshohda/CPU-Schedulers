#pragma once

#include "Headers.hpp"
#include "Process.hpp"

/**
 * @class StatisticsCalculator
 * @brief Calculates various scheduling statistics for a set of completed processes.
 */
class StatisticsCalculator
{
private:
    std::vector<Process> processes; ///< Stores the list of completed processes.

public:
    /**
     * @brief Constructor to initialize the calculator with completed processes.
     * @param completedProcesses Vector of completed Process objects.
     */
    StatisticsCalculator(const std::vector<Process> &completedProcesses);

    /**
     * @brief Returns the turnaround time for each process.
     * @return Vector of turnaround times.
     */
    std::vector<int> getTurnaroundTimes() const;

    /**
     * @brief Returns the waiting time for each process.
     * @return Vector of waiting times.
     */
    std::vector<int> getWaitingTimes() const;

    /**
     * @brief Calculates the average turnaround time.
     * @return Average turnaround time.
     */
    double getAverageTurnaroundTime() const;

    /**
     * @brief Calculates the average waiting time.
     * @return Average waiting time.
     */
    double getAverageWaitingTime() const;

    static int getTotalBurstTime(const std::map<int, Process> &processMap);
};
