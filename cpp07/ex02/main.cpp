#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    try
    {
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i * 2;

        std::cout << "Integer Array: ";
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "!";

        std::cout << "String Array: ";
        for (unsigned int i = 0; i < strArray.size(); i++)
            std::cout << strArray[i] << " ";
        std::cout << std::endl;

        // Test const operator[]
        const Array<int>& constIntArray = intArray;
        std::cout << "Accessing via const operator[]: ";
        for (unsigned int i = 0; i < constIntArray.size(); i++)
            std::cout << constIntArray[i] << " ";
        std::cout << std::endl;

        try
        {
            std::cout << intArray[2] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}