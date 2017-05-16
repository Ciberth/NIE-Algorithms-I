#ifndef __STOPWATCH
#define __STOPWATCH
#include <time.h>//Borland heeft het moeilijk met ctime

class Stopwatch{
    public:
    clock_t begin, eind;
    Stopwatch(){
        start();
    }
    void start(){
        begin=clock();
    }
    void stop(){
        eind=clock();
    }
    double tijd(){
        return (double)(eind-begin)/CLOCKS_PER_SEC;
    }
};

#endif
