/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:03:08 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 16:30:39 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target(""){};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj){};

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	AForm::operator=(obj);
	return *this;
}

void	ShrubberyCreationForm::execution() const
{
	std::ofstream file((_target + "_shrubbery").c_str());

	if (!file.is_open())
		std::cerr << "File error !\n";
	else
	{
		file << "                                                         .\n                                              .         ;  \n                 .              .              ;%     ;;   \n                   ,           ,                :;%  %;   \n                    :         ;                   :;%;'     .,   \n           ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'   \n                        `@%.  `;@%.      ;@@%;         \n                          `@%%. `@%%    ;@@%;        \n                            ;@%. :@%%  %@@%;       \n                              %@bd%%%bd%%:;     \n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '         \n                                %@@@o%;:(.,'         \n                            `.. %@@@o%::;         \n                               `)@@@o%::;         \n                                %@@(o)::;        \n                               .%@@@@%::;         \n                               ;%@@@@%::;.          \n                              ;%@@@@%%:;;;. \n                          ...;%@@@@@%%:;;;;,..    \n";
		file.close();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};
