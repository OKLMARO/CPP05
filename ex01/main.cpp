/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:56:39 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/22 16:30:11 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Form contract("Contract", 50, 25);
	std::cout << contract << std::endl;

	Bureaucrat alice(40, "Alice");
	std::cout << alice << std::endl;
	alice.signForm(contract);
	std::cout << contract << std::endl;

	Bureaucrat bob(80, "Bob");
	std::cout << bob << std::endl;
	bob.signForm(contract);

	try
	{
		Form invalid("Invalid", 0, 25);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form invalid("Invalid", 151, 25);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}