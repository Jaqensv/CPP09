/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:09:49 by mde-lang          #+#    #+#             */
/*   Updated: 2025/01/11 15:13:38 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

////LIST///////////////////////////////////////////////////////////////////////////////////////////

Sort::Sort(int argc, char *argv[]) : _ac(argc - 1), _av(argv), _rstep(0), _k(0)
{
	checkError(argc, argv);
	std::list<int> sorted_values = listSort(initialData());
	std::cout << "Sorted (list): ";
	for (std::list<int>::iterator it = sorted_values.begin(); it != sorted_values.end(); ++it)
        std::cout << *it << " ";
}

Sort::~Sort(){}

Sort::Sort(const Sort &src) {*this = src;}

Sort &Sort::operator=(const Sort &rhs) {
	if (this != &rhs) {
		_ac = rhs._ac;
		_av = rhs._av;
		_rstep = rhs._rstep;
		_k = rhs._k;
		_it = rhs._it;
		_it2 = rhs._it2;
		_initial_great_values = rhs._initial_great_values;
		_initial_pairs = rhs._initial_pairs;
	}
	return *this;
};

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
	return initial_list;
}

////VECTOR///////////////////////////////////////////////////////////////////////////////////////////

VSort::VSort(int argc, char *argv[]) : _ac(argc - 1), _av(argv), _rstep(0), _k(0)
{
	checkError(argc, argv);
	std::vector<int> sorted_values = vectorSort(initialData());
	std::cout << "Sorted (vector): ";
	for (std::vector<int>::iterator it = sorted_values.begin(); it != sorted_values.end(); ++it)
        std::cout << *it << " ";
}

VSort::~VSort(){}

VSort::VSort(const VSort &src) {*this = src;}

VSort &VSort::operator=(const VSort &rhs) {
	if (this != &rhs) {
		_ac = rhs._ac;
		_av = rhs._av;
		_rstep = rhs._rstep;
		_k = rhs._k;
		_it = rhs._it;
		_it2 = rhs._it2;
		_initial_great_values = rhs._initial_great_values;
		_initial_pairs = rhs._initial_pairs;
	}
	return *this;
};

void VSort::checkError(int argc, char *argv[]) const
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

std::vector<int> VSort::initialData()
{
	std::vector<int> initial_list;

	for (size_t i = 1; i <= static_cast<size_t>(_ac); ++i)
		initial_list.push_back(atoi(_av[i]));
	return initial_list;
}
