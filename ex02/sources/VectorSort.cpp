/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:52:34 by mde-lang          #+#    #+#             */
/*   Updated: 2024/12/10 16:58:57 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

std::vector<int> VSort::vectorSort(std::vector<int> great_values)
{
	int odd_value = -1;

	std::vector<std::pair<int, int> > pairs = makePairs(great_values);
	if (great_values.size() % 2 != 0)
	 	odd_value = great_values.back();
	std::cout << "odd is : " << odd_value << std::endl;
	for (std::vector<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
        std::cout << "pairs: " << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;
	great_values = makeGreatVector(pairs);
	std::vector<int> small_values = makeSmallVector(great_values, pairs, odd_value);
	if (great_values.size() > 1) {
		_rstep++;
		great_values = vectorSort(great_values);
	}
	std::cout << "EXIT" << std::endl;
	great_values = insertSmall(great_values, small_values);

	return great_values;
}

std::vector<std::pair<int, int> > VSort::makePairs(std::vector<int> great_values) // creation des paires
{
	std::vector<std::pair<int, int> > pairs;
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
		_initial_great_values = makeGreatVector(pairs);
	}
	return pairs;
}

std::vector<int> VSort::makeGreatVector(std::vector<std::pair<int, int> > pairs)
{
	std::vector<int> great_values;
	for (std::vector<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
		great_values.push_back(pair_it->second);
	return great_values;
}

std::vector<int> VSort::makeSmallVector(std::vector<int> great_values, std::vector<std::pair<int, int > > pairs, int third_value)
{	
	std::vector<int> small_values;

	for (std::vector<int>::iterator it = great_values.begin(); it != great_values.end(); ++it) {
		for (std::vector<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
			if (*it == pair_it->second)
				small_values.push_back(pair_it->first);
		}
	}
	if (third_value != -1)
		small_values.push_back(third_value);
	return small_values;
}

std::vector<int> VSort::insertGreat(std::vector<int> great_values)
{
	for (std::vector<int>::iterator it = _initial_great_values.begin(); it != _initial_great_values.end(); ++it) {
		bool found = false;
		std::vector<int>::iterator it2 = great_values.begin();
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

std::vector<int> VSort::insertSmall(std::vector<int> great_values, std::vector<int> small_values)
{
	size_t j = 0;
	ssize_t k = -1;

	while (j++ < small_values.size()) {
		for (std::vector<int>::iterator it = small_values.begin(); it != small_values.end(); ++it)
	    	std::cout << "small values in insertSmall: " << *it << std::endl;
		BACKLINE;
		k = (static_cast<ssize_t>(pow(2, j + 1)) + (static_cast<ssize_t>(pow(-1, j)))) / 3;
		ssize_t last_k = (static_cast<ssize_t>(pow(2, j)) + (static_cast<ssize_t>(pow(-1, j - 1)))) / 3;
		if (k < _k)
			k = _k;
		_k = k;
		std::vector<int>::iterator small_it = small_values.begin();
		std::advance(small_it, k);
		for (std::vector<int>::iterator great_it = great_values.begin(); great_it != great_values.end(); ++great_it) {
			if (*small_it == *great_it)
				--small_it;
		}
		int target_value = *small_it;
		great_values = dichoInsert(great_values, target_value, k, last_k);
	}
	return great_values;
}


std::vector<int> VSort::dichoInsert(std::vector<int> great_values, int target_value, ssize_t k, ssize_t last_k) {
    ssize_t start = 0;
    ssize_t end = k > static_cast<ssize_t>(great_values.size()) ? static_cast<ssize_t>(great_values.size()) : k;
    ssize_t mid = calculateMid(start, end);

    std::cout << "START DICHO INSERT\n";
    std::cout << "Last k: " << last_k << "\n";
    std::cout << "Target value: " << target_value << "\n";

    for (std::vector<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
        std::cout << "great_values: " << *it << "\n";
    if (great_values.empty() || k <= 0) {
        great_values.push_back(target_value);
        return great_values;
    }
    std::vector<int>::iterator it = great_values.begin();
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

    for (std::vector<int>::iterator it = great_values.begin(); it != great_values.end(); ++it) {
        std::cout << "Sorted great_values: " << *it << "\n";
    }
    std::cout << "END DICHO INSERT\n";
    return great_values;
}
