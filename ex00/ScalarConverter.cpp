/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:23:34 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/15 02:51:37 by jaiveca-         ###   ########.fr       */
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
	int			flag = 0;
	
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
	{
		original_type = "float";
		flag = 1;		
	}
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
	{
		original_type = "double";
		flag = 1;		
	}
	else if (literal.length() == 1 && literal.find_first_not_of("0123456789") != std::string::npos)
		original_type = "char";
	else if (literal.find_first_not_of("-+0123456789") == std::string::npos 
	&& check_plus_minus(literal) && check_limits(literal))
		original_type = "int";
	else if (literal.find_first_not_of("-+0123456789e.") == std::string::npos
	&& check_plus_minus(literal) && check_e(literal)
	&& check_decimal(literal))
		original_type = "double";
	else if (literal.find_first_not_of("-+0123456789fe.") == std::string::npos
	&& check_plus_minus(literal) && check_f(literal) 
	&& check_e(literal) && check_decimal(literal))
		original_type = "float";
	else
	{
		std::cout << "The introduced literal represents an unsupported type." << std::endl;
		return ;	
	}

	std::cout << "Type detected: " << original_type << std::endl;
	convert_to_char(literal, original_type, flag);
	convert_to_int(literal, original_type, flag);
	// std::cout << "float:" << convert_to_float(literal, original_type) << std::endl;
	// std::cout << "double:" << convert_to_double(literal, original_type) << std::endl;
}

std::size_t	ScalarConverter::check_e(std::string literal)
{
	// e indicates an exponent, it cannot be the last character 
	// and it cannot come before a decimal point, if it exists
	
	std::size_t e_pos = literal.find_first_of("e");
	std::size_t	decimal_pos = literal.find_first_of(".");

	if (literal.find_first_of("e") == std::string::npos)
		return (1);	
	if (e_pos != literal.find_last_of("e") 
	|| e_pos == literal.length() - 1
	|| e_pos == literal.find_first_of("f") - 1)
		return (0);
	if (decimal_pos != std::string::npos)
		if (decimal_pos > literal.find_first_of("e"))
			return (0);

	return (1);
}

std::size_t	ScalarConverter::check_f(std::string literal)
{
	// floats always end in an f, however they must also have a decimal point before the f
	
	std::size_t f_pos = literal.find_first_of("f");
	std::size_t	decimal_pos = literal.find_first_of(".");
	
	if (f_pos == std::string::npos 
	|| f_pos != literal.find_last_of("f") 
	|| f_pos != literal.length() - 1
	|| decimal_pos == std::string::npos)
		return (0);

	return (1);
}

std::size_t	ScalarConverter::check_plus_minus(std::string literal)
{
	std::size_t pm_pos = literal.find_first_of("+-");
	
	if (pm_pos != literal.find_last_of("+-") 
	|| (pm_pos != 0 && pm_pos != std::string::npos))
		return (0);

	return (1);
}

std::size_t	ScalarConverter::check_decimal(std::string literal)
{
	// a double needs to have at least an exponent or a decimal point,
	// having both at the same time isn't mandatory
	std::size_t decimal_pos = literal.find_first_of(".");
	std::size_t e_pos = literal.find_first_of("e");
	
	if (decimal_pos != literal.find_last_of("."))
		return (0);
	if (decimal_pos == std::string::npos)
		if (e_pos == std::string::npos)
			return (0);

	return (1);
}

std::size_t ScalarConverter::check_limits(std::string literal)
{
	double to_double = atof(literal.c_str());
	if (to_double < std::numeric_limits<int>::min() || to_double > std::numeric_limits<int>::max())
		return (0);
	return (1);
}

void	ScalarConverter::convert_to_char(std::string literal, std::string original_type, int flag)
{
	if (flag)
	{
		std::cout << "char: impossible" << std::endl;
		return ;	
	}
	else if (original_type == "char")
	{
		if (*literal.begin() >= 32 && *literal.begin() <= 126)
			std::cout << "char: '" << *literal.begin() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		return ;
	}
		
	double	to_double = atof(literal.c_str());
	char	output	= static_cast<char>(to_double);
	if (output >= 32 && output <= 126)
		std::cout << "char: '" << output << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::convert_to_int(std::string literal, std::string original_type, int flag)
{
	if (flag)
	{
		std::cout << "int: impossible" << std::endl;
		return ;	
	}
	else if (original_type == "char")
		std::cout << "int: " << static_cast<int>(*literal.begin()) << std::endl;	
	
	double	to_double = atof(literal.c_str());
	std::cout << "int: " << static_cast<int>(to_double) << std::endl;
}