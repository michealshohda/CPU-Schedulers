#ifndef GLOBAL_H
#define GLOBAL_H

class Scheduler;
class CPUSimulator;

extern Scheduler *scheduler;
extern CPUSimulator *sim;
extern int pid_Global; // global pid that is givied to the new process
#endif // GLOBAL_H
