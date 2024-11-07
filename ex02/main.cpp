/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:30:47 by mde-lang          #+#    #+#             */
/*   Updated: 2024/11/07 18:20:44 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

void Sort::display() const
{

}

int main(int argc, char *argv[])
{
	try
	{
		Sort sort(argc, argv);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
