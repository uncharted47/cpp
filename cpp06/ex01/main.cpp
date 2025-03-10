#include "Serializer.hpp"
#include <iostream>

int main()
{

    Data* originalData = new Data;
    originalData->name = "Test Data";
    originalData->value = 42;


    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << originalData << std::endl;
    std::cout << "Name: " << originalData->name << std::endl;
    std::cout << "Value: " << originalData->value << std::endl;

    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "\nSerialized value: " << serialized << std::endl;


    Data* deserialized = Serializer::deserialize(serialized);


    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;


    std::cout << "\nPointer comparison: " << (originalData == deserialized ? "SUCCESS" : "FAILURE") << std::endl;


    delete originalData;

    return 0;
}