#include "Contact.hpp"

Contact::Contact()
{
	this->name = "";
	this->lastname = "";
	this->nickname = "";
	this->number = "";
	this->secret = "";
}
Contact::Contact(std::string name,std::string lastname,std::string nickname,std::string number,std::string secret)
{
	this->name = name;
	this->lastname = lastname;
	this->nickname = nickname;
	this->number = number;
	this->secret = secret;
}
void Contact::print_index(void)
{
	std::cout << "First Name: " << this->name << std::endl;
	std::cout << "Last Name: " << this->lastname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->number << std::endl;
	std::cout << "Darkest Secret: " << this->secret << std::endl;
}


std::string truncate(std::string &str)
{
	std::string tmp;
	if(str.length() > 10)
	{
		tmp = str.substr(0,9);
		tmp.append(".");
		return(tmp);
	}
	return (str);
}

void Contact::print_table(int index)
{
	std::cout << "|" << std::setw(10) << (char)(index + '0');
    std::cout << "|" << std::setw(10) << truncate(this->name);
    std::cout << "|" << std::setw(10) << truncate(this->lastname);
    std::cout << "|" << std::setw(10) << truncate(this->nickname);
    std::cout << "|" << std::endl;
}

Contact& Contact::operator=(const Contact& other)
{
	if(this == &other)
		return (*this);
	this->name = other.name;
	this->lastname = other.lastname;
	this->nickname = other.nickname;
	this->number = other.number;
	this->secret = other.secret;
	return (*this);
}
