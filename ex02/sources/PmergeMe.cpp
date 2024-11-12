/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:09:49 by mde-lang          #+#    #+#             */
/*   Updated: 2024/11/12 19:42:22 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

Sort::Sort(int argc, char *argv[]) : _ac(argc - 1), _av(argv), _pair_nb((argc - 1) / 2), _k(4)
{
	checkError(argc, argv);
	initialData();
	listSort(_initial_great_values);
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

void Sort::initialData()
{
	// for (size_t i = 1; i <= static_cast<size_t>(_ac); ++i){
	// 	_initial_values.push_back(atoi(_av[i]));
	// 	_sorted_values.push_back(atoi(_av[i]));
	// }
	int impair = 0;
	if ((_ac - 1) % 2 == 0)
		impair = 1;
	for (size_t i = 1; i + impair <= static_cast<size_t>(_ac);)
	{
		_initial_pairs.push_back(std::make_pair(atoi(_av[i]), atoi(_av[i + 1])));
		atoi(_av[i]) > atoi(_av[i + 1]) ? _initial_great_values.push_back(atoi(_av[i])) : _initial_great_values.push_back(atoi(_av[i + 1]));
		i += 2;
	}
	for (std::list<std::pair<int, int> >::iterator pair_it = _initial_pairs.begin(); pair_it != _initial_pairs.end(); ++pair_it)
        std::cout << "initial pairs: " << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;
	std::cout << '\n';
	for (std::list<int>::iterator it = _initial_great_values.begin(); it != _initial_great_values.end(); ++it)
        std::cout << "initial great values: " << *it << std::endl;
	std::cout << '\n';
	// _it = _sorted_values.begin();
	// _it2 = _it;
	// std::advance(_it2, 1);
}
