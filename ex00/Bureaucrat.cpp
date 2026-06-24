/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:21:29 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 16:14:49 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {};

Bureaucrat::Bureaucrat(unsigned int grade, std::string name) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
		this->_grade = obj._grade;
	return *this;
}

const std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::upGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::downGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat(){};
