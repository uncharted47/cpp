
#include "PmergeMe.hpp"
#include <cmath>

int PmergeMe::nbr_of_comps = 0;

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}
PmergeMe::~PmergeMe() {}


//  J(n) = (2^n - (-1)^n) / 3
long jacobsthal_number(long n) 
{ 
    return round((pow(2, n + 1) + pow(-1, n)) / 3); 
}

void PmergeMe::sort_vec(std::vector<int>& vec) 
{ 
    merge_insertion_sort(vec, 1); 
}

void PmergeMe::sort_deque(std::deque<int>& deque)
{
    merge_insertion_sort(deque, 1);
}
