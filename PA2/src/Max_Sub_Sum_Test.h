#include "Timer.h"
#include <vector>
#include <fstream>

class Max_Sub_Sum_Test
{
public:

void run_app();

private:

Timer timer;

int max_sub_sum1(const std::vector<int> &vec);
int max_sub_sum2(const std::vector<int> &vec);
int max_sub_sum3_rec(const std::vector<int> &vec, int left, int right);
int max_sub_sum3(const std::vector<int> &vec);
int max_sub_sum4(const std::vector<int> &vec);
int max3(int num1, int num2, int num3);
std::vector<int> &load_vector_from_file(std::vector<int> &vec, std::ifstream& infile);
std::vector<std::string>& generate_file_names(std::vector<std::string>& vec);

void test_algorithm(int (Max_Sub_Sum_Test::*alg_ptr)(const std::vector<int>&), const char* alg_name, std::ofstream& outfile);

};


