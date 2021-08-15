#include "StopWatch.h"
#include <iostream>

using namespace std;

int main()
{

Stopwatch a;
float i=0,c=0;

a.Start();

  while( i<10000000)
  {
      while(c<10000000)
      {
         c++;
      }

      i++;
  }
   i=0;
   c=0;

a.Pause();
   while( i<10000000)
  {
      while(c<10000000)
      {
         c++;
      }

      i++;
  }
a.Resume();

a.Stop();

auto ans = a.ReturnTime();
cout << ans<<"s"<< endl;
    return 0;
}
