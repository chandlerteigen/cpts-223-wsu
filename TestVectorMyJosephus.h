/*
Programmer: Chandler Teigen
Date:       10-7-19
Description: tests the operation of the josephus problem classes for 
             PA3 in CPTS 223 Fall 2019
*/

#ifndef __TESTVECTORMYJOSEPHUS__
#define __TESTVECTORMYJOSEPHUS__

#include "VectorMyJosephus.h"
#include "Timer.h"
#include <fstream>
class TestVectorMyJosephus
{
    public:

    TestVectorMyJosephus();
    ~TestVectorMyJosephus();

    void testGame();

    private:
    Timer elimTimer;
    Timer totalTimer; 
    
    long long totalTime;
    long long averageElimTime;

    VectorMyJosephus josephusGame;

    
};

#endif