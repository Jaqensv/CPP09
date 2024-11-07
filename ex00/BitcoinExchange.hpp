#pragma once

#include <iostream> // sortie
#include <fstream> // manipulation fichier
#include <cstdlib> // EXIT_SUCCESS / FAILURE / atoi
#include <map> // conteneur
#include <stdexcept> // std::runtime_error
#include <ctime> // strptime / mktime
#include <iomanip> // std::fixed / std::setprecision
#include <sstream> // std::stringstream
#define INT_MAX 2147483647

class Bitcoin {

public:

	Bitcoin(const std::string &data, const std::string &input);
	Bitcoin(Bitcoin const &src);
	Bitcoin &operator=(Bitcoin const &rhs);
	void inputSplit(const std::string line);
	void inputChecker();
	void checkDate();
	void checkValue();
	int checkNum(std::string value) const;
	void outputDisplay() const;
	void dataMapping(const std::string line);
	void init(const std::string data, const std::string input);
	void memory(std::string line);
	void openAndVerifyFile(const std::string data, const std::string input);
	~Bitcoin(){};

private:

	Bitcoin(){};
	std::ifstream _data;
	std::ifstream _input;
	std::string *_inputDate;
	std::string *_inputValue;
	std::string *_inputError;
	float *_inputDecimalValue;
	size_t _inputSize;
	size_t _dataSize;
	std::map<std::string, float> _dataMap;

};
