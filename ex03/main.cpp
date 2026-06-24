/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:56:39 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 16:06:49 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	Intern someRandomIntern;
	std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		Bureaucrat surgeon(45, "Surgeon");
		surgeon.signForm(*rrf);
		surgeon.executeForm(*rrf);
		surgeon.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
	AForm *scf = someRandomIntern.makeForm("shrubbery creation", "home");
	if (scf)
	{
		Bureaucrat gardener(130, "Gardener");
		gardener.signForm(*scf);
		gardener.executeForm(*scf);
		delete scf;
	}

	std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
	AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
	if (ppf)
	{
		Bureaucrat president(5, "President");
		president.signForm(*ppf);
		president.executeForm(*ppf);
		delete ppf;
	}

	std::cout << "\n--- Form inexistant ---" << std::endl;
	AForm *unknown = someRandomIntern.makeForm("unknown form", "target");
	if (!unknown)
		std::cerr << "Null pointer returned as expected" << std::endl;

	return 0;
}