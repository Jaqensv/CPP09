/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:30:47 by mde-lang          #+#    #+#             */
/*   Updated: 2025/01/11 15:26:21 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int main(int argc, char *argv[])
{
	try
	{
		std::cout << "Initial: ";
		for (size_t i = 1; argv[i]; ++i)
			std::cout << argv[i] << " ";
		BACKLINE;
		//Sort sort(argc, argv);
		BACKLINE;
		VSort vsort(argc, argv);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
