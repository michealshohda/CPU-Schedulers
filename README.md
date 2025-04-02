# CPU Scheduler

This project implements a live CPU scheduler simulation with support for multiple scheduling algorithms, including:

1. **FCFS (First-Come-First-Served)**
2. **SJF (Shortest Job First)** – Both Preemptive and Non-Preemptive
3. **Priority Scheduling** – Both Preemptive and Non-Preemptive (lower number indicates higher priority)
4. **Round Robin**

## Features:
- **Dynamic Process Addition**: New processes can be added while the scheduler is running.
- **Live Scheduler**: Each unit of time is mapped to 1 second, with real-time updates on the process status.
- **Ready-to-Run Executable**: A built executable file for easy deployment.
- **GUI Application**: A user-friendly desktop interface.
  
## Inputs:
- Type of scheduler
- Number of processes and related process information (varies by scheduler type)
- Dynamic process addition without unnecessary prompts (e.g., no need to input priority for FCFS)

## Outputs:
- **Gantt Chart**: Timeline showing process order and time taken.
- **Live Updated Table**: Remaining burst times for processes.
- **Average Metrics**: Average waiting time and average turnaround time.
