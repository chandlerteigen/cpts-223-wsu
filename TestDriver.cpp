/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 11-14-19
 * Description: This project was created to fulfill the assignment PA5
 * 				for CPTS 223 at WSU fall 2019. It consists of a scheduler
 *              which schedules processor time to jobs using a min heap
 *              to determine the job with the shortest run-time.
************************************************************************/


/*
To compile the code: g++ Job.cpp Scheduler.cpp TestDriver.cpp Processor.cpp -o ex
To run the exe:      ./ex
*/


#include "Scheduler.h"
#include <queue>
#include <initializer_list>
#include <vector>
#include "Job.h"


int main(void)
{
    //the name of the input file
    const char* input_file_name = "job_list.txt"; 
    int number_of_processors;

    std::cout << "How many processors would you like to use? ";
    std::cin >> number_of_processors;

    Scheduler sched(number_of_processors, input_file_name);

    sched.run();

    std::cout << "The scheduler has stopped." << std::endl;


    return 0;
}
