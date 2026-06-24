/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:56:39 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 16:06:29 by oamairi          ###   ########.fr       */
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

	AForm *contract = new ShrubberyCreationForm("Contract");
	std::cout << *contract << std::endl;

	Bureaucrat alice(40, "Alice");
	std::cout << alice << std::endl;
	alice.signForm(*contract);
	std::cout << *contract << std::endl;

	Bureaucrat bob(80, "Bob");
	std::cout << bob << std::endl;
	bob.signForm(*contract);

	std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
	ShrubberyCreationForm shrubbery("home");
	Bureaucrat gardener(130, "Gardener");
	gardener.signForm(shrubbery);
	gardener.executeForm(shrubbery);

	Bureaucrat weakGardener(138, "WeakGardener");
	weakGardener.signForm(shrubbery);
	weakGardener.executeForm(shrubbery);

	std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
	RobotomyRequestForm robotomy("Bob");
	Bureaucrat surgeon(45, "Surgeon");
	surgeon.signForm(robotomy);
	surgeon.executeForm(robotomy);
	surgeon.executeForm(robotomy);
	surgeon.executeForm(robotomy);

	std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
	PresidentialPardonForm pardon("Alice");
	Bureaucrat president(5, "President");
	president.signForm(pardon);
	president.executeForm(pardon);

	std::cout << "\n--- Execution sans signature ---" << std::endl;
	PresidentialPardonForm unsigned_form("Charlie");
	president.executeForm(unsigned_form);

	std::cout << "\n--- Exceptions construction ---" << std::endl;
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

	delete contract;
	return 0;
}