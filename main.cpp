/*
Programmer: Chandler Teigen
Date:       10-7-19
Description: tests the operation of the josephus problem classes for 
             PA3 in CPTS 223 Fall 2019
*/

//g++ main.cpp TestVectorMyJosephus.cpp VectorMyJosephus.cpp Person.cpp Timer.cpp -o ex
//g++ main.cpp TestListMyJosephus.cpp ListMyJosephus.cpp Person.cpp -o ex
#include "TestListMyJosephus.h"
#include "TestVectorMyJosephus.h"

int main(void)
{
    TestVectorMyJosephus testVector;

    testVector.testGame();

    TestListMyJosephus testList;

    testList.testGame();


    return 0;
}