#include "StopWatch.h"
#include <iostream>
#include <ctime>

using namespace std;



Stopwatch::Stopwatch()
{
    isrunning = false;
    paused=false;
    start = 0.0;
    stop = 0.0;
}

double Stopwatch::getProcessTime()  // returns the amount of time in seconds that has passed since the process (i.e. your program) started executing
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC; //returns process time in seconds
}

void Stopwatch::Start() //Starts the stopwatch
{
    if(!isrunning)
    {
        start = getProcessTime();
    }
    isrunning =true;
}

void Stopwatch::Stop() //Stops the stopwatch
{
    if(isrunning)
    {
        stop = getProcessTime();
    }

    isrunning=false;
}

void Stopwatch::Reset() //Resets all values to zero
{
start=0.0;
stop=0.0;

if(isrunning)
{
   isrunning=false;
}
if(paused)
{
    paused=false;
}
}

void Stopwatch::Pause()
{
    Pausetime=getProcessTime(); //process time at the moment the pause function is called is recorded
    paused=true;
}

void Stopwatch::Resume()
{
    Resumetime=getProcessTime(); //process time at the moment the resume function is called is recorded
}

double Stopwatch::ReturnTime()
{
    if(!paused)
    {
    auto ans = stop-start; // the runtime between when the start and the stop function were called is calculated
    return ans;
    }
    else
    {
      auto ans =(stop-start)-(Resumetime-Pausetime); //If the pause and resume function was called,the runtime between the two functions is cut from start and stop function
      return ans;
    }

}

