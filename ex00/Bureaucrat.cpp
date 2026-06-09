/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:21:29 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/09 13:40:40 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){};

Bureaucrat::Bureaucrat(unsigned int grade) : _grade(grade) {};

void	Bureaucrat::upGrade()
{
	
}

const std::string	Bureaucrat::getName()
{
	return this->_name;
}

int	Bureaucrat::getGrade()
{
	return this->_grade;
}

void	Bureaucrat::downGrade()
{
	
}
	
Bureaucrat::~Bureaucrat(){};
