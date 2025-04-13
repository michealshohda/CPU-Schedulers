#include "CPUSimulator.hpp"

CPUSimulator::CPUSimulator(Scheduler *sched) : scheduler(sched) {}

void CPUSimulator::addProcess(const Process &p)
{
    scheduler->addProcess(p);
    processMap[p.pid] = p;
}

void CPUSimulator::runSimulation()
{
    while (!processMap.empty())
    {
        scheduler->updateQueue(currentTime);
        Process *p = scheduler->getNextProcess(currentTime);

        if (p != nullptr)
        {
            int pid = p->pid;

            if (processMap[pid].startTime == -1)
                processMap[pid].startTime = currentTime;

            int timeSlice = scheduler->getExecutionTimeSlice(processMap[pid]);
            while (timeSlice-- > 0 && processMap[pid].remainingTime > 0)
            {
                ganttChartLog.push_back({currentTime, pid});
                processMap[pid].remainingTime--;
                updateLiveTable();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                currentTime++;
            }

            if (processMap[pid].remainingTime == 0)
            {
                processMap[pid].finishTime = currentTime;
                processMap[pid].isCompleted = true;
                completedProcesses.push_back(processMap[pid]);
                processMap.erase(pid);
            }
            else
            {
                scheduler->addProcess(processMap[pid]);
            }

            delete p;
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            currentTime++;
        }
    }
}

int CPUSimulator::runSim_2(){
    /**
     * just testing ab2a shelhaaa
     *
 * Runs one step of the simulation and returns the PID of the currently executing process.
 * @return PID of the running process (-1 if idle or no process is running).
 */

        scheduler->updateQueue(currentTime);
        Process *p = scheduler->getNextProcess(currentTime);

        if (p != nullptr) {
            int pid = p->pid;

            // Initialize start time if this is the first execution
            if (processMap[pid].startTime == -1) {
                processMap[pid].startTime = currentTime;
            }

            // Execute for the scheduler's time slice (or until completion)
            int timeSlice = scheduler->getExecutionTimeSlice(processMap[pid]);
            while (timeSlice-- > 0 && processMap[pid].remainingTime > 0) {
                ganttChartLog.push_back({currentTime, pid});
                processMap[pid].remainingTime--;
                updateLiveTable();
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                currentTime++;
            }

            // Check if process completed
            if (processMap[pid].remainingTime == 0) {
                processMap[pid].finishTime = currentTime;
                processMap[pid].isCompleted = true;
                completedProcesses.push_back(processMap[pid]);
                processMap.erase(pid);
            } else {
                // Re-add to scheduler if not completed
                scheduler->addProcess(processMap[pid]);
            }

            delete p;
            return pid; // Return the PID of the executed process
        } else {
            // No process to execute (idle time)
            ganttChartLog.push_back({currentTime, -1}); // Log idle time
            //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            currentTime++;
            return -1; // Return -1 to indicate idle
        }

}

void CPUSimulator::updateLiveTable()
{
    std::cout << "\nTime: " << currentTime + 1 << "\n";
    std::cout << "Live Table:\n";
    for (const auto &[pid, p] : processMap)
    {
        std::cout << "PID: " << pid << " | Remaining Time: " << p.remainingTime << "\n";
    }
    std::cout << "----------------------------\n";
}

void CPUSimulator::printGanttChart()
{
    std::cout << "\nGantt Chart:\n| ";
    for (const auto &[time, pid] : ganttChartLog)
    {
        if (pid == -1)
            std::cout << "Idle | ";
        else
            std::cout << "P" << pid << " | ";
    }
    std::cout << "\n";
}

double CPUSimulator::avgWaitingTime()
{
    calculator = new StatisticsCalculator(completedProcesses);
    return calculator->getAverageWaitingTime();
}

double CPUSimulator::avgTurnaroundTime()
{
    calculator = new StatisticsCalculator(completedProcesses);
    return calculator->getAverageTurnaroundTime();
}

int CPUSimulator::getInitialTotalBurstTime()
{
    return StatisticsCalculator::getTotalBurstTime(processMap);
}
