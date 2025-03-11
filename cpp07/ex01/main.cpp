#include "Iter.hpp"



void print_int(int &element) {
  std::cout << element << " ";
}

void double_int(int &element) {
  element *= 2;
}

void print_float(float &element) {
  std::cout << element << "f ";
}

void print_string(std::string &element) {
  std::cout << element << " ";
}

void to_upper(std::string &element) {
  for (size_t i = 0; i < element.length(); i++)
    element[i] = std::toupper(element[i]);
}

int main(void)
{
  int int_array[5] = {1, 2, 3, 4, 5};
  std::cout << "Original array: ";
  ::iter(int_array, 5, print_int);
  std::cout << std::endl;

  ::iter(int_array, 5, double_int);
  std::cout << "After doubling: ";
  ::iter(int_array, 5, print_int);
  std::cout << std::endl;

  float float_array[4] = {1.1f, 2.2f, 3.3f, 4.4f};
  ::iter(float_array, 4, print_float);
  std::cout << std::endl;

  std::string str_array[3] = {"Hello", "World", "Test"};
  std::cout << "Original array: ";
  ::iter(str_array, 3, print_string);
  std::cout << std::endl;

  ::iter(str_array, 3, to_upper);
  std::cout << "After to_upper: ";
  ::iter(str_array, 3, print_string);
  std::cout << std::endl;

  int empty_array[0] = {};
  ::iter(empty_array, 0, print_int);
  std::cout << "Empty array test completed" << std::endl;


  ::iter<int>(NULL, 5, print_int);
  std::cout << "Null pointer test completed" << std::endl;


  ::iter(int_array, -1, print_int);
  std::cout << "Negative length test completed" << std::endl;

  return 0;
}