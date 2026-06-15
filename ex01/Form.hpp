/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:05:45 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/15 18:35:13 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	bool _sig;
	const std::string _name;
	const unsigned int _reqsig;
	const unsigned int _reqexec;
public:
	Form();
	Form(const Form &obj);
	bool	isSig() const;
	const std::string	getName() const;
	const unsigned int	getReqSig() const;
	const unsigned int	getReqExec() const;
	void	beSigned(const Bureaucrat &obj);
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
