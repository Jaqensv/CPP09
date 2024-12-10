#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iterator> // std::advance
#include <utility> // std::pair
#include <algorithm> // std::swap
#include <cmath> // logarithme / std::ceil et std::floor
#include <ctime> // std::clock
#include <string>

#define BACKLINE std::cout << '\n'

class Sort {

public:

	~Sort();
	Sort(const Sort &src);
	Sort(int argc, char *argv[]);
	Sort &operator=(const Sort &rhs);
	void checkError(int argc, char *argv[]) const;
	std::list<int> initialData();
	//
	std::list<int> listSort(std::list<int> great_values);
	std::list<std::pair<int, int> > makePairs(std::list<int> great_values);
	std::list<int> makeGreatList(std::list<std::pair<int, int> > pairs);
	std::list<int> makeSmallList(std::list<int> great_values, std::list<std::pair<int, int > > pairs, int third_value);
	std::list<int> insertGreat(std::list<int> great_values);
	std::list<int> insertSmall(std::list<int> great_values, std::list<int> small_values);
	std::list<int> dichoInsert(std::list<int> great_values, int target_value, ssize_t k, ssize_t last_k);

private:

	Sort();
	int 	  	_ac;
	char	  **_av;
	int			_rstep;
	ssize_t		_k;

	std::list<int>::iterator			_it;
	std::list<int>::iterator 			_it2;
	std::list<int> 						_initial_great_values;
	std::list<std::pair<int, int> > 	_initial_pairs;
	ssize_t calculateMid(ssize_t start, ssize_t end) {return start + (end - start) / 2;}

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class VSort {

public:

	~VSort();
	VSort(const VSort &src);
	VSort(int argc, char *argv[]);
	Sort &operator=(const Sort &rhs);
	void checkError(int argc, char *argv[]) const;
	std::vector<int> initialData();
	//
	std::vector<int> vectorSort(std::vector<int> great_values);
	std::vector<std::pair<int, int> > makePairs(std::vector<int> great_values);
	std::vector<int> makeGreatVector(std::vector<std::pair<int, int> > pairs);
	std::vector<int> makeSmallVector(std::vector<int> great_values, std::vector<std::pair<int, int > > pairs, int third_value);
	std::vector<int> insertGreat(std::vector<int> great_values);
	std::vector<int> insertSmall(std::vector<int> great_values, std::vector<int> small_values);
	std::vector<int> dichoInsert(std::vector<int> great_values, int target_value, ssize_t k, ssize_t last_k);

private:

	VSort();
	int 	  	_ac;
	char	  **_av;
	int			_rstep;
	ssize_t		_k;

	std::vector<int>::iterator			_it;
	std::vector<int>::iterator 			_it2;
	std::vector<int> 					_initial_great_values;
	std::vector<std::pair<int, int> > 	_initial_pairs;
	ssize_t calculateMid(ssize_t start, ssize_t end) {return start + (end - start) / 2;}

};

