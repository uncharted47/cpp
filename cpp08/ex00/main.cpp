#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> vector;
        vector.push_back(1);
        vector.push_back(2);
        vector.push_back(3);
        vector.push_back(4);
        vector.push_back(5);
        vector.push_back(6);

        std::cout << ::easyfind(vector, 5) << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}