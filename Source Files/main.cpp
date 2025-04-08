#include"Headers.hpp"
#include"FCFSScheduler.hpp"
#include"PriorityNonPreemptiveScheduler.hpp"
#include"PriorityPreemptiveScheduler.hpp"
#include"RoundRobinScheduler.hpp"
#include"StatisticsCalculator.hpp"
#include <map>
#include <thread>
#include <chrono>
class CPUSimulator
{
private:
    int currentTime = 0;
    Scheduler *scheduler;
    StatisticsCalculator *calculator;
    vector<pair<int, int>> ganttChartLog; // <time, pid>
    map<int, Process> processMap;         // Live table
    vector<Process> completedProcesses;

public:
    CPUSimulator(Scheduler *sched) : scheduler(sched) {}

    void addProcess(const Process &p)
    {
        scheduler->addProcess(p);
        processMap[p.pid] = p;
    }

    void runSimulation()
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

                // Ask scheduler how long to run this process
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
                    scheduler->addProcess(processMap[pid]); // Preempted
                    //scheduler->updateQueue(currentTime);
                }

                delete p;
            }
            else
            {
                ganttChartLog.push_back({currentTime, -1}); // Idle
                updateLiveTable();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                currentTime++;
            }
        }
    }

    void updateLiveTable()
    {
        std::cout << "\nTime: " << currentTime + 1 << "\n";
        std::cout << "Live Table:\n";
        for (const auto &[pid, p] : processMap)
        {
            std::cout << "PID: " << pid << " | Remaining Time: " << p.remainingTime << "\n";
        }
        std::cout << "----------------------------\n";
    }

    void printGanttChart()
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

    double avgWaitingTime()
    {
        calculator = new StatisticsCalculator(completedProcesses);
        return calculator->getAverageWaitingTime();
    }

    double avgTurnaroundTime()
    {
        calculator = new StatisticsCalculator(completedProcesses);
        return calculator->getAverageTurnaroundTime();
    }
};

int main()
{
    cout<<"Hello to CPU Simulator\n"
    <<"\n-------------------------------------------------------\n"
    <<"Please choose the type of schedule you want:\n"
    <<"1.FCFS Schedule\n"
    <<"2.RoundRobin Schedule\n"
    <<"3.Priority Preemptive Schedule\n"
    <<"4.Priority non Preemptive Schedule\n";
    int choice;
    cin>>choice;

    Scheduler *scheduler;
    if(choice == 1) scheduler = new FCFSScheduler();
    else if(choice == 2) scheduler = new RoundRobinScheduler();
    else if(choice == 3) scheduler = new PriorityPreemptiveScheduler();
    else if(choice == 4) scheduler = new PriorityNonPreemptiveScheduler();
    
    CPUSimulator sim(scheduler);

    cout<<"\n-------------------------------------------------------\n"
    <<"please enter number of proccesses:\n";
    int number;
    cin>>number;
    cout<<"Enter arrival time and burst time\n"
    <<"           arrival time     burst time\n";
    for(int i=1;i<=number;i++)
    {
        int a,b,p;
        cout<<"process "<<i<<":";
        cin>>a>>b>>p;
        sim.addProcess(Process(i, a, b,p));
    }

    
    sim.runSimulation();
   // std::thread simThread([&sim]()
     //                     { sim.runSimulation(); });

    // Simulate new process arriving after 1 second
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //sim.addProcess(Process(3, 4, 2));

    //simThread.join();
    sim.printGanttChart();

    cout << "waiting Time: " << sim.avgWaitingTime() << endl;
    cout << "Turnaround Time: " << sim.avgTurnaroundTime() << endl;
    return 0;
   
}