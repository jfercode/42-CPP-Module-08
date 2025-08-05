/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:56:43 by jaferna2          #+#    #+#             */
/*   Updated: 2025/08/05 13:06:56 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other)
	: _maxSize(other._maxSize), _numbers(other._numbers) {}


Span::~Span(void) {}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

void Span::addNumber(int N)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span reached the maximum number of elements");
	if (std::find(_numbers.begin(), _numbers.end(), N) != _numbers.end())
		throw std::runtime_error("Value already exists in Span");
	_numbers.push_back(N);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int shortest = INT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}


int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (max - min);
}

void	Span::addRange(std::vector<int>::iterator iter01, std::vector<int>::iterator iter02)
{
	size_t rangeSize = 0;
	{
		std::vector<int>::iterator it = iter01;
		while (it != iter02)
		{
			++rangeSize;
			++it;
		}
	}
	if (_numbers.size() + rangeSize > _maxSize)
		throw std::runtime_error("Span reached the maximum number of elements");
	for (std::vector<int>::iterator it = iter01; it != iter02; ++it)
	{
		if (std::find(_numbers.begin(), _numbers.end(), *it) != _numbers.end())
			throw std::runtime_error("Duplicate value in range cannot be added");		
		_numbers.push_back(*it);
	}
}