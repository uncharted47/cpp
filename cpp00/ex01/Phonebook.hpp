#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <cstdlib>

class Phonebook
{
	private:
		Contact contacts[8];
		int oldest;
		int index;
	public:
		Phonebook();
		void ADD(void);
		void add_contact(Contact contact);
		void search_contact(void);
		void exit(void);
};

void getline(std::string &string,std::string msg);
int test_number(std::string str);

#endif