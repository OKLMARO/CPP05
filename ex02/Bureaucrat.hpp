/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:19:09 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 11:20:23 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat(unsigned int grade, std::string name);
	void				upGrade();
	void				downGrade();
	const std::string	getName() const;
	int					getGrade() const;
	void				signForm(AForm &obj);
	Bureaucrat			&operator=(const Bureaucrat &obj);
	void				executeForm(AForm const & form) const;
	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "grade is too high";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "grade is too low";
			}
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur);
