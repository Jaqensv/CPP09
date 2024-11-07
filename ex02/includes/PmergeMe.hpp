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

class Sort {

public:

	~Sort();
	Sort(const Sort &src);
	Sort(int argc, char *argv[]);
	Sort &operator=(const Sort &rhs);
	void checkError(int argc, char *argv[]) const;
	void makeList();
	void display() const;
	//
	void listSort();
	void makePairs();
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

	std::list<int> _values;
	std::list<int>::iterator _it;
	std::list<int>::iterator _it2;

	std::list<std::pair<int, int> > pairs;
	//std::list<int>::iterator it;
	std::vector<int> vector;
	int _k;
	int _jack;

};
