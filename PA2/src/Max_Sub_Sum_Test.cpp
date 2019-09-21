#include "Max_Sub_Sum_Test.h"
#include <iostream>
#include <cmath>

void Max_Sub_Sum_Test::run_app()
{
    std::ofstream outfile("test_output.csv");
    test_algorithm(&Max_Sub_Sum_Test::max_sub_sum1, "max_sub_sum1", outfile);
    test_algorithm(&Max_Sub_Sum_Test::max_sub_sum2, "max_sub_sum2", outfile);
    test_algorithm(&Max_Sub_Sum_Test::max_sub_sum3, "max_sub_sum3", outfile);
    test_algorithm(&Max_Sub_Sum_Test::max_sub_sum4, "max_sub_sum4", outfile);
    outfile.close();
}

int Max_Sub_Sum_Test::max_sub_sum1(const std::vector<int> &vec)
{
    int max_sum = 0;

    for(int i = 0; i < vec.size(); i++) // iterate through possible starting points
        for(int j = i; j < vec.size(); j++) // iterator through possible ending points
        {
            int cur_sum = 0;

            for (int k = i; k <= j; k++) // add values between starting and ending point
                cur_sum += vec[k];
            
            if(cur_sum > max_sum) // set the current sum to the max if it is greater than the max
                max_sum = cur_sum;
        }
        return max_sum;
}

int Max_Sub_Sum_Test::max_sub_sum2(const std::vector<int> &vec)
{
    int max_sum = 0;

    for(int i = 0; i < vec.size(); i++) // iterate through the possibe starting points
    {
        int cur_sum = 0;
        for(int j = i; j < vec.size(); j++) //iterate through the possible ending points
        {
            cur_sum += vec[j]; // add the current value to the sum

            if(cur_sum > max_sum) // if the current sum is greater than the max sum, it is the new max sum
            {
                max_sum = cur_sum;
            }
        }
    }
    return max_sum;
}

int Max_Sub_Sum_Test::max_sub_sum3_rec(const std::vector<int> &vec, int left, int right)
{
    if (left == right) // base case
    {
        if(vec[left] > 0)
            return vec[left];
        else
            return 0;
    }


    int center = (left + right) / 2;
    int max_left_sum = max_sub_sum3_rec(vec, left, center);
    int max_right_sum = max_sub_sum3_rec(vec, center + 1, right);

    int max_left_border_sum = 0, left_border_sum = 0;
    for(int i = center; i >= left; i--)
    {
        left_border_sum += vec[i];
        if(left_border_sum > max_left_border_sum)
            max_left_border_sum = left_border_sum;
    }

    int max_right_border_sum = 0, right_border_sum = 0;
    for(int j = center + 1; j <= right; j++)
    {
        right_border_sum += vec[j];
        if(right_border_sum > max_right_border_sum)
            max_right_border_sum = right_border_sum;
    }

    return max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}

int Max_Sub_Sum_Test::max_sub_sum3(const std::vector<int> &vec)
{
    return max_sub_sum3_rec(vec, 0, vec.size() - 1);
}

int Max_Sub_Sum_Test::max3(int num1, int num2, int num3)
{
    int max = num1;
    if(num2 > max)
        max = num2;
    if(num3 > max)
        max = num3;

    return max;
}

int Max_Sub_Sum_Test::max_sub_sum4(const std::vector<int> &vec)
{
    int max_sum = 0, cur_sum = 0;

    for(int j = 0; j < vec.size(); j++)
    {
        cur_sum += vec[j];

        if(cur_sum > max_sum)
            max_sum = cur_sum;
        else if (cur_sum < 0)
            cur_sum = 0;
    }
    return max_sum;
}


std::vector<int>& Max_Sub_Sum_Test::load_vector_from_file(std::vector<int> &vec, std::ifstream& infile)
{
    
    int temp_int = 0;
    while(!(infile.eof()))
    {
        infile >> temp_int;
        vec.push_back(temp_int);
    }

    return vec;
}


std::vector<std::string>& Max_Sub_Sum_Test::generate_file_names(std::vector<std::string>& file_name_vec)
{
    std::string base_file_name = "../inputs/input_~_+.txt"; // basic format of filepath/name
    std::string file_name = base_file_name;
    std::string file_size_sub_string = "";
    std::string file_number_sub_string = "";

    int size_index = base_file_name.find('~'); // indexes of where to find the delimiters
    int number_index = base_file_name.find('+');

    for(int i = 8; i <= 8192; i = i * 2)
    {
        for(int j = 0; j <= 9; j++)
        {
            file_size_sub_string = std::to_string(i); // numbers to be inserted into string
            file_number_sub_string = std::to_string(j);

            //insert the file size into the file name
            file_name.replace(size_index, 1, file_size_sub_string, 0, file_size_sub_string.length());
            //file number index changes based on the size of the file size string
            number_index = file_name.find('+');
            file_name.replace(number_index, 1, file_number_sub_string, 0, file_number_sub_string.length());
            
            file_name_vec.push_back(file_name);

            //reset the file_name back to the base value
            file_name.assign(base_file_name);
        }
    }

    return file_name_vec;
}

void Max_Sub_Sum_Test::test_algorithm(int (Max_Sub_Sum_Test::*alg_ptr)(const std::vector<int>&), const char* alg_name, std::ofstream& outfile)
{
    std::vector<std::string> file_name_vec;
    generate_file_names(file_name_vec);
    std::ifstream infile;
    
    std::vector<int> number_vector;

    //long long total_time = 0;
    int sum = 0;

    for(int i = 0; i < file_name_vec.size(); i++)
    {
        infile.open(file_name_vec[i]);
        //std::cout << file_name_vec[i] << ": ";
        number_vector = load_vector_from_file(number_vector, infile);

        
        timer.start();
        sum = (this->*alg_ptr)(number_vector); // use function pointer to call sub sum algorithm
        timer.stop();
        //timer.printTime();

        number_vector.clear();
        
        infile.close();
        std::cout << alg_name << ',' << 8*pow(2, i / 10) << ',' << sum << ',' << timer.getLength().count() << '\n';
        outfile << alg_name << ',' << 8*pow(2, i / 10) << ',' << sum << ',' << timer.getLength().count() << '\n';
    }
}
