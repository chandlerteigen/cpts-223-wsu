/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 11-14-19
 * Description: This project was created to fulfill the assignment PA5
 * 				for CPTS 223 at WSU fall 2019. It consists of a scheduler
 *              which schedules processor time to jobs using a min heap
 *              to determine the job with the shortest run-time.
************************************************************************/

#ifndef JOB_H
#define JOB_H

#include <string>
#include <fstream>
#include <iostream>

class Job
{
public:

    Job();
    ~Job();

    static int next_job_id;

    //accessors
    const std::string &get_job_description() const;
    int get_n_ticks() const;
    int get_n_procs() const;
    int get_job_id() const;
    int get_ticks_left() const;

    //mutators
    void set_job_description(std::string &new_job_description);
    void set_n_ticks(int new_n_ticks);
    void set_n_procs(int new_n_procs);
    void set_ticks_left(int new_ticks_left);
    void decrement_ticks_left();

private:

    int job_id;
    std::string job_description;
    int n_procs;    //number of procs required for job
    int n_ticks;    //number of ticks to finished the job
    int ticks_left; //ticks left until job is finished
};

/**************************************************************************************
* Function: Job::operator>>
* Arguments: std::ifstream&, Job&
* Returns: std::istream&
* Description: overloaded stream extraction operator for Job. this fills the fields of
               Job and also prompts the user for the job description because that wasn't
               included in the file. allows chaining
***************************************************************************************/
std::istream &operator>> (std::ifstream &lhs, Job &rhs);

/**************************************************************************************
* Function: Job::operator<<
* Arguments: std::ostream&, const Job&
* Returns: std::ostream&
* Description: overloaded stream insertion operator for Job. prints the relevant fields
               of the job. allows chaining. 
***************************************************************************************/
std::ostream &operator<< (std::ostream &lhs, const Job &rhs);


//helper class for the Job min heap
struct Job_N_Ticks_Greater
{
/**************************************************************************************
* Function: Job_N_Ticks_Greater::operator()
* Arguments: const Job&, const Job&
* Returns: bool
* Description: functor for the Job class. compares the n_ticks member using the > operator.
               created to implement a priority_queue<Job> as a min heap. 
***************************************************************************************/
    bool operator()(const Job &lhs, const Job& rhs ) const
    {
        return lhs.get_n_ticks() > rhs.get_n_ticks();
    }
};


#endif

