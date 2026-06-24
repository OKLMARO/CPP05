/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:03:02 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 16:30:39 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target(""){};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj){};

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	AForm::operator=(obj);
	return *this;
}

void	RobotomyRequestForm::execution() const
{
	std::cout << "BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\nBRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n";
	if ((rand() % 2) == 0)
		std::cout << "SUCCESS !\n" << this->_target << " has been robotomized !\n";
	else
		std::cout << "FAILED !\n" << this->_target << " has not been robotomized !\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){};
