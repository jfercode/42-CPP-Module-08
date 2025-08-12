/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 < jaferna2@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:52:29 by jaferna2          #+#    #+#             */
/*   Updated: 2025/08/12 13:17:10 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/MutantStack.hpp"
#include <list>
#include <stdexcept>
#include <cstdlib>

template <typename T>
void print_container(const std::string& name, const T& container)
{
    std::cout << name << " elements: [ ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

int main(void)
{
    /*------------------------------------------------------------*/
    /* MUTANTSTACK BASIC FUNCTIONALITY                            */
    /*------------------------------------------------------------*/
    try
    {
        std::cout << "/*** MUTANTSTACK: BASIC PUSH, POP, AND ITERATION ***/" << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "Top element: " << mstack.top() << std::endl;
        std::cout << "Size: " << mstack.size() << std::endl;
        print_container("MutantStack", mstack);

        std::cout << "Popping an element..." << std::endl;
        mstack.pop();
        print_container("Popping MutantStack", mstack);
        std::cout << "New top element: " << mstack.top() << std::endl;
        std::cout << "New size: " << mstack.size() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    /*------------------------------------------------------------*/
    /* STD::LIST BASIC FUNCTIONALITY               */
    /*------------------------------------------------------------*/
    try
    {
        std::cout << "/*** STD::LIST: COMPARISON WITH MUTANTSTACK ***/" << std::endl;
        std::list<int> my_list;
        
        my_list.push_back(5);
        my_list.push_back(17);
        my_list.push_back(3);
        my_list.push_back(5);
        my_list.push_back(737);
        my_list.push_back(0);

        std::cout << "Last element: " << my_list.back() << std::endl;
        std::cout << "Size: " << my_list.size() << std::endl;
        print_container("std::list", my_list);

        std::cout << "Popping an element..." << std::endl;
        my_list.pop_back();
        print_container("Popping std::list", my_list);
        std::cout << "New last element: " << my_list.back() << std::endl;
        std::cout << "New size: " << my_list.size() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

     /*------------------------------------------------------------*/
    /* MUTANTSTACK EMPTY ACCESS TEST               */
    /*------------------------------------------------------------*/
    try
    {
        std::cout << "/*** MUTANTSTACK: ATTEMPTING TO ACCESS EMPTY STACK ***/" << std::endl;
        MutantStack<int> empty_stack;
       	if (empty_stack.empty())
        {
            throw std::runtime_error("Empty stack. Can't access to top element!!!.");
        }
        else
            std::cout << "Top element: " << empty_stack.top() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    return (EXIT_SUCCESS);
}
