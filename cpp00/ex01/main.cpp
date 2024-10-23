/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:30:59 by elyzouli          #+#    #+#             */
/*   Updated: 2024/10/23 21:27:02 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

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
		std::cout << "Enter one of the following commands ADD SEARCH EXIT :" ;
		std::getline(std::cin, command);
		std::cout << std::endl;
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
