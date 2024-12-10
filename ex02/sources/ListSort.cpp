/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:55:18 by mde-lang          #+#    #+#             */
/*   Updated: 2024/12/10 16:38:36 by mde-lang         ###   ########.fr       */
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
	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
        std::cout << "pairs: " << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;
	great_values = makeGreatList(pairs);
	std::list<int> small_values = makeSmallList(great_values, pairs, odd_value);
	if (great_values.size() > 1) {
		_rstep++;
		great_values = listSort(great_values);
	}
	std::cout << "EXIT" << std::endl;
	great_values = insertSmall(great_values, small_values);

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
			if (*it == pair_it->second)
				small_values.push_back(pair_it->first);
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

std::list<int> Sort::insertSmall(std::list<int> great_values, std::list<int> small_values)
{
	size_t j = 0;
	ssize_t k = -1;

	while (j++ < small_values.size()) {
		for (std::list<int>::iterator it = small_values.begin(); it != small_values.end(); ++it)
	    	std::cout << "small values in insertSmall: " << *it << std::endl;
		BACKLINE;
		k = (static_cast<ssize_t>(pow(2, j + 1)) + (static_cast<ssize_t>(pow(-1, j)))) / 3;
		ssize_t last_k = (static_cast<ssize_t>(pow(2, j)) + (static_cast<ssize_t>(pow(-1, j - 1)))) / 3;
		if (k < _k)
			k = _k;
		_k = k;
		std::list<int>::iterator small_it = small_values.begin();
		std::advance(small_it, k);
		for (std::list<int>::iterator great_it = great_values.begin(); great_it != great_values.end(); ++great_it) {
			if (*small_it == *great_it)
				--small_it;
		}
		int target_value = *small_it;
		great_values = dichoInsert(great_values, target_value, k, last_k);
	}
	return great_values;
}


std::list<int> Sort::dichoInsert(std::list<int> great_values, int target_value, ssize_t k, ssize_t last_k) {
    ssize_t start = 0;
    ssize_t end = k > static_cast<ssize_t>(great_values.size()) ? static_cast<ssize_t>(great_values.size()) : k;
    ssize_t mid = calculateMid(start, end);

    std::cout << "START DICHO INSERT\n";
    std::cout << "Last k: " << last_k << "\n";
    std::cout << "Target value: " << target_value << "\n";

    for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
        std::cout << "great_values: " << *it << "\n";
    if (great_values.empty() || k <= 0) {
        great_values.push_back(target_value);
        return great_values;
    }
    std::list<int>::iterator it = great_values.begin();
    while (start < end) {
        mid = calculateMid(start, end);
        it = great_values.begin();
        std::advance(it, mid);

        if (*it == target_value) {
            great_values.insert(it, target_value);
            return great_values;
        } 
		else if (target_value < *it)
            end = mid;
		else
            start = mid + 1;
    }
    it = great_values.begin();
    std::advance(it, start);
    great_values.insert(it, target_value);

    std::cout << "Inserted value: " << target_value << " at position: " << start << "\n";

    for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it) {
        std::cout << "Sorted great_values: " << *it << "\n";
    }
    std::cout << "END DICHO INSERT\n";
    return great_values;
}
