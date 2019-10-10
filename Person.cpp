#include "Person.h"

Person::Person(int newPosition)
{
    this->position = newPosition;
}

Person::~Person()
{
    
}

int Person::getPosition() const { return position; }