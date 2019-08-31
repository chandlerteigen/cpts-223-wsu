#include "Timer.h"
#include <iostream>

Timer::Timer(){}

Timer::~Timer(){}

std::chrono::microseconds Timer::getLength()
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
    length = std::chrono::duration_cast<std::chrono::microseconds> (stopTime - startTime);
    

}

void Timer::printTime()
{
    std::cout << length.count() << "us" << std::endl;
}