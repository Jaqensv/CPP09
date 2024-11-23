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
	void display() const;
	//
	std::list<int> listSort(std::list<int> great_values);
	std::list<std::pair<int, int> > makePairs(std::list<int> great_values);
	std::list<int> makeGreatList(std::list<std::pair<int, int> > pairs);
	std::list<int> makeSmallList(std::list<int> great_values, std::list<std::pair<int, int > > pairs, int third_value);
	std::list<int> insertThird(std::list<int> great_values);
	std::list<int> insertGreat(std::list<int> great_values);
	std::list<int> insertSmall(std::list<int> great_values, std::list<int> small_values);
	std::list<int> dichotomy(std::list<int> great_values, std::list<int>::iterator small_it);
	
	void sortPairValues();
	void splitValues();
	int insert();
	//
	void listVector();

private:

	Sort();
	int 	  	_ac;
	char	  **_av;
	int			_rstep;

	std::list<int>::iterator			_it;
	std::list<int>::iterator 			_it2;
	std::list<int> 						_initial_great_values;
	std::list<std::pair<int, int> > 	_initial_pairs;

	std::vector<int> vector;

};
