/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:34:41 by elyzouli          #+#    #+#             */
/*   Updated: 2024/10/21 18:34:42 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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