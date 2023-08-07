/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:23:34 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/07 17:30:45 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &target)
{
	*this = target;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &target)
{
	(void)target;
	return (*this);
}

void ScalarConverter::convert(std::string literal)
{
	(void)literal;
}