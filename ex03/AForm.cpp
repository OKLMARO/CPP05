/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:05:42 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 10:39:32 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _sig(false), _name("Default"), _reqsig(150), _reqexec(150){};

AForm::AForm(std::string name, unsigned int reqsig, unsigned int reqexec) : _sig(false), _name(name), _reqsig(reqsig), _reqexec(reqexec)
{
	if (this->_reqexec < 1 || this->_reqsig < 1)
		throw AForm::GradeTooHighException();
	if (this->_reqexec > 150 || this->_reqsig > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj) : _sig(obj._sig), _name(obj._name), _reqsig(obj._reqsig), _reqexec(obj._reqexec){};

AForm	&AForm::operator=(const AForm &obj)
{
	if (this != &obj)
		this->_sig = obj._sig;
	return *this;
}

bool	AForm::isSig() const
{
	return this->_sig;
}

std::string	AForm::getName() const
{
	return this->_name;
}

unsigned int	AForm::getReqSig() const
{
	return this->_reqsig;
}

unsigned int	AForm::getReqExec() const
{
	return this->_reqexec;
}

void	AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= this->_reqsig)
		this->_sig = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_sig == false)
		throw AForm::FormNotSignedException();
	else
	{
		if (executor.getGrade() > this->_reqexec)
			throw Bureaucrat::GradeTooLowException();
		else
			execution();
	}
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm name : " << form.getName() << " | is signed : " << form.isSig() << " | grade required to sign it : " << form.getReqSig() << " | grade required to execute it : " << form.getReqExec() << '\n';
	return out;
}

AForm::~AForm(){};
