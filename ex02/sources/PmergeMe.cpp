/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:09:49 by mde-lang          #+#    #+#             */
/*   Updated: 2024/11/17 18:12:33 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

Sort::Sort(int argc, char *argv[]) : _ac(argc - 1), _av(argv), _rstep(0)
{
	checkError(argc, argv);
	std::list<int> sorted_values = listSort(initialData());
}

Sort::~Sort(){}

void Sort::checkError(int argc, char *argv[]) const
{
	for (size_t i = 1; i <= static_cast<size_t>(argc - 1); ++i) {
		for (size_t j = 0; j < strlen(argv[i]); ++j) {       
			if (argv[i][0] >= '0' && argv[i][0] <= '9' && argc < 3)
				throw std::runtime_error("Error: needs at last two value to sort out");
			if (argv[i][j] == '-')
				throw std::runtime_error("Error: argument has to be positive");
			if (argv[i][j] < '0' || argv[i][j] > '9')
				throw std::runtime_error("Error: argument has to be a number");
		}
	}
}

std::list<int> Sort::initialData()
{
	std::list<int> initial_list;

	for (size_t i = 1; i <= static_cast<size_t>(_ac); ++i)
		initial_list.push_back(atoi(_av[i]));
	////////////////////////////////////////////////////////////////////////////////////////////
	for (std::list<int>::iterator it = initial_list.begin(); it != initial_list.end(); ++it)
        std::cout << "initial values: " << *it << std::endl;
	BACKLINE;
	return initial_list;
}
