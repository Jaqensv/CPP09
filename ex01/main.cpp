/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:16:14 by mde-lang          #+#    #+#             */
/*   Updated: 2024/10/22 19:01:20 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char *argv[])
{
	try
	{
		if (argc < 1 || argc > 2)
		{
            std::cerr << "Error: Wrong arguments number" << std::endl;
            return EXIT_FAILURE;
		}
		parser(argv);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
