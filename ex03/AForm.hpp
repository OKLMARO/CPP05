/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:05:45 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 11:27:05 by oamairi          ###   ########.fr       */
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
	virtual void	execution() const = 0;
public:
	AForm();
	AForm(const AForm &obj);
	bool			isSig() const;
	std::string		getName() const;
	unsigned int	getReqSig() const;
	unsigned int	getReqExec() const;
	void			beSigned(Bureaucrat &obj);
	AForm			&operator=(const AForm &obj);
	void			execute(Bureaucrat const & executor) const;
	AForm(std::string name, unsigned int reqsig, unsigned int reqexec);
	virtual ~AForm();

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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Form is not signed";
			}
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &bur);
