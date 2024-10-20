#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private :
		std::string name;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string secret;
	public:

	Contact();
	Contact(std::string name,std::string lastname,std::string nickname,std::string number,std::string secret);
	void print_index(void);
	void print_table(int index);
	Contact& operator=(const Contact& other);
};



#endif