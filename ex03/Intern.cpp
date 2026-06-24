/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:44:51 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 16:03:54 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &obj)
{
	(void) obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
	(void) obj;
	return *this;
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	for (size_t i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			switch (i)
			{
				case 0:
					return (std::cout << "Intern creates " << name << "\n", new RobotomyRequestForm(target));
				case 1:
					return (std::cout << "Intern creates " << name << "\n", new ShrubberyCreationForm(target));
				case 2:
					return (std::cout << "Intern creates " << name << "\n", new PresidentialPardonForm(target));
			}
		}
	}
	std::cerr << "Form not found !\n";
	return NULL;
}

Intern::~Intern(){};
