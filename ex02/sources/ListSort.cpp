/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:55:18 by mde-lang          #+#    #+#             */
/*   Updated: 2025/01/11 15:42:35 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

std::list<int> Sort::listSort(std::list<int> great_values)
{
	int odd_value = -1;

	std::list<std::pair<int, int> > pairs = makePairs(great_values);
	if (great_values.size() % 2 != 0)
	 	odd_value = great_values.back();
	great_values = makeGreatList(pairs);
	std::list<int> small_values = makeSmallList(great_values, pairs, odd_value);
	if (great_values.size() > 1) {
		_rstep++;
		great_values = listSort(great_values);
	}
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

std::list<int> Sort::insertSmall(std::list<int> great_values, std::list<int> small_values)
{
    size_t j = 0;
    std::list<int>::iterator small_it = small_values.begin();

    while (j < small_values.size()) {
        int target_value = *small_it;
        ssize_t k = static_cast<ssize_t>(pow(2, j + 1)) - 1;
        if (k >= static_cast<ssize_t>(great_values.size()))
            k = static_cast<ssize_t>(great_values.size()) - 1;
        great_values = dichoInsert(great_values, target_value, k);
        ++small_it;
        ++j;
    }

    return great_values;
}

std::list<int> Sort::dichoInsert(std::list<int> great_values, int target_value, ssize_t k) {
    ssize_t start = 0;
    ssize_t end = (k >= static_cast<ssize_t>(great_values.size())) ? great_values.size() : k + 1;
    ssize_t mid;

    std::list<int>::iterator it_start = great_values.begin();
    std::list<int>::iterator it_end = great_values.begin();
    std::advance(it_end, end);

    while (start < end) {
        mid = start + (end - start) / 2;
        std::list<int>::iterator it_mid = great_values.begin();
        std::advance(it_mid, mid);

        if (*it_mid == target_value) 
            return great_values;
        else if (*it_mid > target_value) {
            end = mid;
            it_end = it_mid;
        } else {
            start = mid + 1;
            it_start = it_mid;
            ++it_start;
        }
    }
    std::list<int>::iterator it_insert = great_values.begin();
    std::advance(it_insert, start);
    great_values.insert(it_insert, target_value);

    return great_values;
}
