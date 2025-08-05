/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:10:00 by jaferna2          #+#    #+#             */
/*   Updated: 2025/08/05 13:08:53 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Span.hpp"
#include <iostream>

int	main(void)
{
	/*------------------------------------------------------------*/
	/*                  BASIC FUNCTIONALITY TEST                  */
	/*------------------------------------------------------------*/
	try
	{
		std::cout << "/*** BASIC TEST WITH 5 NUMBERS ***/" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	/*------------------------------------------------------------*/
	/*                     EXCEED CAPACITY TEST                   */
	/*------------------------------------------------------------*/
	try
	{
		std::cout << "\n/*** TEST: ADDING MORE THAN CAPACITY ***/" << std::endl;
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	/*------------------------------------------------------------*/
	/*                       DUPLICATE TEST                       */
	/*------------------------------------------------------------*/
	try
	{
		std::cout << "\n/*** TEST: DUPLICATE VALUE ***/" << std::endl;
		Span sp(2);
		sp.addNumber(10);
		sp.addNumber(10);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	/*------------------------------------------------------------*/
	/*             NOT ENOUGH ELEMENTS FOR SPAN TEST              */
	/*------------------------------------------------------------*/
	try
	{
		std::cout << "\n/*** TEST: NOT ENOUGH ELEMENTS (SHORTEST) ***/" << std::endl;
		Span sp(2);
		sp.addNumber(100);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n/*** TEST: NOT ENOUGH ELEMENTS (LONGEST) ***/" << std::endl;
		Span sp(2);
		sp.addNumber(200);
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	/*------------------------------------------------------------*/
	/*                      LARGE SPAN TEST                       */
	/*------------------------------------------------------------*/
	try
	{
		std::cout << "\n/*** TEST: LARGE DATASET (10,000 VALUES) ***/" << std::endl;
		Span sp(10000);
		std::vector<int> vec;
		for (size_t i = 0; i < 10000; ++i)
			vec.push_back(i);
		sp.addRange(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
