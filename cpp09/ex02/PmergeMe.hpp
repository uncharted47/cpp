
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>

// Ford-Johnson merge-insertion sort implementation
class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sort_vec(std::vector<int>& vec);
    void sort_deque(std::deque<int>& deque);

    static int nbr_of_comps;

private:
    template <typename Container>
    void merge_insertion_sort(Container& container, int group_size);

    template <typename Iterator>
    void swap_groups(Iterator pos, int group_size);

    template <typename Iterator>
    Iterator advance_iterator(Iterator it, int steps);
};

// Helper function to calculate Jacobsthal numbers
long jacobsthal_number(long n);

// Comparison function template
template <typename Iterator> 
bool compare_iterators(Iterator left, Iterator right) 
{
    PmergeMe::nbr_of_comps++;
    return *left < *right;
}

// Template implementations

template <typename Iterator>
Iterator PmergeMe::advance_iterator(Iterator it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename Iterator>
void PmergeMe::swap_groups(Iterator pos, int group_size)
{
    Iterator start = advance_iterator(pos, -group_size + 1);
    Iterator end = advance_iterator(start, group_size);
    
    while (start != end)
    {
        std::iter_swap(start, advance_iterator(start, group_size));
        ++start;
    }
}

template <typename Container>
void PmergeMe::merge_insertion_sort(Container& container, int group_size)
{
    typedef typename Container::iterator Iterator;

    int num_groups = container.size() / group_size;
    if (num_groups < 2)
        return;

    bool has_odd_group = (num_groups % 2 == 1);
    
    Iterator start = container.begin();
    Iterator last_even_pos = advance_iterator(container.begin(), group_size * num_groups);
    Iterator end_for_swapping = advance_iterator(last_even_pos, -(has_odd_group ? group_size : 0));
    
    int jump = 2 * group_size;
    for (Iterator it = start; it != end_for_swapping; std::advance(it, jump))
    {
        Iterator first_group_end = advance_iterator(it, group_size - 1);
        Iterator second_group_end = advance_iterator(it, group_size * 2 - 1);
        
        if (compare_iterators(second_group_end, first_group_end))
        {
            swap_groups(first_group_end, group_size);
        }
    }
    
    merge_insertion_sort(container, group_size * 2);

    std::vector<Iterator> main_chain;
    std::vector<Iterator> pending_chain;
    
    main_chain.push_back(advance_iterator(container.begin(), group_size - 1));
    main_chain.push_back(advance_iterator(container.begin(), group_size * 2 - 1));

    for (int i = 4; i <= num_groups; i += 2)
    {
        pending_chain.push_back(advance_iterator(container.begin(), group_size * (i - 1) - 1));
        main_chain.push_back(advance_iterator(container.begin(), group_size * i - 1));
    }
    
    if (has_odd_group)
    {
        pending_chain.push_back(advance_iterator(end_for_swapping, group_size - 1));
    }

    int prev_jacobsthal = jacobsthal_number(1);
    int inserted_count = 0;
    
    for (int k = 2; ; k++)
    {
        int curr_jacobsthal = jacobsthal_number(k);
        int batch_size = curr_jacobsthal - prev_jacobsthal;
        int offset = 0;
        
        if (batch_size > static_cast<int>(pending_chain.size()))
            break;
            
        int remaining_in_batch = batch_size;
        typename std::vector<Iterator>::iterator pend_it = advance_iterator(pending_chain.begin(), batch_size - 1);
        typename std::vector<Iterator>::iterator search_bound = advance_iterator(main_chain.begin(), curr_jacobsthal + inserted_count);
        
        while (remaining_in_batch > 0)
        {
            typename std::vector<Iterator>::iterator insert_pos = 
                std::upper_bound(main_chain.begin(), search_bound, *pend_it, compare_iterators<Iterator>);
            
            typename std::vector<Iterator>::iterator inserted_at = main_chain.insert(insert_pos, *pend_it);
            remaining_in_batch--;
            pend_it = pending_chain.erase(pend_it);
            std::advance(pend_it, -1);
            
            offset += (inserted_at - main_chain.begin()) == curr_jacobsthal + inserted_count;
            search_bound = advance_iterator(main_chain.begin(), curr_jacobsthal + inserted_count - offset);
        }
        
        prev_jacobsthal = curr_jacobsthal;
        inserted_count += batch_size;
    }

    for (int i = pending_chain.size() - 1; i >= 0; i--)
    {
        typename std::vector<Iterator>::iterator curr_element = advance_iterator(pending_chain.begin(), i);
        typename std::vector<Iterator>::iterator search_bound = 
            advance_iterator(main_chain.begin(), main_chain.size() - pending_chain.size() + i + has_odd_group);
        
        typename std::vector<Iterator>::iterator insert_pos = 
            std::upper_bound(main_chain.begin(), search_bound, *curr_element, compare_iterators<Iterator>);
        
        main_chain.insert(insert_pos, *curr_element);
    }

    std::vector<int> sorted_values;
    sorted_values.reserve(container.size());
    
    for (typename std::vector<Iterator>::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
    {
        for (int i = 0; i < group_size; i++)
        {
            Iterator element = *it;
            std::advance(element, -group_size + i + 1);
            sorted_values.push_back(*element);
        }
    }

    Iterator container_it = container.begin();
    for (std::vector<int>::iterator sorted_it = sorted_values.begin(); 
         sorted_it != sorted_values.end(); ++sorted_it, ++container_it)
    {
        *container_it = *sorted_it;
    }
}


template <typename Container>
bool is_sorted(const Container& container)
{
    if (container.size() <= 1)
        return true;
    
    typename Container::const_iterator current = container.begin();
    typename Container::const_iterator next = current;
    ++next;
    
    while (next != container.end())
    {
        if (*current > *next)
            return false;
        ++current;
        ++next;
    }
    return true;
}

#endif
