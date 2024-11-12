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

class Sort {

public:

	~Sort();
	Sort(const Sort &src);
	Sort(int argc, char *argv[]);
	Sort &operator=(const Sort &rhs);
	void checkError(int argc, char *argv[]) const;
	void initialData();
	void display() const;
	//
	std::list<int> listSort(std::list<int> great_values);
	std::list<std::pair<int, int> > makePairs(std::list<int> great_values);
	std::list<int> makeGreatList(std::list<std::pair<int, int> > pairs);
	void sortPairValues();
	void splitValues();
	int insert();
	//
	void listVector();

private:

	Sort();
	int 	  	_ac;
	char	  **_av;
	int			_pair_nb;

	std::list<int> _initial_great_values;
	std::list<int>::iterator _it;
	std::list<int>::iterator _it2;

	std::list<std::pair<int, int> > _initial_pairs;

	std::vector<int> vector;
	int _k;
	int _jack;

};
