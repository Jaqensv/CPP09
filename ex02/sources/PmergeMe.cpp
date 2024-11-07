/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:09:49 by mde-lang          #+#    #+#             */
/*   Updated: 2024/11/07 20:09:26 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

Sort::Sort(int argc, char *argv[]) : _ac(argc - 1), _av(argv), _pair_nb((argc - 1) / 2), _k(4)
{
	checkError(argc, argv);
	makeList();
	listSort();
}

Sort::~Sort(){}

void Sort::checkError(int argc, char *argv[]) const // check des erreurs avant parsing
{
	for (size_t i = 1; i <= static_cast<size_t>(argc - 1); ++i)
	{
		for (size_t j = 0; j < strlen(argv[i]); ++j)
		{       
			if (argv[i][0] >= '0' && argv[i][0] <= '9' && argc < 3)
				throw std::runtime_error("Error: needs at last two value to sort out");
			if (argv[i][j] == '-')
				throw std::runtime_error("Error: argument has to be positive");
			if (argv[i][j] < '0' || argv[i][j] > '9')
				throw std::runtime_error("Error: argument has to be a number");
		}
	}
}

void Sort::makeList()
{
	for (size_t i = 1; i <= static_cast<size_t>(_ac); ++i)
		_values.push_back(atoi(_av[i]));
	_it = _values.begin();
	_it2 = _it;
	std::advance(_it2, 1);
}
