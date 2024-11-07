/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:16:52 by mde-lang          #+#    #+#             */
/*   Updated: 2024/10/23 11:07:43 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void parser(char *argv[])
{
	int space = 0;
	char **arg = NULL;

	for (size_t i = 0; argv[1][i]; ++i)
	{
		if (argv[1][i] == ' ')
			space++;
	}
	size_t size = strlen(argv[1]) - space;

	checkError(argv);
	try
	{
		arg = new char*[size];
		for (size_t i = 0; i < size; ++i)
		{
			arg[i] = new char[2];
			arg[i][1] = '\0';
		}
		size_t index = 0;
		for (size_t i = 0; argv[1][i]; ++i)
		{
			if (argv[1][i] != ' ')
			{
				arg[index][0] = argv[1][i];
				index++;
			}
		}
		execution(arg, size);
		cleanUp(arg, size);
	}
	catch (const std::bad_alloc &e)
	{
		delete[] arg;
	}
}

void checkError(char *argv[])
{
	int digit = 0;
	int op = 0;
	for (size_t i = 0; i < strlen(argv[1]); ++i)
	{
		if (argv[1][i] != ' ')
		{
			if ((argv[1][i] < '0' || argv[1][i] > '9') && (argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != '/' && argv[1][i] != '*'))
				throw std::runtime_error("Error: bad argument");
			if (argv[1][i] >= '0' && argv[1][i] <= '9')
				digit++;
			else if (argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '/' || argv[1][i] == '*')
				op++;
		}
	}
	if (digit - op != 1)
		throw std::runtime_error("Error: bad argument");
}

void execution(char *argv[], size_t size)
{
	std::stack<float> result;

	for (size_t i = 0; i < size; ++i)
	{
		if (argv[i][0] == '*' || argv[i][0] == '/' || argv[i][0] == '+' || argv[i][0] == '-')
			result.push(calculation(result, argv[i][0]));
		else
			result.push(static_cast<float>(atof(argv[i])));
	}
	std::cout << result.top() << std::endl;
}

float calculation(std::stack<float> &result, char op)
{
	float tmp_result = 0;
	float tmp = result.top();
	result.pop();
	if (op == '+')
		tmp_result = result.top() + tmp;
	else if (op == '-')
		tmp_result = result.top() - tmp;
	else if (op == '*')
		tmp_result = result.top() * tmp;
	else if (op == '/')
		tmp_result = result.top() / tmp;
	result.pop();
	return tmp_result;
}

void cleanUp(char *argv[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
        delete[] argv[i];
    delete[] argv;
}
