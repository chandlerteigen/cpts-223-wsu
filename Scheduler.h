/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 11-14-19
 * Description: This project was created to fulfill the assignment PA5
 * 				for CPTS 223 at WSU fall 2019. It consists of a scheduler
 *              which schedules processor time to jobs using a min heap
 *              to determine the job with the shortest run-time.
************************************************************************/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Processor.h"
#include "Job.h"
#include <queue>
#include <vector>
#include <algorithm>

class Scheduler
{
public:
    Scheduler(int new_num_procs, const char* job_list);

    ~Scheduler();

/**************************************************************************************
* Function: Scheduler::run
* Arguments: void
* Returns: void
* Description: calls Scheduler::tick until the return value is false;
***************************************************************************************/
    void run();
    
    static unsigned int tick_number;

private:

/**************************************************************************************
* Function: Scheduler::tick
* Arguments: void
* Returns: bool
* Description: looks for new jobs in the job list file, processes jobs in the waiting
               queue and the running queue, returns true if another tick should happen 
***************************************************************************************/
    bool tick();

/**************************************************************************************
* Function: Scheduler::insert_job
* Arguments: Job
* Returns: void
* Description: adds the Job to the waiting queue if it has valid n_procs and n_ticks values
***************************************************************************************/
    void insert_job(Job new_job);

/**************************************************************************************
* Function: Scheduler::find_shortest
* Arguments: void
* Returns: Job
* Description: returns the Job in the waiting queue with the smallest n_ticks value
***************************************************************************************/
    Job find_shortest();

/**************************************************************************************
* Function: Scheduler::delete_shortest
* Arguments: void
* Returns: void
* Description: deletes the Job in the waiting queue with thr smallest n_ticks value
***************************************************************************************/
    void delete_shortest();

/**************************************************************************************
* Function: Scheduler::check_availability
* Arguments: int
* Returns: bool
* Description: returns true if num_needed_procs is less than or equal to the number of
               free Processors in the processor_bank 
***************************************************************************************/
    bool check_availability(int num_needed_procs);

/**************************************************************************************
* Function: Scheduler::run_job
* Arguments: Job
* Returns: void
* Description: removes the number of procs needed from num_free_procs, pushes job onto
               running queue min heap, and assigns procs to the job 
***************************************************************************************/
    void run_job(Job job);

/**************************************************************************************
* Function: Scheduler::erase_finsihed_jobs
* Arguments: void
* Returns: void
* Description: iterates through running jobs, if any have ticks_left at 0, they are
               erases and their Processors are releases; 
***************************************************************************************/
    void erase_finished_jobs();

/**************************************************************************************
* Function: Scheduler::assign_procs
* Arguments: Job&
* Returns: void
* Description: iterates over processor_bank and assigns Processors to the job until
               enough have been assigned. 
***************************************************************************************/
    void assign_procs(Job &job);

/**************************************************************************************
* Function: Scheduler::release_procs
* Arguments: int
* Returns: void
* Description: iterates through processor_bank and releases any Processors assigned to the
               job 
***************************************************************************************/
    void release_procs(int job_int);

/**************************************************************************************
* Function: Scheduler::decrement_timer
* Arguments: void
* Returns: void
* Description: iterates through the running queue and decrements each ticks_left value
***************************************************************************************/
    void decrement_timer();

/**************************************************************************************
* Function: Scheduler::print_tick_info
* Arguments: void
* Returns: void
* Description: prints the relevant information about the current tick
***************************************************************************************/
    void print_tick_info();

    int num_procs;
    int num_free_procs;
    std::priority_queue< Job, std::vector<Job>, Job_N_Ticks_Greater > waiting_job_queue; 
    std::vector<Job> running_job_queue;
    std::vector<Processor> processor_bank;
    std::ifstream job_input_file;
};

#endif