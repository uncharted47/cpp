/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:42:08 by elyzouli          #+#    #+#             */
/*   Updated: 2025/01/13 15:42:09 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int cmd , char **str)
{
	if(cmd == 1)
		return(std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl,0);
	for(int i = 1; str[i] ;i++)
		for(int j = 0;str[i][j];j++)
			std::cout << (char)(std::toupper(str[i][j]));
	std::cout << std::endl;
}