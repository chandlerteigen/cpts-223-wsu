#include <string>
#include <list>
#include <chrono>

class ListPerformanceTest
{

public:
ListPerformanceTest();
~ListPerformanceTest();

void runTest();

private:

void loadListFromFile(const std::string &fileName);

int findMax();

int findMin();

int findMed();

std::chrono::microseconds timeInsert, timeMax, timeMin, timeMed;


std::list<int> mList;

};
