/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:21:29 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 15:56:13 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {};

Bureaucrat::Bureaucrat(unsigned int grade, std::string name) : _name(name), _grade(grade) {};

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
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::downGrade()
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn’t sign " << obj.getName() <<  " because " << e.what() << '\n';
	}
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat(){};
