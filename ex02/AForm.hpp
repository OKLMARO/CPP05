/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:05:45 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/22 18:28:07 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	bool _sig;
	const std::string _name;
	const int _reqsig;
	const int _reqexec;
public:
	AForm();
	AForm(const AForm &obj);
	bool	isSig() const;
	std::string	getName() const;
	void	beSigned(Bureaucrat &obj);
	unsigned int	getReqSig() const;
	unsigned int	getReqExec() const;
	AForm	&operator=(const AForm &obj);
	AForm(std::string name, unsigned int reqsig, unsigned int reqexec);
	~AForm();

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

std::ostream	&operator<<(std::ostream &out, const AForm &bur);
