/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:56:39 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 16:37:55 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	std::cout << "\n--- ShrubberyCreationForm ---\n";
	ShrubberyCreationForm shrubbery("home");
	Bureaucrat gardener(130, "Gardener");
	gardener.signForm(shrubbery);
	gardener.executeForm(shrubbery);

	Bureaucrat weakGardener(138, "WeakGardener");
	weakGardener.signForm(shrubbery);
	weakGardener.executeForm(shrubbery);

	std::cout << "\n--- RobotomyRequestForm ---\n";
	RobotomyRequestForm robotomy("Bob");
	Bureaucrat surgeon(45, "Surgeon");
	surgeon.signForm(robotomy);
	surgeon.executeForm(robotomy);
	surgeon.executeForm(robotomy);
	surgeon.executeForm(robotomy);

	std::cout << "\n--- PresidentialPardonForm ---\n";
	PresidentialPardonForm pardon("Alice");
	Bureaucrat president(5, "President");
	president.signForm(pardon);
	president.executeForm(pardon);

	std::cout << "\n--- Execution sans signature ---\n";
	PresidentialPardonForm unsigned_form;
	president.executeForm(unsigned_form);

	std::cout << "\n--- Exceptions construction ---\n";
	try
	{
		ShrubberyCreationForm invalid("invalid");
		Bureaucrat tooweak(150, "TooWeak");
		tooweak.signForm(invalid);
		tooweak.executeForm(invalid);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}