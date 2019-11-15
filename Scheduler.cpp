/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 11-14-19
 * Description: This project was created to fulfill the assignment PA5
 * 				for CPTS 223 at WSU fall 2019. It consists of a scheduler
 *              which schedules processor time to jobs using a min heap
 *              to determine the job with the shortest run-time.
************************************************************************/

#include "Scheduler.h"

//initialize tick_number to be 1 at the start of execution
unsigned int Scheduler::tick_number = 1;

Scheduler::Scheduler(int new_num_procs, const char* job_list)
{
    num_procs = new_num_procs;
    num_free_procs = new_num_procs;
    job_input_file.open(job_list);

    //push_back the processors onto vector
    for (int i = 0; i < new_num_procs; i++)
    {
        Processor new_proc;
        processor_bank.push_back(new_proc);
    }
}

Scheduler::~Scheduler()
{
    job_input_file.close();
}

void Scheduler::run()
{
    //checking the condition is also doing what the loop is supposed to repeat
    //keep calling tick while the return value is true
    while(tick())
        continue;
}

bool Scheduler::tick()
{
    //print info regarding scheduler state at current tick
    print_tick_info();

    //assume the tick will indicate the scheduler should continue
    bool tick_result = true;

    //grab a new job from file
    if (!job_input_file.eof())
    {
        Job new_job;
        job_input_file >> new_job;

        //if exit is job desc, stop the scheduler
        if (new_job.get_job_description() == "exit")    
            tick_result = false;
        else if (new_job.get_job_description() != "NULL")
            insert_job(new_job);
    }

    //stop scheduler when the queues are empty and end of file has been reached
    if (waiting_job_queue.empty() && running_job_queue.empty() && job_input_file.eof())
    {
        tick_result = false;
    }

    if (tick_result)
    {
        decrement_timer();
        //release_procs() is called inside this erase function
        erase_finished_jobs();

        //keep finding shortest job while wait queue isn't empty
        while (!waiting_job_queue.empty())
        {
            Job shortest_job = find_shortest();
            //add job to running queue if procs are available
            if (check_availability(shortest_job.get_n_procs()))
            {
                delete_shortest();
                run_job(shortest_job);
            }
            //if procs aren't available stop looking at shortest jobs
            else
                break;   
        }
    }
    tick_number++;

    //tick_result indicates if the scheduler should keep ticking
    return tick_result;
}

void Scheduler::insert_job(Job new_job)
{
    //make sure the job doesn't require more procs than the system has
    if (new_job.get_n_procs() > 0 && new_job.get_n_procs() <= num_procs)
    {
        //make sure the job doesn't require going backwards in time :)
        if (new_job.get_n_ticks() > 0)
        {
        std::cout << "\n****JOB ADDED TO WAITING QUEUE****\n" << new_job << "****************************\n" << std::endl;

            //std::cout << "\nJob ID: " << new_job.get_job_id() << " added to wait queue." << std::endl;
            //if valid job, push it onto the waiting heap
            waiting_job_queue.push(new_job);
        }
        else
            std::cout << "job_id: " << new_job.get_job_id() << " failed to be submitted due to invalid n_ticks value." << std::endl;
    }
    else
        std::cout << "job_id: " << new_job.get_job_id() << " failed to be submitted due to invalid n_procs value." << std::endl;
}


//peeks the top of the heap
Job Scheduler::find_shortest() { return waiting_job_queue.top(); }

//pops the top
void Scheduler::delete_shortest() { waiting_job_queue.pop(); }

bool Scheduler::check_availability(int num_needed_procs)
{
    return num_needed_procs <= num_free_procs;
}

void Scheduler::run_job(Job job)
{
    std::cout << "\n****JOB ADDED TO RUNNING QUEUE****\n" << job << "****************************\n" << std::endl;
    //subtract the procs needed from the number available
    num_free_procs -= job.get_n_procs();
    //push job into the running jobs vector
    running_job_queue.push_back(job);

    assign_procs(job);
}

void Scheduler::erase_finished_jobs()
{
    std::vector<Job>::iterator iter = running_job_queue.begin();
    while(iter != running_job_queue.end())
    {
        if (iter->get_ticks_left() == 0)
        {
            num_free_procs += iter->get_n_procs();
            release_procs(iter->get_job_id());
            std::cout << "\n*****procs being released for job******" << std::endl;
            std::cout << *iter << "********************************\n" << std::endl;
            iter = running_job_queue.erase(iter);
        }
        else
        {
            iter++;
        }
        
    }
}

void Scheduler::assign_procs(Job &job)
{
    std::vector<Processor>::iterator iter = processor_bank.begin();

    int n = 0;
    //loop while not enough procs have been assigned and there are still procs to iterate over
    while(n < job.get_n_procs() && iter != processor_bank.end())
    {
        //if the proc is free
        if (iter->get_is_free())
        {
            iter->assign_job(job.get_job_id());
            n++;
        }
        iter++;
    }
    //std::cout << "\nAssigned " << n << " procs to job: " << job.get_job_id() << std::endl;
}

void Scheduler::release_procs(int job_id)
{
    std::vector<Processor>::iterator iter = processor_bank.begin();
    //int n = 0;
    //release all procs that have the job_id that was passed in
    for (; iter != processor_bank.end(); iter++)
    {
        if (iter->get_job_id() == job_id)
        {
            iter->release();
            //n++;
        }
    }
    //std::cout << "\nn: " << n << " procs released for job_id: " << job_id << std::endl;
}

void Scheduler::decrement_timer()
{
    std::vector<Job>::iterator iter = running_job_queue.begin();

    //decrement the ticks_left of every job in the running queue
    for (; iter != running_job_queue.end(); iter++)
        iter->decrement_ticks_left();
}

void Scheduler::print_tick_info()
{
    std::cout << "Tick #: " << tick_number << std::endl;
    std::cout << "busy procs: " << num_procs - num_free_procs << std::endl;
    std::cout << "running: " << running_job_queue.size() << std::endl;
    std::cout << "waiting: " << waiting_job_queue.size() << std::endl << std::endl;
}
