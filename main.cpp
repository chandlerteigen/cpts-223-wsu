/*
Programmer: Chandler Teigen
Date:       10-7-19
Description: tests the operation of the josephus problem classes for 
             PA3 in CPTS 223 Fall 2019
*/


//below is the command to compile project
//g++ main.cpp TestVectorMyJosephus.cpp VectorMyJosephus.cpp Person.cpp Timer.cpp TestListMyJosephus.cpp ListMyJosephus.cpp -o ex

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