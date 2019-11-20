/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 11-14-19
 * Description: This project was created to fulfill the assignment PA5
 * 				for CPTS 223 at WSU fall 2019. It consists of a scheduler
 *              which schedules processor time to jobs using a min heap
 *              to determine the job with the shortest run-time.
************************************************************************/
#include "Job.h"

//set the next job id to be 0 initially
int Job::next_job_id = 0;


Job::Job()
{
    //set the job_id to the next value, increment next value
    job_id = next_job_id;
    next_job_id++;
}

Job::~Job() {}

//accessors
const std::string &Job::get_job_description() const { return job_description; }
int Job::get_n_ticks() const { return n_ticks; }
int Job::get_n_procs() const { return n_procs; }
int Job::get_job_id() const { return job_id; }
int Job::get_ticks_left() const { return ticks_left; }

//mutators
void Job::set_job_description(std::string &new_job_description)
{
    job_description.assign(new_job_description);
}

void Job::set_n_ticks(int new_n_ticks)
{
    n_ticks = new_n_ticks;
}
void Job::set_n_procs(int new_n_procs)
{
    n_procs = new_n_procs;
}

void Job::set_ticks_left(int new_ticks_left)
{
    ticks_left = new_ticks_left;
}

void Job::decrement_ticks_left()
{
    ticks_left--;
}

std::istream &operator>> (std::ifstream &lhs, Job &rhs)
{
    //get the next line from the file stream
    std::string temp_str;
    getline(lhs, temp_str, ' ');

    //get job desc from the user
    std::cout << "Enter Job Description: ";
    std::cin >> temp_str;
    rhs.set_job_description(temp_str);

    // if desc is not NULL get the rest of the information for the job from stream
    if (rhs.get_job_description() != "NULL")
    {
        int temp_int = 0;
        lhs >> temp_int;
        rhs.set_n_procs(temp_int);
        lhs >> temp_int;
        rhs.set_n_ticks(temp_int);
        rhs.set_ticks_left(temp_int);
        getline(lhs, temp_str, '\n');
    }
    
    return lhs;
}

std::ostream &operator<< (std::ostream &lhs, const Job &rhs)
{
    lhs << "ID: " << rhs.get_job_id() << "  Desc.: " << rhs.get_job_description();
    lhs << "  n_procs: " << rhs.get_n_procs() << "  n_ticks: " << rhs.get_n_ticks() << std::endl;
    return lhs;
}



