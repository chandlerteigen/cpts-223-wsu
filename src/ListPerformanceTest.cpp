#include "ListPerformanceTest.h"
#include <fstream>
#include "Timer.h"
#include <iostream>


ListPerformanceTest::ListPerformanceTest(){}
ListPerformanceTest::~ListPerformanceTest(){}

void ListPerformanceTest::runTest()
{
    loadListFromFile("../Resources/input1.txt");
    int max = 0, min = 0, med = 0;

    max = findMax();
    min = findMin();
    med = findMed();
    
    std::cout << "max: " << max << "\nmin: " << min << "\nmed: " << med << std::endl;
}

void ListPerformanceTest::loadListFromFile(const std::string &fileName)
{
    std::ifstream infile;
    infile.open(fileName);

    if (infile.is_open())
    {
        int tempInt = 0;
        Timer timer;
        timer.start();

        while(!infile.eof())
        {
            infile >> tempInt;
            mList.insert(std::lower_bound(mList.begin(), mList.end(), tempInt), tempInt);
        }

        timer.stop();
        timeInsert = timer.getLength();
        std::cout << "time_insert: " << timeInsert.count() << std::endl;
    }
}

int ListPerformanceTest::findMax()
{
    
    Timer timer;
    timer.start();

    std::list<int>::iterator iter;

    iter = mList.begin();

    for(int i = 0; i < mList.size() - 1; i++)
    {
        iter++;
    }

    timer.stop();
    timeMax = timer.getLength();
    std::cout << "time_max: " << timeMax.count() << std::endl;

    return *iter;
}

int ListPerformanceTest::findMin()
{
    Timer timer;
    timer.start();

    std::list<int>::iterator iter;

    iter = mList.begin();

    timer.stop();

    timeMin = timer.getLength();    
    std::cout << "time_min: " << timeMin.count() << std::endl;

    return *iter;
}

int ListPerformanceTest::findMed()
{
    int size = mList.size(), median = 0;
    std::list<int>::iterator iter = mList.begin();

    if(size % 2 == 0)
    {
        for(int i = 1; i <= size / 2; i++)
        {
            iter++;
        }
        median = (*iter + *(iter++)) / 2;
    }

    else
    {
        for(int i = 1; i <= size / 2; i++)
        {
            iter++;
        }
        median = *iter;
    }
    
    return median;
}
