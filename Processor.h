/***********************************************************************
 * Programmer: Chandler Teigen
 * Date: 11-14-19
 * Description: This project was created to fulfill the assignment PA5
 * 				for CPTS 223 at WSU fall 2019. It consists of a scheduler
 *              which schedules processor time to jobs using a min heap
 *              to determine the job with the shortest run-time.
************************************************************************/

#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor
{
public:
    Processor();
    ~Processor();

    //accessors
    bool get_is_free() const;

    int get_job_id() const;

/**************************************************************************************
* Function: Processor::release
* Arguments: void
* Returns: void
* Description: set is_free to true, and job_id to -1.
***************************************************************************************/
    void release();

/**************************************************************************************
* Function: Processor::assign_job
* Arguments: int job_id
* Returns: void
* Description: sets is_free to false, and job_id to new_job_id
***************************************************************************************/
    void assign_job(int new_job_id);

private:
    bool is_free;
    int job_id;
};




#endif