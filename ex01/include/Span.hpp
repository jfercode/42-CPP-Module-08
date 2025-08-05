/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:56:46 by jaferna2          #+#    #+#             */
/*   Updated: 2025/08/05 12:36:02 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <climits>
#include <algorithm>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:

	Span(unsigned int N);
	Span(const Span &other);
	~Span(void);

	Span& operator=(const Span &other);

	void	addNumber(int N);
	int		shortestSpan() const;
	int		longestSpan() const;
	void	addRange(std::vector<int>::iterator iter01, std::vector<int>::iterator iter02);
};

#endif