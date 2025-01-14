/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:16:52 by mde-lang          #+#    #+#             */
/*   Updated: 2025/01/15 00:13:54 by mde-lang         ###   ########.fr       */
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
    int digit = 0; // operandes
    int op = 0;    // operateurs

    char *expr = argv[1];
    size_t i = 0;

    while (expr[i] != '\0') {
        if (expr[i] == ' ') {
            i++;
            continue;
        }
        if (std::isdigit(expr[i])) {
            digit++;
            while (expr[i] != '\0' && std::isdigit(expr[i]))
                i++;
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '*') {
            op++;
            i++;
        }
        else
            throw std::runtime_error("Error: bad argument");
    }
	if (digit - op != 1) {
        throw std::runtime_error("Error: bad argument");
    }
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
