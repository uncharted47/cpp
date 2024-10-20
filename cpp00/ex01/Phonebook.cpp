#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->oldest = 0;
	this->index = 0;
}
int test_number(std::string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(std::isdigit(str[i]) == 0)
			return (0);
	}
	return (str.length() > 0 && str.length() < 12 && str.length() > 8);
}
void Phonebook::ADD(void)
{
	std::string name;
	std::string lastname;
	std::string nickname;
	std::string number;
	std::string secret;
	std::cout << "Enter the first name: ";
	std::getline(std::cin, name);
	std::cout << "Enter the last name: ";
	std::getline(std::cin, lastname);
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter the phone number: ";
	std::getline(std::cin, number);
	while(!test_number(number))
	{
		std::cout << "Invalid phone number" << std::endl;
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, number);
	}
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, secret);
	this->add_contact(Contact(name, lastname, nickname, number, secret));
	std::cout << "Contact added" << std::endl;
}




void Phonebook::add_contact(Contact contact)
{
	if(this->index < 8)
	{
		this->contacts[this->index] = contact;
		this->index++;
	}
	else
	{
		this->contacts[this->oldest] = contact;
		this->oldest++;
		if(this->oldest == 8)
			this->oldest = 0;
	}
}

void Phonebook::search_contact(void)
{
	int i;
	std::string index;
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	i = 0;
	while(i < this->index)
	{
		this->contacts[i].print_table(i);
		i++;
	}
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, index);
	if(index.length() == 1 && index[0] >= '0' && index[0] < (this->index + '0'))
	{
		i = index[0] - '0';
		this->contacts[i].print_index();
	}
	else
		std::cout << "Invalid index" << std::endl;
}

void Phonebook::exit(void)
{
	std::cout << "Exiting..." << std::endl;
}

int main(void)
{
	std::string command;
	Phonebook phonebook;
	while(1)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "EOF detected" <<std::endl;
			std::cout << std::endl;
			phonebook.exit();
			return(1);
		}
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if(command == "ADD")
			phonebook.ADD();
		else if(command == "SEARCH")
			phonebook.search_contact();
		else if(command == "EXIT")
		{
			phonebook.exit();
			break;
		}
		else if(!std::cin.eof())
			std::cout << "Invalid command Enter a new command" <<std::endl << std::endl;
	}
	return (0);
}