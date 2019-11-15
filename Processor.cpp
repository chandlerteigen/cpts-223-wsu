/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 11-14-19
 * Description: This project was created to fulfill the assignment PA5
 * 				for CPTS 223 at WSU fall 2019. It consists of a scheduler
 *              which schedules processor time to jobs using a min heap
 *              to determine the job with the shortest run-time.
************************************************************************/

#include "Processor.h"

Processor::Processor()
{
    //initially free, and given invalid job value to ensure not collisions with real jobs
    is_free = true;
    job_id = -1;
}

Processor::~Processor(){}

//accessors
bool Processor::get_is_free() const { return is_free; }

int Processor::get_job_id() const{ return job_id; }


void Processor::release()
{
    //release the proc from the job back to initial condition
    is_free = true;
    job_id = -1;
}

void Processor::assign_job(int new_job_id)
{
    //no longer free and has valid job id
    is_free = false;
    job_id = new_job_id;
}