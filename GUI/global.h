#ifndef GLOBAL_H
#define GLOBAL_H

class Scheduler;
class CPUSimulator;
class MainWindow;

extern Scheduler *scheduler;
extern CPUSimulator *sim;
extern MainWindow *w;
extern int pid_Global; // global pid that is givied to the new process
#endif // GLOBAL_H
