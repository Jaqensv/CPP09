/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:55:18 by mde-lang          #+#    #+#             */
/*   Updated: 2024/11/25 18:59:09 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

std::list<int> Sort::listSort(std::list<int> great_values)
{
	int odd_value = -1;

	std::list<std::pair<int, int> > pairs = makePairs(great_values);
	if (great_values.size() % 2 != 0)
	 	odd_value = great_values.back();
	std::cout << "odd is : " << odd_value << std::endl;
	BACKLINE;
	////////////////////////////////////////////////////////////////////////////////////////////
	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
        std::cout << "pairs: " << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;
	BACKLINE;
	////////////////////////////////////////////////////////////////////////////////////////////
	great_values = makeGreatList(pairs);
	// for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
    //     std::cout << "great values after makeGreatList: " << *it << std::endl;
	// BACKLINE;
	// std::cout << "great values size: " << great_values.size() << std::endl;
	// BACKLINE;
	std::list<int> small_values = makeSmallList(great_values, pairs, odd_value);
	////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////
	if (great_values.size() > 1) {
		_rstep++;
		great_values = listSort(great_values);
	}
	std::cout << "EXIT" << std::endl;
	BACKLINE;
	great_values = insertSmall(great_values, small_values);
	//for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
    //     std::cout << "sorted great values: " << *it << std::endl;
	// BACKLINE;
	// for (std::list<int>::iterator it = small_values.begin(); it != small_values.end(); ++it)
    //     std::cout << "sorted small values: " << *it << std::endl;
	//BACKLINE;

	return great_values;
}

std::list<std::pair<int, int> > Sort::makePairs(std::list<int> great_values) // creation des paires
{
	std::list<std::pair<int, int> > pairs;
	_it = great_values.begin();
	_it2 = _it;
	std::advance(_it2, 1);
	for (size_t i = 1; i <= (great_values.size()) / 2; ++i)
	{
		if (*_it < *_it2)
			pairs.push_back(std::make_pair(*_it, *_it2));
		else
			pairs.push_back(std::make_pair(*_it2, *_it));
		std::advance(_it, 2);
		std::advance(_it2, 2);
	}
	if (_rstep == 0) {
		_initial_pairs = pairs;
		_initial_great_values = makeGreatList(pairs);
	}
	return pairs;
}

std::list<int> Sort::makeGreatList(std::list<std::pair<int, int> > pairs)
{
	std::list<int> great_values;
	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
		great_values.push_back(pair_it->second);
	return great_values;
}

std::list<int> Sort::makeSmallList(std::list<int> great_values, std::list<std::pair<int, int > > pairs, int third_value)
{	
	std::list<int> small_values;

	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it) {
		for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
			if (*it == pair_it->second) {
				small_values.push_back(pair_it->first);
				//std::cout << "small in makeSmallList: " << pair_it->first << std::endl;
			}
		}
	}
	if (third_value != -1)
		small_values.push_back(third_value);
	return small_values;
}

std::list<int> Sort::insertGreat(std::list<int> great_values)
{
	for (std::list<int>::iterator it = _initial_great_values.begin(); it != _initial_great_values.end(); ++it) {
		bool found = false;
		std::list<int>::iterator it2 = great_values.begin();
		for (; it2 != great_values.end(); ++it2) {
			if (*it == *it2)
				found = true;
		}
		if (found == false) {
			while (*it > *it2)
				it2++;
			great_values.insert(it2, *it);
		}
    }
	return great_values;
}

// std::list<int> Sort::insertSmall(std::list<int> great_values, std::list<int> small_values)
// {
// 	size_t j = 0;
// 	//int k = 0;
// 	//std::list<int>::iterator great_it = great_values.begin();

// 	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
//     	std::cout << "great values in insertSmall: " << *it << std::endl;
// 	for (std::list<int>::iterator it = small_values.begin(); it != small_values.end(); ++it)
// 	    std::cout << "small values in insertSmall: " << *it << std::endl;
// 	BACKLINE;

// 	std::list<int>::iterator it = small_values.begin();
// 	while (j++ < small_values.size()) {
// 		great_values.push_back(*it);
// 		it++;
// 		great_values.sort();	
// 	}
// 	return great_values;
// }

std::list<int> Sort::insertSmall(std::list<int> great_values, std::list<int> small_values)
{
	size_t j = 0;
	ssize_t k = 0;
	//std::list<int>::iterator great_it = great_values.begin();

	// for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
    // 	std::cout << "great values in insertSmall: " << *it << std::endl;
	// for (std::list<int>::iterator it = small_values.begin(); it != small_values.end(); ++it)
	//     std::cout << "small values in insertSmall: " << *it << std::endl;
	// BACKLINE;

	//std::list<int>::iterator it = small_values.begin();
	while (j++ < small_values.size()) {
		k = (static_cast<ssize_t>(pow(2, j + 1)) + (static_cast<ssize_t>(pow(-1, j)))) / 3;
		great_values = dichoInsert(great_values, small_values, k);
		if (k == 5)
			exit(1);
	}
	return great_values;
}

std::list<int> Sort::dichoInsert(std::list<int> great_values, std::list<int> small_values, ssize_t k)
{
	ssize_t i = k / 2;
	ssize_t j = 0;

	for (std::list<int>::iterator it = small_values.begin(); it != small_values.end(); ++it)
	    std::cout << "small values in dicho: " << *it << std::endl;
	BACKLINE;
	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
    	std::cout << "great values in dicho: " << *it << std::endl;
	BACKLINE;
	std::list<int>::iterator small_it = small_values.begin();
	std::list<int>::iterator great_it = great_values.begin();

	std::advance(small_it, -1);
	if (k > static_cast<ssize_t>(great_values.size()))
		k = static_cast<ssize_t>(great_values.size());
	std::advance(small_it, k);
	std::cout << "k = " << k << std::endl;

	if (k == 1) {
		great_values.push_front(*small_it);
	} else {
		while (i % 2 > 1) {
			j = i;
			if (*small_it < *great_it) {
				while (j > i)
					--j;
			}
			else if (*small_it > *great_it) {
				while (j < i)
					++j;
			}
			i %= 2;
		}
		std::list<int>::iterator great_it = great_values.begin();
		//std::advance(great_it, -1);
		std::advance(great_it, j);
		std::cout << *small_it << " to insert before : " << *great_it << std::endl;
		BACKLINE;
		great_values.insert(great_it, *small_it);
	}

	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
    	std::cout << "great values in dicho sorted: " << *it << std::endl;
	BACKLINE;
	return great_values;
}

// std::list<int> Sort::insertSmall(std::list<int> great_values, std::list<int> small_values)
// {
// 	size_t j = 0;
// 	int k = 0;
// 	//std::list<int>::iterator great_it = great_values.begin();

// 	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
//     	std::cout << "great values in insertSmall: " << *it << std::endl;
// 	for (std::list<int>::iterator it = small_values.begin(); it != small_values.end(); ++it)
// 	    std::cout << "small values in insertSmall: " << *it << std::endl;
// 	BACKLINE;

// 	while (j++ < small_values.size()) {
// 		std::list<int>::iterator small_it = small_values.begin();
// 		k = (static_cast<int>(pow(2, j + 1)) + (static_cast<int>(pow(-1, j)))) / 3;
// 		std::cout << "k = " << k << std::endl;
// 		if (k == 1) {
// 			std::cout << "value to insert in k = 1: " << *small_it << std::endl;
// 			great_values.push_front(*small_it);
// 		} else {
// 			if (k > static_cast<int>(small_values.size())) {
// 				small_it = small_values.end();
// 				small_it--;
// 				//small_values.erase(--small_values.end());
// 			}
// 			else
// 				std::advance(--small_it, k);
// 			std::cout << "value to insert: " << *small_it << std::endl;

// 			//great_values = dichotomy(great_values, small_it);
// 			//great_values.insert(great_it, *small_it);
// 		}
// 		for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
//         	std::cout << "sorted great values: " << *it << " | k = " << k << " | j = " << j << std::endl;
// 		BACKLINE;
// 	}
// 	return great_values;
// }


//k = phase d'insertion. ex: K2: insert J3 et J2
