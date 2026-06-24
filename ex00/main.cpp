/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:56:39 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/24 15:54:18 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat alice(75, "Alice");
	std::cout << alice << std::endl;

	alice.upGrade();
	std::cout << alice << std::endl;

	alice.downGrade();
	std::cout << alice << std::endl;

	Bureaucrat def;
	std::cout << def << std::endl;

	try
	{
		Bureaucrat top(1, "Top");
		std::cout << top << std::endl;
		top.upGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bot(150, "Bot");
		std::cout << bot << std::endl;
		bot.downGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}