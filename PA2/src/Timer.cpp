#include "Timer.h"
#include <iostream>

Timer::Timer(){}

Timer::~Timer(){}

std::chrono::nanoseconds Timer::getLength()
{
    return length; // return length of elapsed time in nanoseconds
}

void Timer::start()
{
    startTime = std::chrono::high_resolution_clock::now(); // records current time as starting time
}
void Timer::stop()
{
    stopTime = std::chrono::high_resolution_clock::now(); // records current time as ending time
    length = std::chrono::duration_cast<std::chrono::nanoseconds> (stopTime - startTime); // calculate difference between stop and start
    

}

void Timer::printTime()
{
    std::cout << length.count() / 1000000 << "ms" << std::endl; // print time in milliseconds
}