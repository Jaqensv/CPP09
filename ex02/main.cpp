/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:30:47 by mde-lang          #+#    #+#             */
/*   Updated: 2025/01/13 14:06:14 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int main(int argc, char *argv[])
{
	std::clock_t start;
	std::clock_t finish;
	try
	{
		std::cout << "Initial: ";
		for (size_t i = 1; argv[i]; ++i)
			std::cout << argv[i] << " ";
		BACKLINE;
		BACKLINE;
		start = std::clock();
		Sort sort(argc, argv);
		BACKLINE;
		finish = std::clock();
		std::cout << "Time to process a range of " << argc -1 << " elements with std::list<int>: " << (float)(finish - start)/CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
		start = std::clock();
		BACKLINE;
		VSort vsort(argc, argv);
		BACKLINE;
		finish = std::clock();
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector<int>: " << (float)(finish - start)/CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
