#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <ctime>

using namespace std;
// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing
class Stopwatch
{
public :
    Stopwatch();
    void Start();
    void Stop();
    void Reset();
    void Pause();
    void Resume();
    double ReturnTime();

private :
    double start,stop,Pausetime,Resumetime;
    bool isrunning,paused;
    double getProcessTime();
};



#endif
