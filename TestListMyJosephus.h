#ifndef __TESTLISTMYJOSEPHUS__
#define __TESTLISTMYJOSEPHUS__

#include "ListMyJosephus.h"
#include "Timer.h"
#include <fstream>
class TestListMyJosephus
{
public:
    TestListMyJosephus();

    ~TestListMyJosephus();

    void testGame();

private:

    ListMyJosephus josephusGame;
    Timer elimTimer;
    Timer totalTimer; 
    
    long long totalTime;
    long long averageElimTime;

};



#endif