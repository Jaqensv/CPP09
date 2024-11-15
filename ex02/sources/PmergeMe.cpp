/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:09:49 by mde-lang          #+#    #+#             */
/*   Updated: 2024/11/15 15:31:34 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

Sort::Sort(int argc, char *argv[]) : _ac(argc - 1), _av(argv), _odd_val(0), _odd(false), _third_val(0), _third(false)
{
	checkError(argc, argv);
	std::list<int> sorted_values = listSort(initialData());
	/////////////////////////////////////////////////////////////////////////////////////////////
	for (std::list<int>::iterator it = sorted_values.begin(); it != sorted_values.end(); ++it)
        	std::cout << "sorted values: " << *it << std::endl;
	BACKLINE;
}

Sort::~Sort(){}

void Sort::checkError(int argc, char *argv[]) const // check des erreurs avant parsing
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

	int impair = 1;
	if (_ac % 2 == 0)
		impair = 0;
	else {
		_odd_val = atoi(_av[_ac]);
		_odd = true;
	}
	for (size_t i = 1; i + impair <= static_cast<size_t>(_ac); ++i) {
		initial_list.push_back(atoi(_av[i]));	
	}
	/////////////////////////////////////////////////////////////////////////////////////////////
	for (std::list<int>::iterator it = initial_list.begin(); it != initial_list.end(); ++it)
        std::cout << "initial values: " << *it << std::endl;
	BACKLINE;
	std::cout << "impair : " << _odd_val << std::endl;
	BACKLINE;
	return initial_list;
}
