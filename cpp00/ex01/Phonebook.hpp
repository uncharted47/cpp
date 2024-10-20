#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"


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


#endif