/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListSort.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:55:18 by mde-lang          #+#    #+#             */
/*   Updated: 2024/11/15 16:31:18 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

std::list<int> Sort::listSort(std::list<int> great_values)
{
	std::list<std::pair<int, int> > pairs = makePairs(great_values);
	/////////////////////////////////////////////////////////////////////////////////////////////
	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
        std::cout << "pairs: " << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;
	BACKLINE;
	/////////////////////////////////////////////////////////////////////////////////////////////
	great_values = makeGreatList(pairs);
	/////////////////////////////////////////////////////////////////////////////////////////////
	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
        std::cout << "great value after makeGreatList: " << *it << std::endl;
	BACKLINE;
	std::cout << "great values size: " << great_values.size() << std::endl;
	BACKLINE;
	/////////////////////////////////////////////////////////////////////////////////////////////
	if (great_values.size() == 3)
		saveThird(great_values);
	if (great_values.size() == 1) {
		std::list<std::pair<int, int> >::iterator pair_it = pairs.begin();
		great_values.push_front(pair_it->first);
		if (_third == true)
			great_values = insertThird(great_values);
		/////////////////////////////////////////////////////////////////////////////////////////////
		for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it)
        	std::cout << "sorted third value : " << *it << std::endl;
		BACKLINE;
		/////////////////////////////////////////////////////////////////////////////////////////////
		return great_values;
	}
	else {
		std::cout << "else" << std::endl;
		great_values = listSort(great_values);
	}
	std::cout << "EXIT" << std::endl;
	BACKLINE;
	std::list<int> small_values = makeSmallList(pairs, great_values);

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
	if (_ac % 2 != 0)
		_odd_val = atoi(_av[_ac]);
	std::cout << "impair is: " << _odd_val << std::endl;
	return pairs;
}

std::list<int> Sort::makeGreatList(std::list<std::pair<int, int> > pairs)
{
	std::list<int> great_values;
	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
		great_values.push_back(pair_it->second);
	return great_values;
}

std::list<int> Sort::makeSmallList(std::list<std::pair<int, int> > pairs, std::list<int> great_values)
{	
	std::list<int> small_values;
	
	for (size_t i = 0; i <= _ac; ++i)
		small_values.push_back(0);

	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it) {
		for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
			if (*it == pair_it->second) {
				std::list<int>::iterator tmp = it;
				it = pair_it;
				small_values.erase(it);
				small_values.insert(pair_it, pair_it->second);
			}
		}
	}
}

void Sort::saveThird(std::list<int> great_values)
{
	std::list<int>::iterator it = great_values.begin();
	std::advance(it, 2);
	_third_val = *it;
	_third = true;
	std::cout << "third is : " << *it << std::endl;
	BACKLINE;
}

std::list<int> Sort::insertThird(std::list<int> great_values)
{
	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it) {
		std::list<int>::iterator it2 = it++;
		if (*it < *it2) {
			great_values.push_front(_third_val);
			return great_values;
		}
		else {
			if (_third_val > *it)
				great_values.push_back(_third_val);
			else
				great_values.insert(it, _third_val);
			return great_values;
		}
	}
	return great_values;
}

// std::list<int> Sort::insertOdd(std::list<int> great_values)
// {
// 	for (std::list<int>::iterator it = great_values.begin(); it != great_values.end(); ++it) {
// 		std::list<int>::iterator it2 = it++;
// 		if (*it < *it2) {
// 			great_values.push_front(_odd_val);
// 			return great_values;
// 		}
// 		else {
// 			it++;
// 			if (_odd_val > *it)
// 				great_values.push_back(_odd_val);
// 			else
// 				great_values.insert(it, _odd_val);
// 			return great_values;
// 		}
// 	}
// 	return great_values;
// }









// std::list<std::pair<int, int> > Sort::makePairs() // creation des paires
// {
// 	_it = _sorted_values.begin();
// 	_it2 = _it;
// 	std::advance(_it2, 1);
// 	for (size_t i = 1; i <= (_sorted_values.size()) / 2; ++i)
// 	{
// 		pairs.push_back(std::make_pair(*_it, *_it2));
// 		std::advance(_it, 2);
// 		std::advance(_it2, 2);
// 	}

// }



// void Sort::makePairs() // creation des paires
// {
// 	_it = _sorted_values.begin();
// 	_it2 = _it;
// 	std::advance(_it2, 1);
// 	for (size_t i = 1; i <= (_sorted_values.size()) / 2; ++i)
// 	{
// 		pairs.push_back(std::make_pair(*_it, *_it2));
// 		std::advance(_it, 2);
// 		std::advance(_it2, 2);
// 	}

// 	_sorted_values.clear();
	
// 	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
//         std::cout << "pair: " << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;
// 	std::cout << '\n';
// }

// void Sort::sortPairValues()
// {
// 	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
// 	{
// 		if (pair_it->first < pair_it->second)
// 		{
// 			int tmp = pair_it->first;
// 			pair_it->first = pair_it->second;
// 			pair_it->second = tmp;
// 		}
// 		_sorted_values.push_back(pair_it->first);
// 		std::cout << "swap: " << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;
		
// 	}
// 	std::cout << '\n';
// 	for (std::list<int>::iterator it = _sorted_values.begin(); it != _sorted_values.end(); ++it)
// 		std::cout << " value: " << *it << std::endl;
// 	std::cout << '\n';
// 	_step++;
// }

// void Sort::makePairs() // creation des paires pour list et vector
// {
// 	size_t i = 1;
// 	int impair = 2;

// 	if ((_ac - 1) % 2 == 0)
// 		impair = 1;
// 	while (i <= static_cast<size_t>(_ac - impair))
// 	{
// 		pairs.push_back(std::make_pair(atoi(_av[i]), atoi(_av[i + 1])));
// 		i += 2;
// 	}
// 	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
//         std::cout << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;
// }




// void Sort::splitValues()
// {
// 	for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
// 	{
// 		_great_values.push_back(pair_it->second);
// 		_small_values.push_back(pair_it->first);
// 		//std::cout << "greatValues: " << *it << std::endl;
// 		//std::cout << "smallValues: " << *it2 << std::endl;
// 	}
// 	for (std::list<int>::iterator it = _great_values.begin(); it != _great_values.end(); ++it)
// 	{
// 		std::cout << "greatValues: " << *it << std::endl;
// 	}
// }

// int Sort::insert()
// {
//     for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
//     {
//         std::list<std::pair<int, int> >::iterator pair_it2 = pair_it;
//         pair_it2++;

//         if (pair_it2 != pairs.end() && pair_it->first > pair_it2->first)
//             std::swap(*pair_it, *pair_it2);
//     }

//     for (std::list<std::pair<int, int> >::iterator pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it)
//         std::cout << "mergeInsert: " << "(" << pair_it->first << ", " << pair_it->second << ")" << std::endl;

//     return 0;
// }


// int Sort::fjFormula(int argc)
// {

// 	_jack = (static_cast<int>(pow(2, _k + 1)) + (static_cast<int>(pow(-1, _k)))) / 3;

// 	if ((argc - 1) % 2 == 0)	// pair
// 	// {
// 	// 	//_k = static_cast<int>(floor(log2(argc - 1)));
// 	// 	return 1;
// 	// }
// 	// else 						// impair
// 	// {
// 	// 	//_k = static_cast<int>(ceil(log2(argc - 1)));
// 	// 	_group_size = (static_cast<int>(pow(2, _k + 1)) + (static_cast<int>(pow(-1, _k)))) / 3;
// 	// 	return 2;
// 	// }
// 	return 0;
// }

//k = phase d'insertion. ex: K2: insert J3 et J2