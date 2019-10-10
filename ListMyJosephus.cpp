#include "ListMyJosephus.h"


ListMyJosephus::ListMyJosephus()
{

}

ListMyJosephus::ListMyJosephus(int newN, int newM)
{
    init(newN, newM);
}

ListMyJosephus::~ListMyJosephus()
{

}

void ListMyJosephus::init(int newN, int newM)
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

void ListMyJosephus::clear()
{
    circ.clear();
}

int ListMyJosephus::currentSize()
{
    return circ.size();
}

bool ListMyJosephus::isEmpty()
{
    return circ.empty();
}

int ListMyJosephus::getWinner()
{
    int winner = 0;
    if(currentSize() == 1)
    {
        winner = circ.front().getPosition();
    }
    else
    {
        winner = -1;
    }
    
    return winner;
}

void ListMyJosephus::eliminateNext()
{   
    std::list<Person>::iterator iter = circ.begin();

    if(currentPotatoHolder + M < currentSize())
    {
        iter = std::next(iter, currentPotatoHolder + M);
        elimSequence.push_back(iter->getPosition());
        circ.erase(iter); //erases the Mth person after the current holder
        currentPotatoHolder += M;
    }
    else
    {
        int overlap = (currentPotatoHolder + M) % currentSize();

        iter = std::next(iter, overlap);
        elimSequence.push_back(iter->getPosition());
        circ.erase(iter);
        currentPotatoHolder = overlap;
    }
}

void ListMyJosephus::printAll()
{
    std::list<Person>::iterator iter = circ.begin();
    while(iter != circ.end())
    {
        std::cout << iter->getPosition() << std::endl;
        iter = std::next(iter,1);
    }
}

void ListMyJosephus::printElimSequence() const
{
    std::list<int>::const_iterator iter = elimSequence.begin();
    while(iter != elimSequence.end())
    {
        std::cout << *iter << " ";
        iter++;
    }
}

void ListMyJosephus::playGame()
{
    
}