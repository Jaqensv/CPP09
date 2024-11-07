/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:41:05 by mde-lang          #+#    #+#             */
/*   Updated: 2024/10/15 18:04:55 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


Bitcoin::Bitcoin(const std::string &data, const std::string &input) 
{
	init(data, input);
	inputChecker();
	outputDisplay();
}

void Bitcoin::openAndVerifyFile(const std::string data, const std::string input)
{
	_data.open(data.c_str());
    _input.open(input.c_str());
	if (!_data.is_open() || !_input.is_open()) {
        throw std::runtime_error("Error: unable to open files");}
}

void Bitcoin::init(const std::string data, const std::string input)
{
	std::string	line;

	openAndVerifyFile(data, input);
	memory(line);
	_data.close();
	_input.close();
	openAndVerifyFile(data, input);

	std::getline(_input, line);
	if (line != "date | value")
		throw std::runtime_error("Error: header needs to be 'date | value'");
	while (std::getline(_data, line))
		dataMapping(line);
	while (std::getline(_input, line))
		inputSplit(line);
}

void Bitcoin::memory(std::string line)
{
	_dataSize = 0;
	_inputSize = 0;
	while (std::getline(_input, line))
		_inputSize++;
	while (std::getline(_data, line))
		_dataSize++;
	try 
	{
		_inputDate = new std::string[_inputSize];
		_inputValue = new std::string[_inputSize];
		_inputError = new std::string[_inputSize];
		_inputDecimalValue = new float[_inputSize];
	}
	catch (const std::bad_alloc &e)
	{
		delete[] _inputDate;
		delete[] _inputValue;
		delete[] _inputError;
		delete[] _inputDecimalValue;
		throw std::runtime_error("Error: Memory allocation failed");
	}
}

int Bitcoin::checkNum(std::string value) const
{
	for (size_t i = 0; i < value.size(); ++i)
	{
		if (value[i] == '.')
			return 2;
	}
	return 1;
}

void Bitcoin::dataMapping(const std::string line)
{
	size_t pos = line.find(",");

	for (size_t i = 0; i < _dataSize; ++i)
	{
		if (checkNum(line.substr(pos + 1, line.size())) == 1)
			_dataMap[line.substr(0, pos)] = atoi(line.substr(pos + 1, line.size()).c_str());
		else if (checkNum(line.substr(pos + 1, line.size())) == 2)
			_dataMap[line.substr(0, pos)] = static_cast<float>(atof(line.substr(pos + 1, line.size()).c_str())); // comment stocker la valeur en float ?
	}
}

void Bitcoin::inputSplit(const std::string line)
{
	static int i;
	size_t pos = line.find(" | ");

	_inputDate[i] = line.substr(0, 10);
    if (pos != std::string::npos)
	{
        _inputValue[i] = line.substr(pos + 3);
	}
	else
		_inputError[i] = "Error: wrong format. Must be 'XXXX-XX-XX | value'";
	i++;
}

void Bitcoin::inputChecker()
{
	checkDate();	
	checkValue();
}


void Bitcoin::checkDate()
{
	//ISO 8601
	struct tm tm;

	for (size_t i = 0; i < _inputSize - 1; ++i)
	{
    	if (strptime(_inputDate[i].c_str(), "%Y-%m-%d", &tm) == NULL)
			_inputError[i] = "Error: wrong date format";
		else if (atoi(_inputDate[i].substr(0, 4).c_str()) < 2009 || atoi(_inputDate[i].substr(0, 4).c_str()) > 2022)
			_inputError[i] = "Error: wrong date";
	}

}

void Bitcoin::checkValue()
{
	for (size_t i = 0; i < _inputSize - 1; ++i)
	{
		while (_inputValue[i][0] == '-')
		{
			_inputError[i] = "Error: not a positive number";
			i++;
		}
		for (size_t j = 0; _inputValue[i][j]; ++j)
		{
			if ((_inputValue[i][j] < '0' || _inputValue[i][j] > '9') && _inputValue[i][j] != '.')
			{
				_inputError[i] = "Error: bad input -> " + _inputValue[i];
				i++;
				break;
			}
		}
		if (atol(_inputValue[i].c_str()) > INT_MAX || atol(_inputValue[i].c_str()) > 1000)
			_inputError[i] = "Error: too large a number";
		else
		{
			if (checkNum(_inputValue[i]) == 1)
				_inputDecimalValue[i] = atoi(_inputValue[i].c_str());
			else if (checkNum(_inputValue[i]) == 2)
				_inputDecimalValue[i] = static_cast<float>(atof(_inputValue[i].c_str()));
			
		}
	}
}

void Bitcoin::outputDisplay() const
{
	for (size_t i = 0; i < _inputSize - 1; ++i)
	{
		int precision = 1;
		if (_inputError[i].empty())
		{
			std::map<std::string, float>::const_iterator it = _dataMap.find(_inputDate[i]);
			if (it == _dataMap.end())
			{
				std::cout << "Date not found in dataMap: " << _inputDate[i] << std::endl;
				it = _dataMap.lower_bound(_inputDate[i]);
				if (it != _dataMap.begin())
				{
					--it;
					std::cout << "Using previous available date: " << it->first << std::endl;
				}
				else
				{
					std::cout << "No earlier date available in dataMap." << std::endl;
					continue;
				}
			}
			std::stringstream tmpValue;
			tmpValue << std::fixed << (_inputDecimalValue[i] * it->second);
			std::string result = tmpValue.str();
			size_t pos = result.find(".");
			if (pos != std::string::npos && result[pos + 1] == '0')
				precision = 0;
			std::cout << _inputDate[i] << " => " << _inputValue[i] << " = " << std::fixed << std::setprecision(precision) << _inputDecimalValue[i] * it->second << std::endl;
		}
		else
			std::cout << _inputError[i] << std::endl;
	}
}

Bitcoin::Bitcoin(Bitcoin const &src)
{
	*this = src; // utilise la surcharge plus bas
}

Bitcoin &Bitcoin::operator=(Bitcoin const &rhs)
{
	if (this != &rhs)
	{
		this->_inputDate = rhs._inputDate;
		this->_inputValue = rhs._inputValue;
		this->_inputError = rhs._inputError;
		this->_inputDecimalValue = rhs._inputDecimalValue;
		this->_inputSize = rhs._inputSize;
		this->_dataSize = rhs._dataSize;
		this->_dataMap = rhs._dataMap;	
	}
	return *this;
}