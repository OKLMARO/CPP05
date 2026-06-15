/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:19:09 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/15 17:20:02 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int		_grade;
public:
	Bureaucrat();
	void				upGrade();
	void				downGrade();
	Bureaucrat(const Bureaucrat &obj);
	const std::string	getName() const;
	int					getGrade() const;
	Bureaucrat(unsigned int grade, std::string name);
	Bureaucrat			&operator=(const Bureaucrat &obj);
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
