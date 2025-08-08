
#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <set>
#include <ctime>

bool is_valid_number(const std::string& arg)
{
    if (arg.empty() || arg[0] == '-')
        return false;
    
    char* end;
    errno = 0;
    long number = strtol(arg.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || number > INT_MAX)
        return false;
    
    if (number == 0 && arg != "0")
        return false;
    
    return true;
}

std::string validate_arguments(int argc, char** argv)
{
    if (argc < 2)
        return "No arguments provided";
    
    for (int i = 1; i < argc; i++)
    {
        if (!is_valid_number(argv[i]))
        {
            return "Invalid argument: " + std::string(argv[i]) + 
                   " (only positive integers allowed)";
        }
    }
    return "";
}

std::vector<int> create_vector(int argc, char** argv)
{
    std::vector<int> container;
    container.reserve(argc - 1);
    
    for (int i = 1; i < argc; i++)
    {
        container.push_back(atoi(argv[i]));
    }
    return container;
}

std::deque<int> create_deque(int argc, char** argv)
{
    std::deque<int> container;
    
    for (int i = 1; i < argc; i++)
    {
        container.push_back(atoi(argv[i]));
    }
    return container;
}



bool has_duplicate_values(int argc, char** argv)
{
    std::set<int> unique_values;
    
    for (int i = 1; i < argc; i++)
    {
        int value = atoi(argv[i]);
        if (unique_values.find(value) != unique_values.end())
            return true;
        unique_values.insert(value);
    }
    return false;
}

bool contains_original_values(int argc, char** argv, const std::vector<int>& sorted_vec)
{
    std::set<int> original_values;
    std::set<int> sorted_values;
    
    for (int i = 1; i < argc; i++)
    {
        original_values.insert(atoi(argv[i]));
    }
    
    for (size_t i = 0; i < sorted_vec.size(); i++)
    {
        sorted_values.insert(sorted_vec[i]);
    }
    
    return original_values == sorted_values;
}

std::string format_input(int argc, char** argv)
{
    if (argc < 2)
        return "[]";
    
    std::string result = "[";
    result += argv[1];
    
    for (int i = 2; i < argc; i++)
    {
        result += " ";
        result += argv[i];
    }
    result += "]";
    return result;
}

std::string format_container(const std::vector<int>& container)
{
    if (container.empty())
        return "[]";
    
    std::stringstream ss;
    ss << "[" << container[0];
    
    for (size_t i = 1; i < container.size(); i++)
    {
        ss << " " << container[i];
    }
    ss << "]";
    return ss.str();
}

void display_results(int argc, char** argv, const std::vector<int>& sorted_vec,
                    double vec_time, double deque_time, int comparisons)
{
    std::cout << "Before: " << format_input(argc, argv) << std::endl;
    std::cout << "After:  " << format_container(sorted_vec) << std::endl;

    
    std::cout << "Time to process a range of " << sorted_vec.size()
              << " elements with std::vector: " << std::fixed << std::setprecision(5)
              << vec_time << " us" << std::endl;

    std::cout << "Time to process a range of " << sorted_vec.size()
              << " elements with std::deque:  " << std::fixed << std::setprecision(5)
              << deque_time << " us" << std::endl;
              
        (void)comparisons; 
    // std::cout << "Number of comparisons: " << comparisons << std::endl;
}

double calculate_time_elapsed(clock_t start, clock_t end)
{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC ; // Convert to microseconds
}

int main(int argc, char** argv)
{
    std::string validation_error = validate_arguments(argc, argv);
    if (!validation_error.empty())
    {
        std::cerr << "Error: " << validation_error << std::endl;
        return EXIT_FAILURE;
    }
    
    if (has_duplicate_values(argc, argv))
    {
        std::cerr << "Error: Duplicate values are not allowed" << std::endl;
        return EXIT_FAILURE;
    }
    
    PmergeMe sorter;
    
    std::vector<int> initial_vec = create_vector(argc, argv);
    if (is_sorted(initial_vec))
    {
        std::cout << "Input is already sorted." << std::endl;
        return EXIT_SUCCESS;
    }

    std::vector<int> vec = create_vector(argc, argv);
    clock_t vec_start = clock();
    sorter.sort_vec(vec);
    clock_t vec_end = clock();
    double vec_time = calculate_time_elapsed(vec_start, vec_end);
    
    PmergeMe::nbr_of_comps = 0;
    
    std::deque<int> deque = create_deque(argc, argv);
    clock_t deque_start = clock();
    sorter.sort_deque(deque);
    clock_t deque_end = clock();
    double deque_time = calculate_time_elapsed(deque_start, deque_end);
    
    // Display results
    display_results(argc, argv, vec, vec_time, deque_time, PmergeMe::nbr_of_comps);

    return EXIT_SUCCESS;
}
