#include "Timer.h"
#include <iostream>

Timer::Timer(){}

Timer::~Timer(){}

std::chrono::nanoseconds Timer::getLength()
{
    return length;
}

void Timer::start()
{
    startTime = std::chrono::high_resolution_clock::now();
}
void Timer::stop()
{
    stopTime = std::chrono::high_resolution_clock::now();
    length = std::chrono::duration_cast<std::chrono::nanoseconds> (stopTime - startTime);
    

}

void Timer::printTime()
{
    std::cout << length.count() / 1000000 << "ms" << std::endl;
}