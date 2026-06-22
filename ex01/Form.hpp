/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:05:45 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/22 16:31:09 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
	bool _sig;
	const std::string _name;
	const int _reqsig;
	const int _reqexec;
public:
	Form();
	Form(const Form &obj);
	bool	isSig() const;
	std::string	getName() const;
	void	beSigned(Bureaucrat &obj);
	unsigned int	getReqSig() const;
	unsigned int	getReqExec() const;
	Form	&operator=(const Form &obj);
	Form(std::string name, unsigned int reqsig, unsigned int reqexec);
	~Form();

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

std::ostream	&operator<<(std::ostream &out, const Form &bur);
