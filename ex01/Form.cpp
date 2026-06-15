/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:05:42 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/15 18:37:19 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _sig(false), _name("Default"), _reqsig(150), _reqexec(150){};

Form::Form(std::string name, unsigned int reqsig, unsigned int reqexec) : _sig(false), _name(name), _reqsig(reqsig), _reqexec(reqexec){};

Form::Form(const Form &obj) : _sig(obj._sig), _name(obj._name), _reqsig(obj._reqsig), _reqexec(obj._reqexec){};

Form	&Form::operator=(const Form &obj)
{
	if (this != &obj)
		this->_sig = obj._sig;
	return *this;
}

bool	Form::isSig() const
{
	return this->_sig;
}

const std::string	Form::getName() const
{
	return this->_name;
}

const unsigned int	Form::getReqSig() const
{
	return this->_reqsig;
}

const unsigned int	Form::getReqExec() const
{
	return this->_reqexec;
}

void	Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() <= this->_reqsig)
		this->_sig = true;
	else
		throw Form::GradeTooLowException();
}

Form::~Form(){};
