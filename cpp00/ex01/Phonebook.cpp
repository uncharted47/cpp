/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:35:56 by elyzouli          #+#    #+#             */
/*   Updated: 2024/10/23 21:33:33 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



void getline(std::string &string,std::string msg)
{
	if(std::cin.eof())
	{
		std::cout << std::endl;
		std::cout << "EOF detected" <<std::endl;
		std::cout << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(1);
	}
		std::getline(std::cin,string);
	while(string.length() <=0)
	{
		std::cout << "Field can't be empty" <<std::endl;
		std::cout << msg ;
		std::getline(std::cin,string);
	}
}
void Phonebook::ADD(void)
{
	std::string name;
	std::string lastname;
	std::string nickname;
	std::string number;
	std::string secret;
	std::cout << "Enter the first name: ";
	getline(name,"Enter the first name: ");
	std::cout << "Enter the last name: ";
	getline(lastname,"Enter the last name: ");
	std::cout << "Enter the nickname: ";
	getline(nickname,"Enter the nickname: ");
	std::cout << "Enter the phone number: ";
	getline(number,"Enter the phone number: ");
	while(!test_number(number))
	{
		std::cout << "Invalid phone number" << std::endl;
		std::cout << "Enter the phone number: ";
		getline(number,"Enter the phone number: ");
	}
	std::cout << "Enter the darkest secret: ";
	getline(secret,"Enter the darkest secret: ");
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
	while(1)
	{
		getline(index,"Enter the index of the contact you want to see: ");
		if(index.length() == 1 && index[0] >= '0' && index[0] < (this->index + '0'))
		{
			i = index[0] - '0';
			this->contacts[i].print_index();
			return ;
		}
		else
			std::cout << "Invalid index" << std::endl;
	}
}

void Phonebook::exit(void)
{
	std::cout << "Exiting..." << std::endl;
}
