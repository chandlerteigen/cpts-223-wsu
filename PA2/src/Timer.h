#include <chrono>


class Timer
{
public:
Timer();
~Timer();

std::chrono::nanoseconds getLength();

void start();

void stop();

void printTime();

private:
    std::chrono::high_resolution_clock::time_point startTime, stopTime;
    std::chrono::nanoseconds length;
};
