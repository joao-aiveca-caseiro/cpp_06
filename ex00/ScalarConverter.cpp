/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:23:34 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/10 02:32:39 by jaiveca-         ###   ########.fr       */
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
	std::string original_type;
	
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		original_type = "float";
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		original_type = "double";
	else if (literal.length() == 1 && literal.find_first_not_of("0123456789") != std::string::npos)
		original_type = "char";
	else if (literal.find_first_not_of("-+0123456789") == std::string::npos 
	&& literal.find_first_of("+-") == literal.find_last_of("+-") 
	&& (literal.find_first_of("+-") == 0 || literal.find_first_of("+-") == std::string::npos))
		original_type = "int";
	else if (literal.find_first_not_of("-+0123456789.") == std::string::npos
	&& literal.find_first_of("+-") == literal.find_last_of("+-") 
	&& (literal.find_first_of("+-") == 0 || literal.find_first_of("+-") == std::string::npos)
	&& literal.find_first_of(".") != std::string::npos)
		original_type = "double";
	else if (literal.find_first_not_of("-+0123456789f.") == std::string::npos
	&& literal.find_first_of("+-") == literal.find_last_of("+-") 
	&& (literal.find_first_of("+-") == 0 || literal.find_first_of("+-") == std::string::npos)
	&& literal.find_first_of("f") == literal.find_last_of("f")
	&& literal.find_first_of("f") == literal.length() - 1
	&& literal.find_first_of(".") != std::string::npos)
		original_type = "float";

	std::cout << original_type << std::endl;
	// std::cout << "char:" << convert_to_char(literal, original_type) << std::endl;
	// std::cout << "int:" << convert_to_int(literal, original_type) << std::endl;
	// std::cout << "float:" << convert_to_float(literal, original_type) << std::endl;
	// std::cout << "double:" << convert_to_double(literal, original_type) << std::endl;



}