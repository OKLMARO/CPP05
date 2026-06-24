/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:02:51 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 16:30:10 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target(""){};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target){};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj){};

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	AForm::operator=(obj);
	return *this;
}

void	PresidentialPardonForm::execution() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){};
