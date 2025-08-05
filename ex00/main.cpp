/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:38:26 by jaferna2          #+#    #+#             */
/*   Updated: 2025/08/05 11:51:22 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	try
	{
		std::cout << "/*** FIRST TEST WITH STD::VECTOR ***/" << std::endl;
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		std::cout << "/*** SEARCHING FOR VALUE 3 (CORRECT) ***/" << std::endl;
		std::vector<int>::iterator it01 = easyfind(v, 3);
		std::cout << "Found in vector: " << *it01 << std::endl;

		std::cout << "/*** SEARCHING FOR VALUE 4 (INCORRECT) ***/" << std::endl;
		std::vector<int>::iterator it02 = easyfind(v, 4);
		std::cout << "Found in vector: " << *it02 << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Vector error: " << e.what() << '\n';
	}
	try
	{
		std::cout << "/*** FIRST TEST WITH STD::LIST ***/" << std::endl;
		std::list<int> l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(30);
		std::cout << "/*** SEARCHING FOR VALUE 10 (CORRECT) ***/" << std::endl;
		std::list<int>::iterator it01 = easyfind(l, 10);
		std::cout << "Found in list: " << *it01 << std::endl;

		std::cout << "/*** SEARCHING FOR VALUE 40 (INCORRECT) ***/" << std::endl;
		std::list<int>::iterator it02 = easyfind(l, 40);
		std::cout << "Found in list: " << *it02 << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << "List error: " << e.what() << '\n';
	}
	try
	{
		std::cout << "/*** FIRST TEST WITH STD::LIST ***/" << std::endl;
		std::deque<int> d;
		d.push_back(100);
		d.push_back(200);
		d.push_back(300);
		std::cout << "/*** SEARCHING FOR VALUE 100 (CORRECT) ***/" << std::endl;
		std::deque<int>::iterator it01 = easyfind(d, 100);
		std::cout << "Found in deque: " << *it01 << std::endl;

		std::cout << "/*** SEARCHING FOR VALUE 400 (INCORRECT) ***/" << std::endl;
		std::deque<int>::iterator it02 = easyfind(d, 400);
		std::cout << "Found in deque: " << *it02 << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Deque error: " << e.what() << '\n';
	}
	
	return (EXIT_SUCCESS);
}
