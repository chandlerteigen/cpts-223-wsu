#include "VectorMyJosephus.h"

VectorMyJosephus::VectorMyJosephus()
{

}

VectorMyJosephus::~VectorMyJosephus()
{

}

VectorMyJosephus::VectorMyJosephus(int newN, int newM)
{
    this->init(newN, newM);
}

void VectorMyJosephus::init(int newN, int newM)
{
    size = newN;
    N = newN;
    M = newM;
    currentPotatoHolder = 0;

    for(int i = 0; i < N; i++)
    {
        Person temp(i);
        circ.push_back(temp);
    }
}

void VectorMyJosephus::clear()
{
    circ.clear();
}

int VectorMyJosephus::currentSize() const
{
    return circ.size();
}

bool VectorMyJosephus::isEmpty() const
{
    return circ.empty();
}

void VectorMyJosephus::printAll() const
{
    std::vector<Person>::const_iterator iter = circ.begin(); // create const_iterator

    while(iter != circ.end())
    {
        std::cout << iter->getPosition() << std::endl; //print each position
        iter++;
    }
    std::cout << std::endl;
}

void VectorMyJosephus::printElimSequence() const
{
    std::vector<int>::const_iterator iter = elimSequence.begin();
    while(iter != elimSequence.end())
    {
        std::cout << *iter << " ";
        iter++;
    }   
}

int VectorMyJosephus::getWinner() const
{
    //returns the winner, if someone has won
    int winner = 0;
    if (currentSize() == 1)
    {
        winner = circ.begin()->getPosition();
    }
    else
    {
        winner = -1;
    }

    return winner;
}

void VectorMyJosephus::eliminateNext()
{   //if next potato position is in the bounds of the vector
    if(currentPotatoHolder + M < currentSize())
    {
        // incrememnt the potato position
        auto iter = circ.begin() + currentPotatoHolder + M;
        elimSequence.push_back(iter->getPosition()); // add to elim sequence
        circ.erase(iter); //erases the Mth person after the current holder
        currentPotatoHolder += M;
    }
    else // the potato needs to wrao back to the beginning of the vector
    {
        //overlap represents the amount that the potato wraps around back into the circle
        int overlap = (currentPotatoHolder + M) % currentSize();
        circ.erase(circ.begin() + overlap);
        currentPotatoHolder = overlap;
    }
}
