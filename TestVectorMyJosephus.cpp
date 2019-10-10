#include "TestVectorMyJosephus.h"


TestVectorMyJosephus::TestVectorMyJosephus()
{
    averageElimTime = 0;
    totalTime = 0;
}

TestVectorMyJosephus::~TestVectorMyJosephus()
{

}

void TestVectorMyJosephus::testGame()
{
    std::ofstream outfile;
    outfile.open("vector_output.csv");
    outfile << "N,M,total,average\n";

    for(int N = 4; N <= 1024; N *= 2) // loop through different values of N
    {
    
        totalTimer.start(); // start timer
        josephusGame.init(N, 3);
        while(josephusGame.currentSize() > 1)
        {
            elimTimer.start();
            //josephusGame.printAll();
            josephusGame.eliminateNext();
            elimTimer.stop();
            averageElimTime += elimTimer.getLength().count();
        }
        averageElimTime = averageElimTime / (N - 1);
        //josephusGame.printElimSequence(); // these lines are commented out for testing
        //std::cout << "winner: " << josephusGame.getWinner() << "\n" << std::endl;
        josephusGame.clear();
        totalTimer.stop();
        totalTime = totalTimer.getLength().count();
        //print to output file
        outfile << N << "," << 3 << "," << totalTime << "," << averageElimTime << "\n";

    }

    //reset total and elim time variables
    totalTime = 0;
    averageElimTime = 0;

    //varying M

    for(int M = 2; M < 1024; M *= 2) // iteration through M values
    {   
        totalTimer.start();
        josephusGame.init(1024, M);
        while(josephusGame.currentSize() > 1)
        {
            elimTimer.start();
            //josephusGame.printAll();
            josephusGame.eliminateNext();
            elimTimer.stop();
            averageElimTime += elimTimer.getLength().count(); //sum elim times
        }

        averageElimTime = averageElimTime / 1023; // average elim times (1023 elims ofr 1024 person game)
        //josephusGame.printElimSequence();
        //std::cout << "winner: " << josephusGame.getWinner() << "\n" << std::endl;
        josephusGame.clear();
        totalTimer.stop();
        totalTime = totalTimer.getLength().count();
        outfile << 1024 << "," << M << "," << totalTime << "," << averageElimTime << "\n";
    }

    outfile.close();
}